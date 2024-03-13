char* zoomToMin() {
  Serial.println("@zoomToMin");
  int result_length;
  char str[30] = "zoomToMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }

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
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }

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

char* povFocusToValueMin() {
  Serial.println("@povFocusToValueMin");
  int result_length;
  char str[30] = "povFocusToValueMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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
  // EEPROM.write(2, focus_current);
  // EEPROM.commit();
  return result;
}

char* povFocusToValueMax() {
  Serial.println("@povFocusToValueMax");
  int result_length;
  char str[30] = "povFocusToValueMax";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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
  // EEPROM.write(2, focus_current);
  // EEPROM.commit();
  return result;
}


char* povFocusToValueSet() {
  Serial.println("@povFocusToValueSet");
  int result_length;
  char str[40] = "povFocusToValueSet";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);


  char** android_message_parts_array = decode_android_message(android_message, &num_parts);
  char* functionName = android_message_parts_array[0]; 
  char* focus_current_str = android_message_parts_array[1];//get back the initial focus_current
  char* focus_target_str = android_message_parts_array[2];
  focus_current = atoi(focus_current_str); // Convert string to integer 
  int pos_desired = atoi(focus_target_str); // Convert string to integer

  //go back to initial focus
  setAccel(FOCUS, CALI_ACCEL);
  moveMotor(FOCUS, focus_current,0);

  //carry out main action
  goDist(FOCUS, pos_desired, motor_time,1,true,true,true);


  Serial.println(result);
  return result;
}


