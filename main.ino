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
