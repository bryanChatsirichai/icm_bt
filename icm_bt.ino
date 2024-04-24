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
#define MAX_PARTS 25
#define MAX_LENGTH 70

/* Motor Parameters */
#define MOTOR_STEPS 100 //maybe need edit to 100, 100 or 200 is 1 rotation
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
char* zoomMoveMin();
char* zoomMoveMax();
char* zoomSetMin();
char* zoomSetMax();
char* focusMoveMin();
char* focusMoveMax();
char* focusSetMin();
char* focusSetMax();
char* povZoomMin();
char* povZoomMax();
char* povZoomSet();
char* povFocusMin();
char* povFocusMax();
char* povFocusSet();
char* zoomToMin();
char* zoomToMax();
char* zoomToMinBack();
char* zoomToMaxBack();
char* focusToMin();
char* focusToMax();
char* focusToMinBack();
char* focusToMaxBack();
char* povZoomToValueMin();
char* povZoomToValueMax();
char* povZoomToValueSet();
char* povZoomToValueBackSet();
char* povFocusToValueMin();
char* povFocusToValueMax();
char* povFocusToValueSet();
char* povFocusToValueBackSet();
char* zoomMinFocusMin();
char* zoomMaxFocusMax();
char* zoomMinFocusMax();
char* zoomMaxFocusMin();
char* zoomMinFocusMinBack();
char* zoomMaxFocusMaxBack();
char* zoomMinFocusMaxBack();
char* zoomMaxFocusMinBack();

char* povZFToValueZMin();
char* povZFToValueZMax();
char* povZFToValueFMin();
char* povZFToValueFMax();
char* povZFToValueZSet();
char* povZFToValueFSet();
char* povZFToValueStart();
char* povZFToValueBackStart();

char* bokeh();
char* fireworkFocus(); 
char* fireworkZoomFocus();
char* zoomBlurMin();
char* zoomBlurMax();
char* sinWave1();
char* sinWave2(); 

void goDist(int type, int pos_desired, float motor_time, float motor_div,bool goBack, bool lastSequence,bool showScreen);



