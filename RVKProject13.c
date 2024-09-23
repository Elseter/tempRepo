/* Purpose of the program: Read in string from file, preform math on it, then output it to a file
//Author: COMSC420 - Riley King
//File name: RVKProject13.c
//Date: 09/22/24 */

#include <stdio.h>
#include <stdlib.h>

int main(){

    // Initialize Variables
    FILE *fptrIn, *fptrOut;
    char inputStr[100];
    char outputStr[100];
    int number;
    char *ptr;

    // Open data.txt
    fptrIn = fopen("data.txt", "r");
    if (fptrIn == NULL) {
        return 1;
    }

    // read in data, then close input stream
    fgets(inputStr, sizeof(inputStr), fptrIn);
    fclose(fptrIn);

    ptr = inputStr;
    int offset = 0;

    // Parse the integers from inputStr, add one to each, and store in outputStr
    while (*ptr != '\0') {
        number = strtol(ptr, &ptr, 10);
        number += 1;

        // Append the new number to outputStr
        // Use sprintf to concatenate the integer to the outputStr
        offset += sprintf(outputStr + offset, "%d ", number); 
    }

    // Open output.txt 
    fptrOut = fopen("output.txt", "w");
    if (fptrOut == NULL) {
        return 1;
    }

    // Write Ouput String 
    fputs(outputStr, fptrOut);
    fclose(fptrOut);

    // Print Debug Message
    printf("Modified data written to output.txt: %s\n", outputStr);


    return 0;
}