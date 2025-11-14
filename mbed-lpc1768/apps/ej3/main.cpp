#include "mbed.h"              

Serial pc(USBTX, USBRX);

int main() {
	pc.printf("Muestra en la pantalla todo lo que escribas\n");
    while(1) {
        pc.putc(pc.getc());
    }
}
