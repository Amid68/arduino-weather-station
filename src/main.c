/**
 * @file main.c
 * @brief Main program for the Arduino Weather Station
 *
 * This program reads temperature and humidity data from a DHT11 sensor
 * and displays it on an LCD screen.
 *
 * @author Ameed Othman
 * @date 2024-11-06
 */

#include <avr/io.h>
#include <util/delay.h>
#include "dht11.h"
#include "lcd.h"

/**
 * @brief Main function
 *
 * Initializes the LCD and DHT11 sensor, then enters an infinite loop
 * to read sensor data and display it on the LCD.
 *
 */

int main(void) {
    uint8_t temperature = 0;
    uint8_t humidity = 0;

    LCD_Init();
    DHT11_Init();

    while (1) {
        if (DHT11_Read(&temperature, &humidity) == 0) {
            LCD_Clear();
            LCD_Set_Cursor(0, 0);
            LCD_Print("Humdity: ");
            LCD_Print_uint8(humidity);
            LCD_Print("%");

            LCD_Set_Cursor(0, 1);
            LCD_Print("Temp: ");
            LCD_Print_uint8(temperature);
            LCD_Print(" C");
        } else {
            LCD_Clear();
            LCD_Set_Cursor(0, 0);
            LCD_Print("Sensor Error");
            LCD_Set_Cursor(0, 1);
            LCD_Print("Check Wiring!");
        }

        _delay_ms(2000);
    }

    return 0;
}

