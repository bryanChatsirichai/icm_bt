char* switchOrientation(){
  Serial.println("@switchOrientation");
  int result_length;
  char str[30] = "switchOrientation";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char** android_message_parts_array = decode_android_message(android_message, &num_parts);
  char* functionName = android_message_parts_array[0]; 
  char* orientation_str = android_message_parts_array[1];
  orientation = atoi(orientation_str); // Convert string to integer 
  EEPROM.write(4, orientation);
  EEPROM.commit();
  Serial.println(result);
  return result;
}

char* switchRearMotorRotation(){
  Serial.println("@switchRearMotorRotation");
  int result_length;
  char str[30] = "switchRearMotorRotation";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char** android_message_parts_array = decode_android_message(android_message, &num_parts);
  char* functionName = android_message_parts_array[0]; 
  char* rear_rotation_direction_str = android_message_parts_array[1];
  rear_rotation_direction = atoi(rear_rotation_direction_str); // Convert string to integer 
  EEPROM.write(8, rear_rotation_direction);
  EEPROM.commit();
  Serial.println(result);
  return result;
}

char* switchFrontMotorRotation(){
  Serial.println("@switchFrontMotorRotation");
  int result_length;
  char str[30] = "switchFrontMotorRotation";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char** android_message_parts_array = decode_android_message(android_message, &num_parts);
  char* functionName = android_message_parts_array[0]; 
  char* front_rotation_direction_str = android_message_parts_array[1];
  front_rotation_direction = atoi(front_rotation_direction_str); // Convert string to integer 
  EEPROM.write(9, front_rotation_direction);
  EEPROM.commit();
  Serial.println(result);
  return result;
}

//reset camera setting
char* resetCamera(){
  Serial.println("@resetCamera");
  int result_length;
  char str[30] = "resetCamera";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  EEPROM.write(5,0);
  EEPROM.write(6,0);                 
  EEPROM.write(7,0);
  shutter_time = 0;
  motor_time = 0;
  excess_option_set = 0;
  EEPROM.commit();
  Serial.println(result);
  return result;
}

//reset motorcalibration
char* resetMotorCalibration(){
  Serial.println("@resetMotorCalibration");
  int result_length;
  char str[30] = "resetMotorCalibration";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  EEPROM.write(0,0);
  EEPROM.write(1,0);
  EEPROM.write(2,0);
  EEPROM.write(3,0);
  EEPROM.write(4,0);
  EEPROM.write(9, 0);
  EEPROM.write(10,0);
  focus_range = 0;
  zoom_range = 0;
  focus_current = 0;
  zoom_current = 0;
  orientation = 0;
  rear_rotation_direction = 0;
  front_rotation_direction = 0;
  EEPROM.commit();
  Serial.println(result);
  return result;
}
