#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// function definitions
void validateArg(char *arg);
char* reverseStr(char *str);
int* doubleSecVal(char *str);


int main(int argc, char *argv[]) {

    // validating user argument/input
    validateArg(argv[1]);

    // getting the reversed string
    char *reversed = reverseStr(argv[1]);

    printf("Original string: %s\n", argv[1]);
    printf("Reversed string: %s\n", reversed);

    // double every second digit
    int *doubled = doubleSecVal(reversed);
    bool isSecond = false;
    int total = 0;
    for (int i = 0; i < 16; i++) {
        // (isSecond) ? puts("true") : puts("false");

        if (isSecond) {
            isSecond = false;
            doubled[i] = doubled[i] + doubled[i]; // double every second digit

            // subtracting by 9 if the value is greater than 9
            if (doubled[i] > 9) {
                doubled[i] = doubled[i] - 9;
            }
        } else {
            isSecond = true;
        }

        // printf("%d\n", doubled[i]);
        total += doubled[i];
    }

    // final output
    int result = total % 10;
    if (result == 0) {
        printf("Card Number: %s, has passed the LUHN test!\n", argv[1]);
    } else {
        printf("Card Number: %s, did not pass the LUHN test!\n", argv[1]);
    }

    // freeing up the manually allocated memory
    free(reversed);
    free(doubled);

    return EXIT_SUCCESS;
}


// function declarations
void validateArg(char *arg) {
    // checking for NULL value
    if (arg == NULL) {
        puts("No Argument Found!");
        exit(EXIT_FAILURE);
    }

    // credit card number must be 16 digit long
    size_t length = strlen(arg);
    if (length != 16) {
        puts("Credit/Debit Card Numbers Must Be 16 Digit Long!");
        exit(EXIT_FAILURE);
    }

    printf("Value: %s\n", arg);
}

char* reverseStr(char *str) {
    int length = strlen(str);
    char *reversed = (char *)malloc((length + 1) * sizeof(char));
    if (reversed == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int start = 0;
    int end = length - 1;
    while (start < length) {
        reversed[start] = str[end];
        start++;
        end--;
    }

    reversed[length] = '\0';  // Null-terminate the reversed string
    return reversed;
}

int* doubleSecVal(char *str) {
    int length = strlen(str);
    int *doubled = (int *)malloc((length + 1) * sizeof(int));
    if (doubled == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++) {
        doubled[i] = str[i] - '0'; // typecating from char to int
    }

    doubled[length] = '\0';
    return doubled;
}
