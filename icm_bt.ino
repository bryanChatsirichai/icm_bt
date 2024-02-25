#include <SerialBT.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <AccelStepper.h>
#include <MultiStepper.h>
#include <math.h>
#include <EEPROM.h>
#include "SoftwareSerial.h"

// Maximum number of parts expected after splitting message from android
#define MAX_PARTS 20
#define MAX_LENGTH 50

/* Motor Parameters */
#define MOTOR_STEPS 200 //
#define RPM 1000
#define FOCUS 0
#define ZOOM 1
#define MS_STEP 8 // default 1/8 microstep, 200*8 = 1600 microstepping
#define CALI_ACCEL 400

/* Motor Pins */
#define rear_DIR    6
#define rear_STEP   7
#define front_DIR   0
#define front_STEP  1

//control camera shutter  - may need change FOCUS_CAMERA GPIO PIN
#define FOCUS_CAMERA 21 //26
#define SHUTTER_CAMERA 22 //27

/*RX and TX for JQ8900 communication*/
//It's important to note that those RX and TX labels are with respect to the device itself. 
//So the RX from one device should go to the TX of the other, and vice-versa
#define HBYTE(X) ((X & 0xFF00) >> 8) 
#define LBYTE(X) (X & 0xFF) 
#define RX 5
#define TX 4

// Global Variables 
int first_time = 0; //first time the pico on
int zoom_range = 0; 
int focus_range = 0;    
int zoom_current = 0;     
int focus_current = 0;   
int orientation = 0;    
int shutter_time = 0;
int motor_time = 0;   
int excess_option_set = 0; //default
int camera_shutter_open = 0; //default 0 is not open
int rear_rotation_direction = 0; //default
int front_rotation_direction = 0; //default
int max_shutter_time = 60;
int max_motor_time = 60;

/* Motor Objects*/
AccelStepper front_motor(AccelStepper::DRIVER, front_STEP, front_DIR);
AccelStepper rear_motor(AccelStepper::DRIVER, rear_STEP, rear_DIR);

/*Control multiple steppers motor*/
MultiStepper steppers;

//Comminication to JQ8900
SoftwareSerial SoftwareSerial(RX,TX); // RX, TX

// Function Declaration
char** decode_android_message(const char* input, int* num_parts);
bool isNullOrEmpty(const char *str);
char* syncDevices();
char* setShutterTime();
char* setMotorTime();
char* setExcessTime();
char* switchOrientation();

// Define a character array to hold the concatenated string
char android_message[MAX_LENGTH]; // adjust the size according to your needs
char* pico_reply;
int num_parts;

void setup() {
  //LED
  pinMode(LED_BUILTIN, OUTPUT);

  //bluetooth setup
  SerialBT.begin();
  Serial.begin(9600);
  EEPROM.begin(512);

  //for jp8900-16pin
  SoftwareSerial.begin(9600);


  // ***** Motor *****
  rear_motor.setMaxSpeed(RPM);
  front_motor.setMaxSpeed(RPM);
  steppers.addStepper(rear_motor);
  steppers.addStepper(front_motor);


  
  // ***** EEPROM Read *****
  // reads the stored memory
  focus_range = EEPROM.read(0);
  zoom_range = EEPROM.read(1);
  focus_current = EEPROM.read(2);
  zoom_current = EEPROM.read(3);
  orientation = EEPROM.read(4);
  shutter_time = EEPROM.read(5);
  motor_time = EEPROM.read(6);
  excess_option_set = EEPROM.read(7);
  rear_rotation_direction = EEPROM.read(8);
  front_rotation_direction = EEPROM.read(9);
  first_time = EEPROM.read(10);


  // ***** Default Values *****
  // if empty (==255), setting default values to 0
  // for current positions -> Move the motor to stored current 
  // to be implemented when finalise...
  if(first_time == 255){
    focus_range = 0;
    zoom_range = 0;
    focus_current = 0;
    zoom_current = 0;
    orientation = 0;
    shutter_time = 0;
    motor_time = 0;
    excess_option_set = 0; 
    rear_rotation_direction = 0;
    front_rotation_direction = 0;
    first_time = 0;
                        
    EEPROM.write(0, focus_range);
    EEPROM.write(1, zoom_range);
    EEPROM.write(2, focus_current);
    EEPROM.write(3, zoom_current);
    EEPROM.write(4, orientation);
    EEPROM.write(5, shutter_time);
    EEPROM.write(6, motor_time);
    EEPROM.write(7, excess_option_set);
    EEPROM.write(8, rear_rotation_direction);
    EEPROM.write(9, front_rotation_direction);
    EEPROM.write(10, first_time);
    EEPROM.commit();
  }

}

void loop() {
    while (SerialBT.available()) {
      char c = SerialBT.read();
      // Concatenate characters to android message
      // Serial.println(c);
      strcat(android_message, &c);
    } 
      if (isNullOrEmpty(android_message)) {
        // nothing to do

      }
      else {
        Serial.println(android_message);
        char** android_message_parts_array = decode_android_message(android_message, &num_parts);
        char* functionName = android_message_parts_array[0]; 
          if (strcmp(functionName, "Action1") == 0){
              Serial.println(android_message);
              //dummy move motor 1 step per click
              zoom_current = 0;
              setAccel(ZOOM, CALI_ACCEL);
              setCurrentPos(ZOOM, zoom_current * MS_STEP);
              zoom_current =  zoom_current + 1;
              moveMotor(ZOOM, zoom_current,0);
              SerialBT.write("Action1");
            }
          else if(strcmp(functionName, "syncDevices") == 0){
            pico_reply = syncDevices();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "setShutterTime") == 0){
            pico_reply = setShutterTime();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "setMotorTime") == 0){
            pico_reply = setMotorTime();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "setExcessTime") == 0){
            pico_reply = setExcessTime();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "switchOrientation") == 0){
            pico_reply = switchOrientation();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "switchRearMotorRotation") == 0){
            pico_reply = switchRearMotorRotation();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "switchFrontMotorRotation") == 0){
            pico_reply = switchFrontMotorRotation();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "resetCamera") == 0){
            pico_reply = resetCamera();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          //clean up the array space
          //free(android_message_parts_array);
          
          for (int i = 0; i < num_parts; i++) {
            free(android_message_parts_array[i]);
          }
      }
      // Clearing the array,Remove all characters from the android_message
      for (int i = 0; i < MAX_LENGTH; i++) {
          android_message[i] = '\0';
      }
      Serial.println("-------");
      digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on
      delay(200);
}

