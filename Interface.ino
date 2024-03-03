void goDist(int type, int pos_desired, float motor_time, float motor_div,bool goBack, bool lastSequence,bool showScreen) {
  // Serial.print("@goDist motor_time = ");
  // Serial.println(motor_time);
  
  int pos_current, upper_limit;
  pos_current = type ? zoom_current : focus_current;
  upper_limit = type ? zoom_range : focus_range;

  if(showScreen){
      // start sound
      play_sound_1();
  }

  //move motor depending on excess_option_set
  switch (excess_option_set){
    //pre, delay then move
    case 0:{
      Serial.println("Pre");
      Serial.print("(shutter_time - motor_time) / motor_div = ");
      Serial.print("remainder_time = ");
      Serial.println((shutter_time - motor_time) / motor_div);
      float remainder_time = (shutter_time - motor_time) / motor_div;
      if(camera_shutter_open == 0){
        open_Shutter();
        camera_shutter_open = 1;
      }
      //delay in ms
      delay(remainder_time * 1000);
      moveMotor(type, pos_desired, motor_time / motor_div);
      break;
    }
    //split
    case 1:{
      Serial.println("Split");
      Serial.print("shutter_time - motor_time = ");
      Serial.println((shutter_time - motor_time) / motor_div);
      float remainder_time = (shutter_time - motor_time) / motor_div;
      float front_remainder_time = remainder_time / 2;
      float back_remainder_time = remainder_time / 2;
      if(camera_shutter_open == 0){
        open_Shutter();
        camera_shutter_open = 1;
      }
      //delay in ms
      delay(front_remainder_time * 1000);
      moveMotor(type, pos_desired, motor_time / motor_div);
      //delay in ms
      delay(back_remainder_time * 1000);
      break;
    }
    //after, move then delay
    case 2 :{
      Serial.println("After");
      Serial.print("shutter_time - motor_time = ");
      Serial.println((shutter_time - motor_time) / motor_div);
      float remainder_time = (shutter_time - motor_time) / motor_div;
      if(camera_shutter_open == 0){
        open_Shutter();
        camera_shutter_open = 1;
      }
      moveMotor(type, pos_desired, motor_time / motor_div);
      //delay in ms
      delay(remainder_time * 1000);
      break;
    }
    default:{
      break;
    }
    
  }

  //zoom / focus current postion after moving to desired position
  if (type) { // ZOOM
    zoom_current = pos_desired;
  } 
  else { // FOCUS
    focus_current = pos_desired;
  }

  //end sound 
  if(lastSequence){    
    close_Shutter();
    if(camera_shutter_open == 1){
        play_sound_2();
        camera_shutter_open = 0;
      }
  }

  // returns to original spot, go back acceleration and speed could be faster
  if (goBack) {
    if(showScreen){
    }
    moveMotor(type, pos_current, 0);
    //zoom / focus current postion after moving to desired position
    if (type) { // ZOOM

      zoom_current = pos_current;
      setCurrentPos(ZOOM, zoom_current * MS_STEP);
    } else { // FOCUS
      focus_current = pos_current;
       setCurrentPos(FOCUS, zoom_current * MS_STEP);
    }
  }
}