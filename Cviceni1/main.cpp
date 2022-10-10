#include "mbed.h"
#include <iostream>
#include <string> 

DigitalOut myled(LED1);

float tecka = 0.2;
float carka = 0.6;
float meziZnaky = 0.1;
float pauzaKratka = 1.0;
float pauzaDlouha = 3.0;

void morse (String morseIn, int pocet){

    for (int i = 0; i < pocet; i++) {
        if(morseIn[i] == '.'){
            myled = 1;
            wait(tecka);
            myled = 0;
            wait(meziZnaky);
        }else if(morseIn[i] == '-'){
            myled = 1;
            wait(carka);
            myled = 0;
            wait(meziZnaky);
        }else if(morseIn[i] == ' '){
            wait(pauzaKratka);
        }else{
            wait(pauzaDlouha);
        }
    }
}

int main() {  
    string in = ".- -. . --.. -.- .-/.--- .- -.- ..- -...";
    while(1) {
        morse(in, in.length());
    }
}


