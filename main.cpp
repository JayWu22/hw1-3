#include "mbed.h"
#include <cstdio>

DigitalIn mypin(BUTTON1);
DigitalOut myled(LED1);
DigitalOut myled2(LED2);


int re[5]={1,1,1,1,1};

int main()
{   
    mypin.mode(PullNone);
    for (int i = 0 ; i < 5; i++) {
        myled2=1;
        int pinstate = mypin;
        int press = 0;
        ThisThread::sleep_for(100ms);
        for (int j = 0; j < 18; j++) {
            if (pinstate == 1 && mypin == 0) {
                press++;
            }
            pinstate = mypin;
            ThisThread::sleep_for(100ms);  
        }
        if (press == 3) re[i] = 0;
        myled2.write(0);
        ThisThread::sleep_for(100ms);
    }
    for (int i=0; i < 5; i++) {
        if (re[i]==0) {
            myled=1;
            myled2=1;
            ThisThread::sleep_for(500ms);
            myled.write(0);
            myled2.write(0);
            ThisThread::sleep_for(500ms);
        } else {
            myled=1;
            ThisThread::sleep_for(500ms);
            myled.write(0);
            ThisThread::sleep_for(500ms);
        }
    }
}

