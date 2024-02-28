/***ZOOM***/
//andoird will keep track for this calibration
char* zoomMoveMin() {
  Serial.println("@zoomMoveMin");
  int result_length;
  char str[30] = "zoomMoveMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string
  // motor 1 step per click
  //zoom_current should be irrelevant as the set comman will sync both android and pico
  zoom_current = 0; 
  setAccel(ZOOM, CALI_ACCEL);
  setCurrentPos(ZOOM, zoom_current * MS_STEP);
  zoom_current =  zoom_current - 1;
  moveMotor(ZOOM, zoom_current,0);
  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

//andoird will keep track for this calibration
char* zoomMoveMax() {
  Serial.println("@zoomMoveMax");
  int result_length;
  char str[30] = "zoomMoveMax";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string
  // motor 1 step per click
  //zoom_current should be irrelevant as the set comman will sync both android and pico
  zoom_current = 0; 
  setAccel(ZOOM, CALI_ACCEL);
  setCurrentPos(ZOOM, zoom_current * MS_STEP);
  zoom_current =  zoom_current + 1;
  moveMotor(ZOOM, zoom_current,0);
  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* zoomSetMin() {
  Serial.println("@zoomSetMin");
  int result_length;
  char str[30] = "zoomSetMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string
  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}


//andoird send the zoom_current and zoom_range
char* zoomSetMax() {
  Serial.println("@zoomSetMax");
  int result_length;
  char str[30] = "zoomSetMax";
  
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
  char* zoom_current_str = android_message_parts_array[1];
  char* zoom_range_str = android_message_parts_array[2];
  zoom_current = atoi(zoom_current_str); // Convert string to integer 
  zoom_range = atoi(zoom_range_str); // Convert string to integer

  //at the maximum
  setAccel(ZOOM, CALI_ACCEL);
  setCurrentPos(ZOOM, zoom_range * MS_STEP);
  //go back to the middle between min and max
  moveMotor(ZOOM, zoom_current,0);


  EEPROM.write(1, zoom_range);  
  EEPROM.write(3, zoom_current);
  EEPROM.commit();
  Serial.println(result);
  return result;
}
/***FOCUS***/
//andoird will keep track for this calibration
char* focusMoveMin() {
  Serial.println("@focusMoveMin");
  int result_length;
  char str[30] = "focusMoveMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string
  // motor 1 step per click
  //focus_current should be irrelevant as the set comman will sync both android and pico
  focus_current = 0; 
  setAccel(FOCUS, CALI_ACCEL);
  setCurrentPos(FOCUS, focus_current * MS_STEP);
  focus_current =  focus_current - 1;
  moveMotor(FOCUS, focus_current,0);
  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

//andoird will keep track for this calibration
char* focusMoveMax() {
  Serial.println("@focusMoveMax");
  int result_length;
  char str[30] = "focusMoveMax";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string
  // motor 1 step per click
  //focus_current should be irrelevant as the set comman will sync both android and pico
  focus_current = 0; 
  setAccel(FOCUS, CALI_ACCEL);
  setCurrentPos(FOCUS, focus_current * MS_STEP);
  focus_current =  focus_current + 1;
  moveMotor(FOCUS, focus_current,0);
  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* focusSetMin() {
  Serial.println("@focusSetMin");
  int result_length;
  char str[30] = "focusSetMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string
  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}


//andoird send the focus_current and focus_range
char* focusSetMax() {
  Serial.println("@focusSetMax");
  int result_length;
  char str[30] = "focusSetMax";
  
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
  char* focus_current_str = android_message_parts_array[1];
  char* focus_range_str = android_message_parts_array[2];
  focus_current = atoi(focus_current_str); // Convert string to integer 
  focus_range = atoi(focus_range_str); // Convert string to integer

  //at the maximum
  setAccel(FOCUS, CALI_ACCEL);
  setCurrentPos(FOCUS, focus_range * MS_STEP);
  //go back to the middle between min and max
  moveMotor(FOCUS, focus_current,0);


  EEPROM.write(0, focus_range);
  EEPROM.write(2, focus_current);
  EEPROM.commit();
  Serial.println(result);
  return result;
  return result;
}


char* povZoomMin() {
  Serial.println("@povZoomMin");
  int result_length;
  char str[30] = "povZoomMin";
  
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
  EEPROM.write(3, zoom_current);
  EEPROM.commit();
  return result;
}

char* povZoomMax() {
  Serial.println("@povZoomMax");
  int result_length;
  char str[30] = "povZoomMax";
  
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
  EEPROM.write(3, zoom_current);
  EEPROM.commit();
  return result;
}


char* povZoomSet() {
  Serial.println("@povZoomSet");
  int result_length;
  char str[30] = "povZoomSet";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);

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
  return result;
}



char* povFocusMin() {
  Serial.println("@povFocusMin");
  int result_length;
  char str[30] = "povFocusMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string
  // motor decrease 1 step per click
  setAccel(FOCUS, CALI_ACCEL);
  setCurrentPos(FOCUS, focus_current * MS_STEP);
  focus_current =  focus_current - 1;
  moveMotor(FOCUS, focus_current,0);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);


  //focus current
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char focus_current_str[5];
  sprintf(focus_current_str, "%d", focus_current);
  strcat(result, focus_current_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //focus range
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char focus_range_str[5];
  sprintf(focus_range_str, "%d", focus_range);
  strcat(result, focus_range_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  Serial.println(result);
  EEPROM.write(2, focus_current);
  EEPROM.commit();
  return result;
}

char* povFocusMax() {
  Serial.println("@povFocusMax");
  int result_length;
  char str[30] = "povFocusMax";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string
  // motor increase 1 step per click
  setAccel(FOCUS, CALI_ACCEL);
  setCurrentPos(FOCUS, focus_current * MS_STEP);
  focus_current =  focus_current + 1;
  moveMotor(FOCUS, focus_current,0);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);


  //focus current
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char focus_current_str[5];
  sprintf(focus_current_str, "%d", focus_current);
  strcat(result, focus_current_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //focus range
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char focus_range_str[5];
  sprintf(focus_range_str, "%d", focus_range);
  strcat(result, focus_range_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  Serial.println(result);
  EEPROM.write(2, focus_current);
  EEPROM.commit();
  return result;
}


char* povFocusSet() {
  Serial.println("@povFocusSet");
  int result_length;
  char str[30] = "povFocusSet";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);


  //focus current
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char focus_current_str[5];
  sprintf(focus_current_str, "%d", focus_current);
  strcat(result, focus_current_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  //focus range
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  char focus_range_str[5];
  sprintf(focus_range_str, "%d", focus_range);
  strcat(result, focus_range_str);
  result_length = strlen(result);
  result[result_length + 1] = '\0';

  Serial.println(result);
  return result;
}



