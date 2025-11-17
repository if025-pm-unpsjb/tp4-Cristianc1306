#include "mbed.h"

PwmOut leds[] = {LED1, LED2, LED3, LED4};

int main() {

    while (1) {
        for (int i = 0; i < 4; i++) {
            for (float p = 0.0f; p < 1.0f; p += 0.1f) {
                leds[i] = p;
                wait(0.5);
            }

            leds[i] = 0; 
        }
    }
}
