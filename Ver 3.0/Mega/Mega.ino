#include "Mega_defines.h"
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

void setup() {
  Serial.begin(9600);
  startNRFtransmitter();
  startLineFollowed();
}

void loop() {
  const char text[]="ngu";
  radio.write(&text, sizeof(text));
  delay(1000);
}