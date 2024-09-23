#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    // Initialize file pointers
    FILE *fptrIn, *fptrOut;
    char ch;

    // Open data.txt for reading
    fptrIn = fopen("data.txt", "r");
    if (fptrIn == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Open output.txt for writing
    fptrOut = fopen("output.txt", "w");
    if (fptrOut == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(fptrIn);
        return 1;
    }

    // Read input file character by character
    while ((ch = fgetc(fptrIn)) != EOF) {

        if (isdigit(ch)) {
            // Convert character to integer, add 1, and convert back to character
            int num = ch - '0';  // Convert from char '0'-'9' to int 0-9
            num += 1;            // Increment the integer by 1

            // Handle case when num exceeds 9 (wrap around)
            if (num > 9) {
                num = 0;
            }

            // Write the incremented number as a character to output
            fputc(num + '0', fptrOut);  // Convert int back to char
        } else {
            // If it's not a digit, write the character directly to output
            fputc(ch, fptrOut);
        }
    }

    // Close both files
    fclose(fptrIn);
    fclose(fptrOut);

    printf("Modified data written to output.txt\n");

    return 0;
}


    return 0;
}
