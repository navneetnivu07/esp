#include "max6675.h"

// Thermocouple 1
int thermoDO1 = 18; //D18
int thermoCS1 = 19; //D19
int thermoCLK1 = 21; //D21

// Thermocouple 2
int thermoDO2 = 34; //D34
int thermoCS2 = 35; //D35 ->33
int thermoCLK2 = 32; //D32

MAX6675 thermocouple1(thermoCLK1, thermoCS1, thermoDO1);
MAX6675 thermocouple2(thermoCLK2, thermoCS2, thermoDO2);

// Arduino Pins used to control 74HC4067 MUX
int A = 5; //D5 S0
int B = 4; //D4 S1
int C = 2; //D2 S2 
int D = 15; //D15 S3

void setup() {

  pinMode(A, OUTPUT); digitalWrite(A, HIGH);
  pinMode(B, OUTPUT); digitalWrite(B, HIGH);
  pinMode(C, OUTPUT); digitalWrite(C, HIGH);
  pinMode(D, OUTPUT); digitalWrite(D, HIGH);
  
  Serial.begin(115200);

}
float tc1_out;
float tc2_out;

void loop() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  delay(1000);
  tc1_out = thermocouple1.readCelsius();
  tc2_out = thermocouple2.readCelsius();
  Serial.print("tc1_out : ");Serial.println(tc1_out);
  Serial.print("tc2_out : ");Serial.println(tc2_out);
  Serial.println(" ");
/*
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  delay(1000);
  tc1_out = thermocouple1.readCelsius();
  tc2_out = thermocouple2.readCelsius();
  Serial.print("tc1_out : ");Serial.println(tc1_out);
  Serial.print("tc2_out : ");Serial.println(tc2_out);
  Serial.println(" ");

  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  delay(1000);
  tc1_out = thermocouple1.readCelsius();
  tc2_out = thermocouple2.readCelsius();
  Serial.print("tc1_out : ");Serial.println(tc1_out);
  Serial.print("tc2_out : ");Serial.println(tc2_out);
  Serial.println(" ");

  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  delay(1000);
  tc1_out = thermocouple1.readCelsius();
  tc2_out = thermocouple2.readCelsius();
  Serial.print("tc1_out : ");Serial.println(tc1_out);
  Serial.print("tc2_out : ");Serial.println(tc2_out);
  Serial.println(" ");*/
}

