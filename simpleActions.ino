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

