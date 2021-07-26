#include <LiquidCrystal.h>  
#include <SoftwareSerial.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);   //LCD :  (rs, enable, d4, d5, d6, d7)
SoftwareSerial mySerial(0, 1); // RX, TX

const int trigPin = 12; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 11; // Echo Pin of Ultrasonic Sensor
const int inputPin1  = 9;  // Pin 10 of L293D IC
const int inputPin2  = 10; // Pin 9 of L293D IC
int ledPin = 8;
void setup() 
{
Serial.begin(9600); // Starting Serial Terminal
//mySerial.begin(9600);
lcd.begin(20,4);                                                   
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(inputPin1, OUTPUT);
pinMode(inputPin2, OUTPUT);
pinMode(8,OUTPUT);
lcd.setCursor(0,0);
lcd.print("Distance");
Serial.print("Distance");
lcd.setCursor(0,1);
lcd.print("Measurement");
Serial.print(" Measurement");
Serial.println();
delay(500);
lcd.setCursor(0,2);
lcd.print("Made By");
Serial.print("Made By");
delay(500);
lcd.setCursor(0,3);
lcd.print("GROUP NO :- 19");
Serial.print(" GROUP NO :- 19");
Serial.println();
delay(1000); //DELAY BY 1 SECOND
lcd.clear();
lcd.setCursor(0,0);
}

void loop()
{
  long duration, inches, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  if (cm >= 300) {
    digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, LOW);
    digitalWrite(ledPin, HIGH);
  }
  else {
    delay(1000);
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, LOW);
    digitalWrite(ledPin, LOW);
  }
    
  Serial.print("Distance:");
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();
  
  Serial.print("Inches: ");
  Serial.print(inches);
  Serial.print(" in");
  Serial.println();
   
  lcd.setCursor(0,0);
  lcd.print("Distance in CM:");
  lcd.setCursor(0,1);
  lcd.print(cm);
  lcd.print(" cm ");

  lcd.setCursor(0,2);
  lcd.print("Distance in Inches:");
  lcd.setCursor(0,3);
  lcd.print(inches);
  lcd.print(" inche ");
  delay(200);
}
long microsecondsToInches(long microseconds)
{
 return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds)
{
   return microseconds / 29 / 2;
}
