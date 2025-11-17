#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);
Serial pc(USBTX, USBRX);  

int intervalo = 500;  
char buffer[10];
int indice = 0;

void leerIntervalo() {

    char c = pc.getc();
    pc.putc(c);

    if (c == '\r') {  
    	pc.printf("\n");
        buffer[indice] = '\0';      
        intervalo = atoi(buffer);  
        indice = 0;
    } 
    else  {
        buffer[indice++] = c;
    }    
}

int main() {

    pc.printf("Ingrese un intervalo en ms (por ejemplo: 500):");

    while (1) {

        for (int i = 0; i < 16; i++) {
            led1 = (i / 1) % 2;   // bit 0
            led2 = (i / 2) % 2;   // bit 1
            led3 = (i / 4) % 2;   // bit 2
            led4 = (i / 8) % 2;   // bit 3

            wait_ms(intervalo);

            if (pc.readable()) {  
                leerIntervalo();
            }    
        }
    }
}

