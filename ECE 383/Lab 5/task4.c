#include "pic24_all.h"
int main() {
    // Orion Gregory 12160343
    // Caleb Thompson 12145922
    uint8_t count = 3;
    uint8_t x = 1;
    uint8_t y = 3;

    while (count != 0) {
        if (x == y) { 
            y++; // only happens once, y = 4;
        }
        if (x < y) {
            x = x + 2; // first: x = 3, second: x = 5
        }
        count--; // loops three times.
    }
    return 0;
}
