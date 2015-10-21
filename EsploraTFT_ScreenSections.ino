/*
 * Esplora TFT Screen Sections
 * Board: Arduino Esplora
 * This sketch is used to figure out how to divide the TFT
 * screen up into even sections.
 *
 * David Siver
 * CS 4985
 * Fall 2015
 */

#include <SPI.h>
#include <TFT.h>
#include <Esplora.h>

#define DEBUG 1
#define SERIAL_BAUD_RATE 9600
#define DELAY 250
#define NUM_COLUMNS 8
#define NUM_ROWS 6

int columnWidth, rowHeight;

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  EsploraTFT.begin();
  EsploraTFT.background(0, 0, 0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
