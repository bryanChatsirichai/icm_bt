char* syncDevices() {
  //Serial.println("@syncDevices");
  int result_length;
  char str[50] = "syncDevices";
  
  // Allocate memory for the result string,40 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 50);
  if (result == NULL) {
        //Serial.println("Memory allocation failed");
        return NULL;
  }
  // Finding the length of the string

  // Copy the original string to the result string
  strcpy(result, str);
  
  /**== DO For all global data to sync*/
  // Finding the length of the string,append the character and null terminator
  // Convert the integer to a string and append it

  //1
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char focus_range_str[5];
  sprintf(focus_range_str, "%d", focus_range);
  strcat(result, focus_range_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //2
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char zoom_range_str[5];
  sprintf(zoom_range_str, "%d", zoom_range);
  strcat(result, zoom_range_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //3
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char focus_current_str[5];
  sprintf(focus_current_str, "%d", focus_current);
  strcat(result, focus_current_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //4
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char zoom_current_str[5];
  sprintf(zoom_current_str, "%d", zoom_current);
  strcat(result, zoom_current_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //5
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char orientation_str[5];
  sprintf(orientation_str, "%d", orientation);
  strcat(result, orientation_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //6
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  // Convert the integer to a string and append it
  char shutter_time_str[5];
  sprintf(shutter_time_str, "%d", shutter_time);
  strcat(result, shutter_time_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //7
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char max_shutter_time_str[5];
  sprintf(max_shutter_time_str, "%d", max_shutter_time);
  strcat(result, max_shutter_time_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //8
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char motor_time_str[5];
  sprintf(motor_time_str, "%d", motor_time);
  strcat(result, motor_time_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //9
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char max_motor_time_str[5];
  sprintf(max_motor_time_str, "%d", max_motor_time);
  strcat(result, max_motor_time_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //10
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char excess_option_set_str[5];
  sprintf(excess_option_set_str, "%d", excess_option_set);
  strcat(result, excess_option_set_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //11
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char rear_rotation_direction_str[5];
  sprintf(rear_rotation_direction_str, "%d", rear_rotation_direction);
  strcat(result, rear_rotation_direction_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //12
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char front_rotation_direction_str[5];
  sprintf(front_rotation_direction_str, "%d", front_rotation_direction);
  strcat(result, front_rotation_direction_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //13
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char MOTOR_STEPS_str[5];
  sprintf(MOTOR_STEPS_str, "%d", MOTOR_STEPS);
  strcat(result, MOTOR_STEPS_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  // Return the result string, make sure pico and android knows the order
  //to do change order maybe follow EEPROM ordering to fix
  // for now syncDevices_shutterTimeValue_maxShutterTime_....
  // if no return value just return the function name eg.syncDevices
  //Serial.println(result);
  
  return result;
}