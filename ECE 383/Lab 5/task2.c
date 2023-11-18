#include "pic24_all.h"

/*
Caleb Thompson
CWID:12145922
Orion Gregory
CWID: 12160343
*/

// Function to count the number of one bits in a 16-bit unsigned integer
unsigned char countOneBits(unsigned int check_val) {
    unsigned char ones_count = 0;
    while (check_val > 0) {
        if (check_val & 1) {
            ones_count++;
        }
        check_val >>= 1;
    }
    return ones_count;
}

// Function to find the location of the first bit set in a 16-bit unsigned integer
unsigned char findFirstOne(unsigned int check_val) {
    unsigned char first_one = 0;
    while ((check_val & 1) == 0) {
        first_one++;
        check_val >>= 1;
    }
    return first_one;
}

void main(void) {
    // Input value, change it as needed
    unsigned int check_val = 0xF508;

    // Variables to store results
    unsigned char ones_count, first_one;

    // Calculate the number of one bits and the location of the first bit set
    ones_count = countOneBits(check_val);
    first_one = findFirstOne(check_val);
}