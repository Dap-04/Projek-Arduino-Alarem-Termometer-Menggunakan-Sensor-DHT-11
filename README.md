# Projek-Arduino-Alarem-Termometer-Menggunakan-Sensor-DHT-11
//Project ini merupakan pengembangan alat pengukur suhu berbasis Internet of Things (IoT) yang dirancang untuk memantau suhu secara real-time, sistem ini dibangun menggunakan Arduino IDE sebagai platform pemrograman dan simulasi Proteus sebelum direalisasikan pada perangkat fisik.

//Library yng dipakai
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"


#define DHTPIN 2                   // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11              // Uncomment whatever type you're using
#define BUZZER 9                   // Digital pin connected to the BUZZER


DHT dht(DHTPIN, DHTTYPE);          // Initialize DHT sensor.
LiquidCrystal_I2C lcd(0x27 , 16, 2);  // set LCD address to 0x20 for a 16 chars and 2 line display


void setup()
{
  Serial.begin(9600);              // Initialize device
  dht.begin();
  lcd.init();                      // initialize the lcd 
  lcd.backlight();                 // initialize the backlight
  pinMode(BUZZER,OUTPUT);


  // Print a message to the LCD Or Monitor on PC.
  lcd.setCursor(0, 0);             
  lcd.print("Termometer");
  lcd.setCursor(0, 1);
  lcd.print("Initialization...");
  delay(2000);
  lcd.clear();
}



void loop()
{
  int h = dht.readHumidity();    // Read humidity kalo mau output datanya ada koma pake float
  int t = dht.readTemperature(); // Read temperature as Celsius kalo mau make yang fahrenheit pake dht.readTemperature(true)


  Serial.print("Temp: ");        // Buat munculin output di arduino dan bisa dilihat di monitor arduino ide 
  Serial.print(t);
  Serial.print(" C | Hygro: ");
  Serial.print(h);
  Serial.print(" % | ");


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(t);
  lcd.print("C H:");
  lcd.print(h);
  lcd.print("%");


  if(t>40){                      
    lcd.setCursor(0, 1);
    lcd.print("Temp Alert !");
    tone(BUZZER,1000);
  }
  else{
    lcd.setCursor(0, 1);
    lcd.print("All Normal");
    noTone(BUZZER);
  }


  delay(1000);
}

## Required components
 * 1x Arduino UNO R3
 * 1x Buzzer
 * 1x DHT 11
 * 1x LCD 16x2 with I2c
 * 1x Breadbord
 * Jumper wire (as needed)

## Schematic Diagram
![circuit diagram](https://github.com/Dap-04/Projek-Arduino-Alarem-Termometer-Menggunakan-Sensor-DHT-11/blob/12f4d31ded498c02a462b8f869f68cc81d1985c0/Screenshot%202025-11-16%20233940.png)


## NOTE
Pay attention to the pin numbers in the source code to make it work!
Perhatikan nomor pin yang digunakan dalam kode sumber untuk membuatnya berfungsi!
