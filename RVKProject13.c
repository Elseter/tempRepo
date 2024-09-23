#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    // Initialize Variables
    FILE *fptrIn, *fptrOut;
    char inputStr[100];
    char *outputStr;
    int outputSize = 100;
    int number;
    char *ptr;

    // Allocate initial memory for outputStr
    outputStr = (char *)malloc(outputSize * sizeof(char));
    if (outputStr == NULL) {
        printf("Error: Memory allocation failed for outputStr.\n");
        return 1;
    }
    outputStr[0] = '\0';  // Ensure it's an empty string initially

    // Open data.txt
    fptrIn = fopen("data.txt", "r");
    if (fptrIn == NULL) {
        printf("Error: Could not open input file.\n");
        free(outputStr);  // Free allocated memory on error
        return 1;
    }

    // Read in data, then close input stream
    if (fgets(inputStr, sizeof(inputStr), fptrIn) == NULL) {
        printf("Error: Could not read input file.\n");
        fclose(fptrIn);
        free(outputStr);  // Free allocated memory on error
        return 1;
    }
    fclose(fptrIn);

    printf("Input read: %s\n", inputStr);

    ptr = inputStr;
    int offset = 0;

    // Parse the integers from inputStr, add one to each, and store in outputStr
    while (*ptr != '\0') {
        number = strtol(ptr, &ptr, 10);

        // Ensure there was a valid number found
        if (ptr == inputStr) {  
            printf("Error: No valid integers found in input.\n");
            free(outputStr);  // Free allocated memory on error
            return 1;
        }

        number += 1;

        // Check if we need to reallocate memory for outputStr
        if (offset + 20 > outputSize) {  // Roughly allow 20 characters per integer
            outputSize *= 2;  // Double the size of the output buffer
            outputStr = (char *)realloc(outputStr, outputSize * sizeof(char));
            if (outputStr == NULL) {
                printf("Error: Memory reallocation failed for outputStr.\n");
                return 1;
            }
        }

        // Append the new number to outputStr
        offset += sprintf(outputStr + offset, "%d ", number);
    }

    // Open output.txt 
    fptrOut = fopen("output.txt", "w");
    if (fptrOut == NULL) {
        printf("Error: Could not open output file.\n");
        free(outputStr);  // Free allocated memory on error
        return 1;
    }

    // Write Output String 
    fputs(outputStr, fptrOut);
    fclose(fptrOut);

    // Print Debug Message
    printf("Modified data written to output.txt: %s\n", outputStr);

    // Free allocated memory
    free(outputStr);

    return 0;
}
