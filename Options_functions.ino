char* switchOrientation(){
  Serial.println("@switchOrientation");
  int result_length;
  char str[30] = "switchOrientation";
  
  // Allocate memory for the result string,20 is just an arbitrary buffer size for the integer
  char* result = (char*)malloc(strlen(str) + 20);
  // Finding the length of the string

  // Copy the original string to the result string
  strcpy(result, str);
  char** android_message_parts_array = decode_android_message(android_message, &num_parts);
  char* functionName = android_message_parts_array[0]; 
  char* orientation_str = android_message_parts_array[1];
  orientation = atoi(orientation_str); // Convert string to integer 
  EEPROM.write(4, orientation);
  EEPROM.commit();
  Serial.println(result);
  return result;
}