#include "mbed.h"

DigitalOut myled(LED3);

int main() {
    while(1) {
        myled = 1;
        wait(10);
        myled = 0;
        wait(10);
    }
}
