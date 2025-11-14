#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int main() {
    while (1) {
        for (int i = 0; i < 16; i++) {

            led1 = (i / 1) % 2;     // bit 0 
            led2 = (i / 2) % 2;     // bit 1
            led3 = (i / 4) % 2;     // bit 2
            led4 = (i / 8) % 2;     // bit 3

            wait(1); 
        }
    }
}
