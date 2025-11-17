#include "mbed.h"

DigitalOut leds[] = {LED1, LED2, LED3, LED4};

Serial pc(USBTX, USBRX);

int main() {
    pc.printf("Ingrese un numero de LED (1 a 4):");
    int led_num;
    while (1) {
        if (pc.readable()) {  
            char c = pc.getc(); 
            pc.putc(c); 
            led_num = c - '1';
        }
        leds[led_num] = !leds[led_num];
        wait_ms(250);
    }
}
