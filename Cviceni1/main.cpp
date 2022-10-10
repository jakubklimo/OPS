#include "mbed.h"
#include <iostream>
#include <string> 
#include "stm32746g_discovery_lcd.h"

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
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);

    BSP_LCD_DisplayStringAt(0, 1, (uint8_t *)"Anežka a Jakub", CENTER_MODE);

    string in = ".- -. . --.. -.- .-/.--- .- -.- ..- -...";
    while(1) {
        morse(in, in.length());
    }
}


