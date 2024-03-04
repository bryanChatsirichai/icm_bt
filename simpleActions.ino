char* zoomToMin() {
  Serial.println("@zoomToMin");
  int result_length;
  char str[30] = "zoomToMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  //carry out action
  goDist(ZOOM, 0, motor_time,1,true,true,true);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* zoomToMax() {
  Serial.println("@zoomToMax");
  int result_length;
  char str[30] = "zoomToMax";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  //carry out action
  goDist(ZOOM, zoom_range, motor_time,1,true,true,true);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* zoomToMinBack() {
  Serial.println("@zoomToMinBack");
  int result_length;
  char str[30] = "zoomToMinBack";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  //carry out action
  //going back is now part of motor_time
  int previous_pos = zoom_current;
  goDist(ZOOM, 0, motor_time,2,false,false,true);
  goDist(ZOOM, previous_pos, motor_time,2,false,true,false);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* zoomToMaxBack() {
  Serial.println("@zoomToMaxBack");
  int result_length;
  char str[30] = "zoomToMaxBack";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  //carry out action
  //going back is now part of motor_time
  int previous_pos = zoom_current;
  goDist(ZOOM, zoom_range, motor_time,2,false,false,true);
  goDist(ZOOM, previous_pos, motor_time,2,false,true,false);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

///////////////
char* focusToMin() {
  Serial.println("@focusToMin");
  int result_length;
  char str[30] = "focusToMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  //carry out action
  goDist(FOCUS, 0,motor_time,1,true,true,true);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* focusToMax() {
  Serial.println("@focusToMax");
  int result_length;
  char str[30] = "focusToMax";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  //carry out action
  goDist(FOCUS, focus_range,motor_time,1,true,true,true);
  
  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* focusToMinBack() {
  Serial.println("@focusToMinBack");
  int result_length;
  char str[30] = "focusToMinBack";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  //carry out action
  //going back is now part of motor_time
  int previous_pos = focus_current;
  goDist(FOCUS, 0, motor_time,2,false,false,true);
  goDist(FOCUS, previous_pos, motor_time,2,false,true,false);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* focusToMaxBack() {
  Serial.println("@focusToMaxBack");
  int result_length;
  char str[30] = "focusToMaxBack";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  //carry out action
  //going back is now part of motor_time
  int previous_pos = focus_current;
  goDist(FOCUS, focus_range, motor_time,2,false,false,true);
  goDist(FOCUS, previous_pos, motor_time,2,false,true,false);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}


char* povZoomToValueMin() {
  Serial.println("@povZoomToValueMin");
  int result_length;
  char str[30] = "povZoomToValueMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string
  // motor decrease 1 step per click
  setAccel(ZOOM, CALI_ACCEL);
  setCurrentPos(ZOOM, zoom_current * MS_STEP);
  zoom_current =  zoom_current - 1;
  moveMotor(ZOOM, zoom_current,0);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);


  //zoom current
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char zoom_current_str[5];
  sprintf(zoom_current_str, "%d", zoom_current);
  strcat(result, zoom_current_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //zoom range
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char zoom_range_str[5];
  sprintf(zoom_range_str, "%d", zoom_range);
  strcat(result, zoom_range_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  Serial.println(result);
  // EEPROM.write(3, zoom_current);
  // EEPROM.commit();
  return result;
}

char* povZoomToValueMax() {
  Serial.println("@povZoomToValueMax");
  int result_length;
  char str[30] = "povZoomToValueMax";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string
  // motor increase 1 step per click
  setAccel(ZOOM, CALI_ACCEL);
  setCurrentPos(ZOOM, zoom_current * MS_STEP);
  zoom_current =  zoom_current + 1;
  moveMotor(ZOOM, zoom_current,0);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);


  //zoom current
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char zoom_current_str[5];
  sprintf(zoom_current_str, "%d", zoom_current);
  strcat(result, zoom_current_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //zoom range
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char zoom_range_str[5];
  sprintf(zoom_range_str, "%d", zoom_range);
  strcat(result, zoom_range_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  Serial.println(result);
  // EEPROM.write(3, zoom_current);
  // EEPROM.commit();
  return result;
}


char* povZoomToValueSet() {
  Serial.println("@povZoomToValueSet");
  int result_length;
  char str[40] = "povZoomToValueSet";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);


  char** android_message_parts_array = decode_android_message(android_message, &num_parts);
  char* functionName = android_message_parts_array[0]; 
  char* zoom_current_str = android_message_parts_array[1];//get back the initial zoom_current
  char* zoom_target_str = android_message_parts_array[2];
  zoom_current = atoi(zoom_current_str); // Convert string to integer 
  int pos_desired = atoi(zoom_target_str); // Convert string to integer

  //go back to initial zoom
  setAccel(ZOOM, CALI_ACCEL);
  moveMotor(ZOOM, zoom_current,0);

  //carry out main action
  goDist(ZOOM, pos_desired, motor_time,1,true,true,true);


  Serial.println(result);
  return result;
}


char* povZoomToValueBackSet() {
  Serial.println("@povZoomToValueBackSet");
  int result_length;
  char str[40] = "povZoomToValueBackSet";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);


  char** android_message_parts_array = decode_android_message(android_message, &num_parts);
  char* functionName = android_message_parts_array[0]; 
  char* zoom_current_str = android_message_parts_array[1];//get back the initial zoom_current
  char* zoom_target_str = android_message_parts_array[2];
  zoom_current = atoi(zoom_current_str); // Convert string to integer
  int previous_pos = zoom_current; 
  int pos_desired = atoi(zoom_target_str); // Convert string to integer

  //go back to initial zoom
  setAccel(ZOOM, CALI_ACCEL);
  moveMotor(ZOOM, zoom_current,0);

  //carry out main action
  //going back is now part of motor_time
  goDist(ZOOM, pos_desired, motor_time,2,false,false,true);
  goDist(ZOOM, previous_pos, motor_time,2,false,true,false);


  Serial.println(result);
  return result;
}