// Bokeh Effect - changing focus to minimum from pov
//1
char* bokeh() {
  Serial.println("@bokeh");
  int result_length;
  char str[30] = "bokeh";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 40);
  // Check for memory allocation failure
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
  // Finding the length of the string

  //carry out action
 goDist(FOCUS,0,motor_time,1,true,true,true);

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

//Firework-F same as bokeh(Focus Max, then min, then return to original)
//2
char* fireworkFocus() {
  Serial.println("@fireworkFocus");
  int result_length;
  char str[30] = "fireworkFocus";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 40);
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

// Firework-ZF Effect, zoom the wide(min), focus to min at the same time === ZF-min
//3
char* fireworkZoomFocus() {
  Serial.println("@fireworkZoomFocus");
  int result_length;
  char str[30] = "fireworkZoomFocus";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 40);
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


//ZoomBlur min === zoom to min
//4
char* zoomBlurMin() {
  Serial.println("@zoomBlurMin");
  int result_length;
  char str[30] = "zoomBlurMin";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 40);
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

//Zoomblue-max === zoom to max
//5
char* zoomBlurMax() {
  Serial.println("@zoomBlurMax");
  int result_length;
  char str[30] = "zoomBlurMax";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 40);
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

//SinWave-1 assume focus - small to wide wave
//assume 3 wave motion
//6
char* sinWave1() {
  Serial.println("@sinWave1");
  int result_length;
  char str[30] = "sinWave1";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 40);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
  // Finding the length of the string

  //carry out action
  int initial_pos = focus_current;
  int min_distance_range = initial_pos - 0;
  int max_distance_range = focus_range - initial_pos;
  
  int total_waves = 3;
  int initial_wave = 1;
  int last_wave = 3;
  for (int cur_wave = 1; cur_wave <= total_waves; cur_wave++) {
    int max_direction_to_travel = initial_pos + ((max_distance_range / total_waves) * cur_wave);
    int min_direction_to_travel = initial_pos - ((min_distance_range / total_waves) * cur_wave);
    //trial and error (unless got better idea)
    int wave_motor_div = total_waves * 12;
    //first time initiate start sound and keep screen there
    if(cur_wave == initial_wave){
      goDist(FOCUS, max_direction_to_travel, motor_time,wave_motor_div,false,false,true);
      goDist(FOCUS, initial_pos, motor_time,wave_motor_div,false,false,false);
      goDist(FOCUS, min_direction_to_travel, motor_time,wave_motor_div,false,false,false);
      goDist(FOCUS, initial_pos, motor_time,wave_motor_div,false,false,false);
    }
    //last wave
    else if(cur_wave == last_wave){
      goDist(FOCUS, max_direction_to_travel, motor_time,wave_motor_div,false,false,false);
      goDist(FOCUS, initial_pos, motor_time,wave_motor_div,false,false,false);
      goDist(FOCUS, min_direction_to_travel, motor_time,wave_motor_div,false,false,false);
      //last movement and press close shutter
      goDist(FOCUS, initial_pos, motor_time,wave_motor_div,false,true,false);
    }
    //rest of the waves
    else{
      goDist(FOCUS, max_direction_to_travel, motor_time,wave_motor_div,false,false,false);
      goDist(FOCUS, initial_pos, motor_time,wave_motor_div,false,false,false);
      goDist(FOCUS, min_direction_to_travel, motor_time,wave_motor_div,false,false,false);
      goDist(FOCUS, initial_pos, motor_time,wave_motor_div,false,false,false);
    }
  }

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}

//SinWave-2 - wide to small wave
//assume 3 wave motion
//7
char* sinWave2() {
  Serial.println("@sinWave2");
  int result_length;
  char str[30] = "sinWave2";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 40);
  if (result == NULL) {
        Serial.println("Memory allocation failed");
        return NULL;
  }
  // Finding the length of the string

  //carry out action
  int initial_pos = focus_current;
  int min_distance_range = initial_pos - 0;
  int max_distance_range = focus_range - initial_pos;
  int total_waves = 3;
  int initial_wave = 3;
  int last_wave = 1;

  for (int cur_wave = 3; cur_wave >= last_wave; cur_wave--) {
    int max_direction_to_travel = initial_pos + ((max_distance_range / total_waves) * cur_wave);
    int min_direction_to_travel = initial_pos - ((min_distance_range / total_waves) * cur_wave);
    //trial and error (unless got better idea)
    int wave_motor_div = total_waves * 12;

    //first time initiate start sound and keep screen there
    if(cur_wave == initial_wave){
      goDist(FOCUS, max_direction_to_travel, motor_time,wave_motor_div,false,false,true);
      goDist(FOCUS, initial_pos, motor_time,wave_motor_div,false,false,false);
      goDist(FOCUS, min_direction_to_travel, motor_time,wave_motor_div,false,false,false);
      goDist(FOCUS, initial_pos, motor_time,wave_motor_div,false,false,false);
    }
    //last wave
    else if(cur_wave == last_wave){
      goDist(FOCUS, max_direction_to_travel, motor_time,wave_motor_div,false,false,false);
      goDist(FOCUS, initial_pos, motor_time,wave_motor_div,false,false,false);
      goDist(FOCUS, min_direction_to_travel, motor_time,wave_motor_div,false,false,false);
      //last movement and press close shutter
      goDist(FOCUS, initial_pos, motor_time,wave_motor_div,false,true,false);
    }
    //rest of the waves
    else{
      goDist(FOCUS, max_direction_to_travel, motor_time,wave_motor_div,false,false,false);
      goDist(FOCUS, initial_pos, motor_time,wave_motor_div,false,false,false);
      goDist(FOCUS, min_direction_to_travel, motor_time,wave_motor_div,false,false,false);
      goDist(FOCUS, initial_pos, motor_time,wave_motor_div,false,false,false);
    }
  }

  // Copy the original string to the result string
  strcpy(result, str);
  result_length = strlen(result);
  result[result_length] = '_';
  result[result_length + 1] = '\0';
  Serial.println(result);
  return result;
}
