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

    while(TRUE) {


        while(TRUE) {

            if(!gpioRead(TEC1)) {
                gpioToggle(CIAA_BOARD_LED);
                printf("BOTON1\r\n");
                delay(300);
            }

            if(!gpioRead(TEC2)) {
                gpioToggle(LED1);
                printf("BOTON2\r\n");
                delay(300);
            }

            if(!gpioRead(TEC3)) {
                gpioToggle(LED2);
                printf("BOTON3\r\n");
                delay(300);
            }

            if(!gpioRead(TEC4)) {
                gpioToggle(LED3);
                printf("BOTON4\r\n");
                delay(300);
            }
        }

    }

    return 0;
}
