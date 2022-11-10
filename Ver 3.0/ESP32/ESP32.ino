#include "ESP32_defines.h"
#include <QTRSensors.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(NRF_CE, NRF_CSN); // CE, CSN

const byte address[6] = "13245";

void startNRFtransmitter(){
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void joystickSetup(){
  pinMode(joystickX, INPUT);
  pinMode(joystickY, INPUT);
  pinMode(joystickSwitch, INPUT);
}

void setup() {
  Serial.begin(9600);
  startNRFtransmitter();
  joystickSetup();
}

void readJoy(){
  int valx = analogRead(joystickX);
  int valy = analogRead(joystickY);
  int joySwitch = digitalRead(joystickSwitch);
  Serial.print(valx);Serial.print("  ");
  Serial.print(valy);Serial.print("  ");
  Serial.println(joySwitch);
  delay(1000);
}

void sendNRF(){
  const char text[]="ngu";
  radio.write(&text, sizeof(text));
  delay(1000);
}

void loop() {
  readJoy();
  sendNRF();
}