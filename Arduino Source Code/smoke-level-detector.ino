#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
 
int redLed = 10;
int greenLed = 12;
int buzzer = 8;
int smokeA0 = A0;
// Your threshold value
int sensorThres = 30;
 
void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}
 
void loop() {
  int analogSensor = analogRead(smokeA0);
 
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  lcd.print("Smoke Level:");
  lcd.print(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    lcd.setCursor(0, 2);
    lcd.print("Alert....!!!");
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    lcd.setCursor(0, 2);
    lcd.print(".....Normal.....");
    noTone(buzzer);
  }
  delay(500);
  lcd.clear();
}
