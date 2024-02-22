bool isNullOrEmpty(const char *str) {
    return (str == NULL || str[0] == '\0');
}

char** decode_android_message(const char* input, int* num_parts) {
    char** parts = (char**)malloc(MAX_PARTS * sizeof(char*));
    if (parts == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    char* token;
    int count = 0;

    // Copy the input string to prevent modification
    char* input_copy = strdup(input);
    if (input_copy == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Split the input string using strtok
    token = strtok(input_copy, "_");
    while (token != NULL && count < MAX_PARTS) {
        parts[count] = strdup(token);
        if (parts[count] == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        count++;
        token = strtok(NULL, "_");
    }
    free(input_copy);

    *num_parts = count;
        //functionName_param1_param2_
        //parts -> [functionName_param1_param2,...,...]
    return parts;
}