void open_Shutter() { // Controls the shutter of a Nikon camera
  //Serial.println("Open");
  digitalWrite(FOCUS_CAMERA, HIGH);  
  digitalWrite(SHUTTER_CAMERA, HIGH);
  delay(150);
  digitalWrite(FOCUS_CAMERA, LOW);
  digitalWrite(SHUTTER_CAMERA, LOW);
  delay(150);
  digitalWrite(FOCUS_CAMERA, HIGH);  
  digitalWrite(SHUTTER_CAMERA, HIGH);
  delay(1000);
}
void close_Shutter() { // Controls the shutter of a Nikon camera
  //Serial.println("Close");
  digitalWrite(FOCUS_CAMERA, HIGH);  
  digitalWrite(SHUTTER_CAMERA, HIGH);
  delay(150);
  digitalWrite(FOCUS_CAMERA, LOW);
  digitalWrite(SHUTTER_CAMERA, LOW);
  delay(150);
  digitalWrite(FOCUS_CAMERA, HIGH);  
  digitalWrite(SHUTTER_CAMERA, HIGH);
  delay(1000);
}



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

  //camera shutter and focus for capturing pictures 
  pinMode(FOCUS_CAMERA, OUTPUT);
  pinMode(SHUTTER_CAMERA, OUTPUT);
  digitalWrite(FOCUS_CAMERA, HIGH);  
  digitalWrite(SHUTTER_CAMERA, HIGH);
  delay(150);


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

  //set back last know position after on/off
  setAccel(ZOOM, CALI_ACCEL);
  setAccel(FOCUS, CALI_ACCEL);
  setCurrentPos(ZOOM, zoom_current * MS_STEP);
  setCurrentPos(FOCUS, focus_current * MS_STEP);


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
        //to fix to handle null from function 
          if (strcmp(functionName, "Action1") == 0){
              //Serial.println(android_message);
              //dummy move motor 1 step per click
              zoom_current = 0;
              setAccel(ZOOM, CALI_ACCEL);
              setCurrentPos(ZOOM, zoom_current * MS_STEP);
              zoom_current =  zoom_current + 1;
              moveMotor(ZOOM, zoom_current,0);
              SerialBT.write("Action1");
            }
            else if (strcmp(functionName, "Action2") == 0){
              //Serial.println(android_message);
              //dummy move motor 1 step per click
              zoom_current = 0;
              setCurrentPos(ZOOM, zoom_current * MS_STEP);
              setAccel(ZOOM, CALI_ACCEL);
              moveMotor(ZOOM, 200,0);
              zoom_current = 0;
              setCurrentPos(ZOOM, zoom_current * MS_STEP);
              setAccel(ZOOM, CALI_ACCEL);
              SerialBT.write("Action2");
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
          else if(strcmp(functionName, "resetMotorCalibration") == 0){
            pico_reply = resetMotorCalibration();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomMoveMin") == 0){
            pico_reply = zoomMoveMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomMoveMax") == 0){
            pico_reply = zoomMoveMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomSetMin") == 0){
            pico_reply = zoomSetMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomSetMax") == 0){
            pico_reply = zoomSetMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "focusMoveMin") == 0){
            pico_reply = focusMoveMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "focusMoveMax") == 0){
            pico_reply = focusMoveMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "focusSetMin") == 0){
            pico_reply = focusSetMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "focusSetMax") == 0){
            pico_reply = focusSetMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povZoomMin") == 0){
            pico_reply = povZoomMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }          
          else if(strcmp(functionName, "povZoomMax") == 0){
            pico_reply = povZoomMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povZoomSet") == 0){
            pico_reply = povZoomSet();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povFocusMin") == 0){
            pico_reply = povFocusMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }          
          else if(strcmp(functionName, "povFocusMax") == 0){
            pico_reply = povFocusMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povFocusSet") == 0){
            pico_reply = povFocusSet();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomToMin") == 0){
            pico_reply = zoomToMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomToMax") == 0){
            pico_reply = zoomToMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomToMinBack") == 0){
            pico_reply = zoomToMinBack();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomToMaxBack") == 0){
            pico_reply = zoomToMaxBack();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "focusToMin") == 0){
            pico_reply = focusToMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "focusToMax") == 0){
            pico_reply = focusToMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "focusToMinBack") == 0){
            pico_reply = focusToMinBack();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "focusToMaxBack") == 0){
            pico_reply = focusToMaxBack();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povZoomToValueMin") == 0){
            pico_reply = povZoomToValueMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }          
          else if(strcmp(functionName, "povZoomToValueMax") == 0){
            pico_reply = povZoomToValueMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povZoomToValueSet") == 0){
            pico_reply = povZoomToValueSet();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povZoomToValueBackSet") == 0){
            pico_reply = povZoomToValueBackSet();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povFocusToValueMin") == 0){
            pico_reply = povFocusToValueMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }          
          else if(strcmp(functionName, "povFocusToValueMax") == 0){
            pico_reply = povFocusToValueMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povFocusToValueSet") == 0){
            pico_reply = povFocusToValueSet();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povFocusToValueBackSet") == 0){
            pico_reply = povFocusToValueBackSet();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomMinFocusMin") == 0){
            pico_reply = zoomMinFocusMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }          
          else if(strcmp(functionName, "zoomMaxFocusMax") == 0){
            pico_reply = zoomMaxFocusMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomMinFocusMax") == 0){
            pico_reply = zoomMinFocusMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomMaxFocusMin") == 0){
            pico_reply = zoomMaxFocusMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomMinFocusMinBack") == 0){
            pico_reply = zoomMinFocusMinBack();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }          
          else if(strcmp(functionName, "zoomMaxFocusMaxBack") == 0){
            pico_reply = zoomMaxFocusMaxBack();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomMinFocusMaxBack") == 0){
            pico_reply = zoomMinFocusMaxBack();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomMaxFocusMinBack") == 0){
            pico_reply = zoomMaxFocusMinBack();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }

          else if(strcmp(functionName, "povZFToValueZMin") == 0){
            pico_reply = povZFToValueZMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povZFToValueZMax") == 0){
            pico_reply = povZFToValueZMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povZFToValueZSet") == 0){
            pico_reply = povZFToValueZSet();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povZFToValueFMin") == 0){
            pico_reply = povZFToValueFMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povZFToValueFMax") == 0){
            pico_reply = povZFToValueFMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povZFToValueFSet") == 0){
            pico_reply = povZFToValueFSet();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povZFToValueStart") == 0){
            pico_reply = povZFToValueStart();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "povZFToValueBackStart") == 0){
            pico_reply = povZFToValueBackStart();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          //PRESET actions
          else if(strcmp(functionName, "bokeh") == 0){
            pico_reply = bokeh();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "fireworkFocus") == 0){
            pico_reply = fireworkFocus();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "fireworkZoomFocus") == 0){
            pico_reply = fireworkZoomFocus();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomBlurMin") == 0){
            pico_reply = zoomBlurMin();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "zoomBlurMax") == 0){
            pico_reply = zoomBlurMax();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "sinWave1") == 0){
            pico_reply = sinWave1();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }
          else if(strcmp(functionName, "sinWave2") == 0){
            pico_reply = sinWave2();
            SerialBT.write(pico_reply);
            free(pico_reply);
          }


          //clean up the array space
          //free(android_message_parts_array);
          for (int i = 0; i < num_parts; i++) {
            if(android_message_parts_array[i] != NULL){
              //Serial.println("freeing!");
              //Serial.println(android_message_parts_array[i]);
              free(android_message_parts_array[i]);
            }
            //free(android_message_parts_array[i]);
          }
      }
      // Clearing the array,Remove all characters from the android_message
      // for (int i = 0; i < MAX_LENGTH; i++) {
      //     android_message[i] = '\0';
      // }
      // Serial.println("Clear android message!");
      // strcpy(android_message, "");
      // Serial.println(android_message);
      //android_message[MAX_LENGTH]; // adjust the size according to your needs
      memset(android_message, 0, MAX_LENGTH);
      //Serial.println(sizeof(android_message));


      //Serial.println("-------");
      digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on
      delay(200);
}


