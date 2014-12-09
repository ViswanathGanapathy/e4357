include "mbed.h"
#include "Websocket.h"
#define MEAN_VALUE_MIC 32500

Serial pc(USBTX, USBRX);
Timer tmr;

Websocket ws("ws://sockets.mbed.org/ws/sensors/wo");

AnalogIn light_pin(p19);
AnalogIn mic_pin(p18);

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);
void notify(int a, int b, int c) {
    led1 = a;
    led2 = b;
    led3 = c;
}

int main() {
    notify(1, 0, 0);
    
    //unsigned short light;
    char json_str[100];
    int press;
    double temp;
    int light;
    unsigned short mic_mean;
    unsigned short mic = 0;

    char recv[128];
    while (1) {

        while (!ws.connect()) {
            pc.printf("cannot connect websocket, retrying in one second\r\n");
            wait(1.0);
        }
        notify(0, 0, 1);

        pc.printf("Connected\r\n");

        tmr.start();
        while (1) {

            if (tmr.read() > 0.5) {

                //pressure
                //press = scp1000.readPressure();
                press = 10;

                //temperature
                //temp = scp1000.readTemperature();
                temp = 10.1;

                //light
                light = light_pin.read_u16()/480;

                //microphone
                mic_mean = 0;
                for (double i = 0; i < 200; i++) {
                    mic = mic_pin.read_u16();
                    mic = (mic > MEAN_VALUE_MIC) ? mic : MEAN_VALUE_MIC + (MEAN_VALUE_MIC - mic);
                    mic_mean = (mic_mean*i + mic)/(i+1);
                }
                pc.putc('!');
                
                sprintf(json_str, "{\"id\":\"eth_env\",\"p\":\"%d\",\"t\":\"%d\",\"l\":\"%d\",\"m\":\"%d\"}", (int)press, (int)temp, (int)(140 - light), mic_mean);
                ws.send(json_str);
                
                led4 = !led4;
                
                if (ws.read(recv)) {
                    pc.printf(".");
                    pc.printf("recv: %s\r\n", recv);
                }

                tmr.start();
            }

            Net::poll();
        }
    }
}
