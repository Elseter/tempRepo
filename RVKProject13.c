#include <stdio.h>
#include <stdlib.h>

int main(){

    // Initialize Variables
    FILE *fptrIn, *fptrOut;
    char inputStr[100];
    char outputStr[100] = {0}; // Initialize outputStr to prevent undefined behavior
    int number;
    char *ptr;

    // Open data.txt
    fptrIn = fopen("data.txt", "r");
    if (fptrIn == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // read in data, then close input stream
    if (fgets(inputStr, sizeof(inputStr), fptrIn) == NULL) {
        printf("Error: Could not read input file.\n");
        fclose(fptrIn);
        return 1;
    }
    fclose(fptrIn);

    printf("Input read: %s\n", inputStr);

    ptr = inputStr;
    int offset = 0;

    // Parse the integers from inputStr, add one to each, and store in outputStr
    while (*ptr != '\0') {
        // strtol will skip non-numeric characters
        number = strtol(ptr, &ptr, 10);

        if (ptr == inputStr) {  // Handle case where no integers are found
            printf("Error: No valid integers found in input.\n");
            return 1;
        }

        number += 1;

        // Append the new number to outputStr
        if (offset < sizeof(outputStr) - 1) { // Check for buffer overflow
            offset += sprintf(outputStr + offset, "%d ", number);
        } else {
            printf("Error: outputStr buffer overflow.\n");
            return 1;
        }
    }

    // Open output.txt 
    fptrOut = fopen("output.txt", "w");
    if (fptrOut == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    // Write Output String 
    fputs(outputStr, fptrOut);
    fclose(fptrOut);

    // Print Debug Message
    printf("Modified data written to output.txt: %s\n", outputStr);

    return 0;
}