char* povFocusToValueBackSet() {
  Serial.println("@povFocusToValueBackSet");
  int result_length;
  char str[40] = "povFocusToValueBackSet";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);


  char** android_message_parts_array = decode_android_message(android_message, &num_parts);
  char* functionName = android_message_parts_array[0]; 
  char* focus_current_str = android_message_parts_array[1];//get back the initial focus_current
  char* focus_target_str = android_message_parts_array[2];
  focus_current = atoi(focus_current_str); // Convert string to integer
  int previous_pos = focus_current; 
  int pos_desired = atoi(focus_target_str); // Convert string to integer

  //go back to initial focus
  setAccel(FOCUS, CALI_ACCEL);
  moveMotor(FOCUS, focus_current,0);

  //carry out main action
  //going back is now part of motor_time
  goDist(FOCUS, pos_desired, motor_time,2,false,false,true);
  goDist(FOCUS, previous_pos, motor_time,2,false,true,false);


  Serial.println(result);
  return result;
}
//Both motor at same time
char* zoomMinFocusMin() {
  Serial.println("@zoomMinFocusMin");
  int result_length;
  char str[30] = "zoomMinFocusMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
  // Finding the length of the string

  //carry out action
  goMultiDist(0, 0,motor_time,1,true,true,true);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* zoomMaxFocusMax() {
  Serial.println("@zoomMaxFocusMax");
  int result_length;
  char str[30] = "zoomMaxFocusMax";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
  // Finding the length of the string

  //carry out action
  goMultiDist(zoom_range, focus_range,motor_time,1,true,true,true);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* zoomMinFocusMax() {
  Serial.println("@zoomMinFocusMax");
  int result_length;
  char str[30] = "zoomMinFocusMax";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
  // Finding the length of the string

  //carry out action
  goMultiDist(0, focus_range,motor_time,1,true,true,true);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* zoomMaxFocusMin() {
  Serial.println("@zoomMaxFocusMin");
  int result_length;
  char str[30] = "zoomMaxFocusMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
  // Finding the length of the string

  //carry out action
  goMultiDist(zoom_range,0,motor_time,1,true,true,true);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* zoomMinFocusMinBack() {
  Serial.println("@zoomMinFocusMinBack");
  int result_length;
  char str[30] = "zoomMinFocusMinBack";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
  // Finding the length of the string

  //carry out action
  int previous_zoom_pos = zoom_current;
  int previous_focus_pos = focus_current;
  //going back is now part of motor_time
  goMultiDist(0, 0,motor_time,2, false, false,true);
  goMultiDist(previous_zoom_pos, previous_focus_pos, motor_time,2, false, true,false);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* zoomMaxFocusMaxBack() {
  Serial.println("@zoomMaxFocusMaxBack");
  int result_length;
  char str[30] = "zoomMaxFocusMaxBack";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
  // Finding the length of the string

  //carry out action
  int previous_zoom_pos = zoom_current;
  int previous_focus_pos = focus_current;
  //going back is now part of motor_time
  goMultiDist(zoom_range, focus_range, motor_time,2, false, false,true);
  goMultiDist(previous_zoom_pos, previous_focus_pos, motor_time,2, false, true,false);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}


char* zoomMinFocusMaxBack() {
  Serial.println("@zoomMinFocusMaxBack");
  int result_length;
  char str[30] = "zoomMinFocusMaxBack";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
  // Finding the length of the string

  //carry out action
  int previous_zoom_pos = zoom_current;
  int previous_focus_pos = focus_current;
  //going back is now part of motor_time
  goMultiDist(0, focus_range, motor_time,2, false, false,true);
  goMultiDist(previous_zoom_pos, previous_focus_pos, motor_time,2, false, true,false);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

char* zoomMaxFocusMinBack() {
  Serial.println("@zoomMaxFocusMinBack");
  int result_length;
  char str[30] = "zoomMaxFocusMinBack";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
  // Finding the length of the string

  //carry out action
  int previous_zoom_pos = zoom_current;
  int previous_focus_pos = focus_current;
  //going back is now part of motor_time
  goMultiDist(zoom_range, 0, motor_time,2, false, false,true);
  goMultiDist(previous_zoom_pos, previous_focus_pos, motor_time,2, false, true,false);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

//zoom focus to value
char* povZFToValueZMin() {
  Serial.println("@povZFToValueZMin");
  int result_length;
  char str[40] = "povZFToValueZMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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

char* povZFToValueZMax() {
  Serial.println("@povZFToValueZMax");
  int result_length;
  char str[40] = "povZFToValueZMax";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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


char* povZFToValueZSet() {
  Serial.println("@povZFToValueZSet");
  int result_length;
  char str[40] = "povZFToValueZSet";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }

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

  Serial.println(result);
  return result;
}

char* povZFToValueFMin() {
  Serial.println("@povZFToValueFMin");
  int result_length;
  char str[40] = "povZFToValueFMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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
  // EEPROM.write(2, focus_current);
  // EEPROM.commit();
  return result;
}

char* povZFToValueFMax() {
  Serial.println("@povZFToValueFMax");
  int result_length;
  char str[40] = "povZFToValueFMax";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
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
  // EEPROM.write(2, focus_current);
  // EEPROM.commit();
  return result;
}


char* povZFToValueFSet() {
  Serial.println("@povZFToValueFSet");
  int result_length;
  char str[40] = "povZFToValueFSet";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);


  char** android_message_parts_array = decode_android_message(android_message, &num_parts);
  char* functionName = android_message_parts_array[0]; 
  char* focus_current_str = android_message_parts_array[1];//get back the initial focus_current
  char* focus_target_str = android_message_parts_array[2];
  focus_current = atoi(focus_current_str); // Convert string to integer 
  int pos_desired = atoi(focus_target_str); // Convert string to integer

  //go back to initial focus
  setAccel(FOCUS, CALI_ACCEL);
  moveMotor(FOCUS, focus_current,0);

  Serial.println(result);
  return result;
}


char* povZFToValueStart() {
  Serial.println("@povZFToValueStart");
  int result_length;
  char str[40] = "povZFToValueStart";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);


  char** android_message_parts_array = decode_android_message(android_message, &num_parts);
  char* functionName = android_message_parts_array[0]; 
  char* zoom_current_str = android_message_parts_array[1];//get back the initial zoom_current
  char* zoom_target_str = android_message_parts_array[2];
  char* focus_current_str = android_message_parts_array[3];//get back the initial focus_current
  char* focus_target_str = android_message_parts_array[4];

  zoom_current = atoi(zoom_current_str); // Convert string to integer 
  int zoom_desired = atoi(zoom_target_str); // Convert string to integer

  focus_current = atoi(focus_current_str); // Convert string to integer 
  int focus_desired = atoi(focus_target_str); // Convert string to integer


  //carry out main action
  goMultiDist(zoom_desired, focus_desired,motor_time,1,true,true,true);


  Serial.println(result);
  return result;
}


char* povZFToValueBackStart() {
  Serial.println("@povZFToValueBackStart");
  int result_length;
  char str[40] = "povZFToValueBackStart";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 30);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);


  char** android_message_parts_array = decode_android_message(android_message, &num_parts);
  char* functionName = android_message_parts_array[0]; 
  char* zoom_current_str = android_message_parts_array[1];//get back the initial zoom_current
  char* zoom_target_str = android_message_parts_array[2];
  char* focus_current_str = android_message_parts_array[3];//get back the initial focus_current
  char* focus_target_str = android_message_parts_array[4];

  int previous_zoom_pos = zoom_current;
  int previous_focus_pos = focus_current;

  zoom_current = atoi(zoom_current_str); // Convert string to integer 
  int zoom_desired = atoi(zoom_target_str); // Convert string to integer

  focus_current = atoi(focus_current_str); // Convert string to integer 
  int focus_desired = atoi(focus_target_str); // Convert string to integer

  //carry out main action
  goMultiDist(zoom_desired, focus_desired, motor_time,2, false, false,true);
  goMultiDist(previous_zoom_pos, previous_focus_pos, motor_time,2, false, true,false);

  Serial.println(result);
  return result;
}


