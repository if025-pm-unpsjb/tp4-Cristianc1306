/*
 * main.c
 *
 *  Created on: 13 oct. 2022
 *      Author: fep
 */

#include "app.h"         // <= Su propia cabecera (opcional)
#include "sapi.h"        // <= Biblioteca sAPI


int main(void) {

    boardConfig();
    uartConfig(UART_USB, 9600);

    bool_t ledR = OFF;
    bool_t ledG = OFF;
    bool_t ledB = OFF;

    bool_t rgbEnabled = OFF;   

    while(TRUE) {

        if(!gpioRead(TEC1)) {
            rgbEnabled = !rgbEnabled;
            printf("BOTON1\r\n");
            delay(200);
        }

        if(!gpioRead(TEC2)) {
            ledR = !ledR;
            printf("BOTON2\r\n");
            delay(200);
        }

        if(!gpioRead(TEC3)) {
            ledG = !ledG;
            printf("BOTON3\r\n");
            delay(200);
        }

        if(!gpioRead(TEC4)) {
            ledB = !ledB;
            printf("BOTON4\r\n");
            delay(200);
        }

        if(rgbEnabled) {
            gpioWrite(LEDR, ledR);
            gpioWrite(LEDG, ledG);
            gpioWrite(LEDB, ledB);
        } else {
            gpioWrite(LEDR, OFF);
            gpioWrite(LEDG, OFF);
            gpioWrite(LEDB, OFF);
        }

        delay(20);
    }

    return 0;
}

