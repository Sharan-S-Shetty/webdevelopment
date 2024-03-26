#include <stdio.h>

// Function to perform bit stuffing
void bitStuffing(char* input, char* output) {
    int count = 0;
    char* ptr = output;

    while (*input != '\0') {
        if (*input == '1') {
            count++;
            *ptr++ = *input++;
        } else {
            count = 0;
            *ptr++ = *input++;
        }

        if (count == 5) {
            *ptr++ = '0';  // Stuff a '0' after five consecutive '1's
            count = 0;
        }
    }

    *ptr = '\0';
}

// Function to perform byte stuffing
void byteStuffing(char* input, char* output) {
    char* ptr = output;

    while (*input != '\0') {
        if (*input == 'D' && *(input + 1) == 'L') {
            *ptr++ = 'E';  // Stuff an 'E' after 'D' in the data
            *ptr++ = 'S';  // Stuff an 'S' after 'L' in the data
            input += 2;
        } else {
            *ptr++ = *input++;
        }
    }

    *ptr = '\0';
}

int main() {
    char input[] = "110111110111111111101111101101011";
    char bitStuffed[100];
    
    printf("Original bit stream: %s\n", input);

    bitStuffing(input, bitStuffed);
    printf("Bit-stuffed stream: %s\n", bitStuffed);

    char inputData[] = "DLESDLEEDL";
    char byteStuffed[100];

    printf("\nOriginal byte stream: %s\n", inputData);

    byteStuffing(inputData, byteStuffed);
    printf("Byte-stuffed stream: %s\n", byteStuffed);

    return 0;
}
