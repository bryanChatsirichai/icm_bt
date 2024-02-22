char* syncDevices() {
  Serial.println("@syncDevices");
  int result_length;
  char str[30] = "syncDevices";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  // Copy the original string to the result string
  strcpy(result, str);
  
  /**== DO For all global data to sync*/
  // Finding the length of the string,append the character and null terminator
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  // Convert the integer to a string and append it
  char shutter_time_str[5];
  sprintf(shutter_time_str, "%d", shutter_time);
  strcat(result, shutter_time_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char max_shutter_time_str[5];
  sprintf(max_shutter_time_str, "%d", max_shutter_time);
  strcat(result, max_shutter_time_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char motor_time_str[5];
  sprintf(motor_time_str, "%d", motor_time);
  strcat(result, motor_time_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char max_motor_time_str[5];
  sprintf(max_motor_time_str, "%d", max_motor_time);
  strcat(result, max_motor_time_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';


  // Return the result string, make sure pico and android knows the order
  // syncDevices_shutterTimeValue_maxShutterTime_....
  // if no return value just return the function name eg.syncDevices
  Serial.println(result);
  
  return result;
}