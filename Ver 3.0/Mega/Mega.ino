#include "Mega_defines.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(NRF_CE, NRF_CSN); // CE, CSN

const byte address[6] = "13245";

void startNRFreceiver(){
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void startLineFollowed(){

}

void setup() {
  Serial.begin(9600);
  startNRFreceiver();
  startLineFollowed();

}

void readNRF(){
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}

void loop() {
  readNRF();
}