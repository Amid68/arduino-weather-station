/**
  * @file arduino-weather-station.ino
  * @brief DHT11 Sensor Reading with LCD Display
  *
  * @author Ameed Othman
  * @date 2024-11-06
  **/

#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 8     
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  dht.begin();         
  lcd.begin(16, 2);    
  lcd.clear();         
}

void loop() {
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();  

  if (isnan(humidity) || isnan(temperatureC)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    lcd.setCursor(0, 1);
    lcd.print("Check Wiring");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(humidity, 1); 
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperatureC, 1);  
    lcd.print(" C");
  }

  delay(2000);
}
