char* setShutterTime() {
  Serial.println("@setShutterTime");
  int result_length;
  char str[30] = "setShutterTime";
  
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
  char* shutter_time_str = android_message_parts_array[1];
  shutter_time = atoi(shutter_time_str); // Convert string to integer 
  EEPROM.write(5, shutter_time);
  EEPROM.commit();
  strcat(result, shutter_time_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* setMotorTime() {
  Serial.println("@setMotorTime");
  int result_length;
  char str[30] = "setMotorTime";
  
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
  char* motor_time_str = android_message_parts_array[1];
  motor_time = atoi(motor_time_str); // Convert string to integer 
  EEPROM.write(6, motor_time);
  EEPROM.commit();
  strcat(result, motor_time_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* setExcessTime() {
  Serial.println("@setExcessTime");
  int result_length;
  char str[20] = "setExcessTime";
  
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
  char* excess_option_set_str = android_message_parts_array[1];
  excess_option_set = atoi(excess_option_set_str); // Convert string to integer 
  EEPROM.write(7, excess_option_set);
  EEPROM.commit();
  strcat(result, excess_option_set_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}