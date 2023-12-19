#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define ANALOG_IN_PIN A0
#define RedPin 10
#define GreenPin 11
#define BluePin 12
#define trigPin 6
#define echoPin 7
#define buzzPin 2

float adc_voltage = 0.0;
float in_voltage = 0.0;
float battery = 0.0;


float R1 = 30000.0;
float R2 = 7500.0; 
float ref_voltage = 5.0;
int   adc_value = 0;


float duration = 0;
float distance_cm = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  digitalWrite(buzzPin, HIGH);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


  digitalWrite(RedPin, LOW);
  digitalWrite(GreenPin, LOW);
  digitalWrite(BluePin, LOW);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.blink();
  char text[21] ="DISTANCE MEASUREMENT";
  int i = 0;
  while(i<20)
  {
    lcd.setCursor(i,0);
    lcd.print(text[i]);
    i = i + 1;
    delay(150);
  }
  i = 0;

  char text2[21] =" BY PONGPADA ANOMA  ";
  while(i<20)
  {
    lcd.setCursor(i,1);
    lcd.print(text2[i]);
    i = i + 1;
    delay(150);
  }
  i = 0;

  char text3[21] ="     MILO SEC 2     ";
  while(i<20)
  {
    lcd.setCursor(i,2);
    lcd.print(text3[i]);
    i = i + 1;
    delay(150);
  }
  i = 0;

  char text4[21] ="STUDENT ID  65010666";
  while(i<20)
  {
    lcd.setCursor(i,3);
    lcd.print(text4[i]);
    i = i + 1;
    delay(150);
  }
  i = 0;

  lcd.noBlink();
  delay (5000);
  second_screen_setup();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance_cm = duration * 0.03466 / 2;

  adc_value = analogRead(ANALOG_IN_PIN);
  adc_voltage  = (adc_value * ref_voltage) / 1024.0;
  in_voltage = adc_voltage / (R2/(R1+R2)) ;
  
  battery = ((in_voltage - 6)*100) / (12-6);
  
  if (battery < 0)
  {
    battery = 0.0;
  }
  else if (battery > 99.0)
  {
    battery = 99.0;
  }

  lcd.setCursor(16,1);
  lcd.print("    ");
  lcd.setCursor(17,1);
  lcd.print(battery,0);
  lcd.print("%");

  lcd.setCursor(0,2);
  lcd.print("                    ");
  lcd.setCursor(0,3);
  lcd.print("                    ");

  if (distance_cm < 5 || distance_cm > 100.0){
    my_beep();
    digitalWrite(RedPin, HIGH);
    digitalWrite(GreenPin, LOW);
    digitalWrite(BluePin, LOW);
  }
  else if (distance_cm > 5 && distance_cm < 30){
    digitalWrite(RedPin, LOW);
    digitalWrite(GreenPin, HIGH);
    digitalWrite(BluePin, LOW);
  }
  else if (distance_cm > 30 && distance_cm < 100){
    digitalWrite(RedPin, LOW);
    digitalWrite(GreenPin, LOW);
    digitalWrite(BluePin, HIGH);
  }

  if (distance_cm < 100.0)
  {
  // digitalWrite(buzzPin, HIGH);
  lcd.setCursor(0,2);
  lcd.print("DISTANCE :");
  lcd.print(distance_cm);
  lcd.print(" cm");

  lcd.setCursor(0,3);
  lcd.print("DISTANCE :");
  lcd.print(distance_cm * 10);
  lcd.print(" mm");
  }
  else
  {
    lcd.setCursor(0,2);
    lcd.print("    Out of Range");
    lcd.setCursor(0,3);
    lcd.print("Too Far or Too Close");
  }
  delay(750);
}

void second_screen_setup(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("<-----MEASURING---->");
  lcd.setCursor(0,1);
  lcd.print("MILO | 65010666");
}

void my_beep(){
  digitalWrite(buzzPin,LOW);
  delay(100);
  digitalWrite(buzzPin,HIGH);
  delay(100);
  digitalWrite(buzzPin,LOW);
  delay(100);
  digitalWrite(buzzPin,HIGH);
}
