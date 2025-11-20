/*
 * main.c
 *
 *  Created on: 13 oct. 2022
 *      Author: fep
 */

#include "app.h"         // <= Su propia cabecera (opcional)
#include "sapi.h"        // <= Biblioteca sAPI

int main( void )
{
        // Inicializar y configurar la placa de desarrollo
        boardConfig();

        uartConfig(UART_USB, 9600); 

        char buffer[32];
        uint8_t index = 0;

        while( TRUE ) {

            if(uartReadByte(UART_USB, &buffer[index])) {

                if(buffer[index] == '\r') {

                   buffer[index + 1] = '\0'; 

                   uartWriteString(UART_USB, buffer);
                   uartWriteString(UART_USB, "\r\n");

                   index = 0;
                }
                else {
                   index++;
                }
            }
        
        }
}
