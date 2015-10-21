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
  columnWidth = EsploraTFT.width() / NUM_COLUMNS;
  rowHeight = EsploraTFT.height() / NUM_ROWS;
  delay(500);
  Serial.println("width: " + String(EsploraTFT.width()) + " height: " + String(EsploraTFT.height()));
  drawColumns();
}

/*
 * Stroke: EsploraTFT.stroke(red, green, blue);
 * Fill: EsploraTFT.fill(red, green, blue);
 * Lines: EsploraTFT.line(xStart, yStart, xEnd, yEnd);
 * Rect: EsploraTFT.rect(xStart, yStart, width, height);
 */
void drawColumns() {
  String xStarts = "";
  EsploraTFT.stroke(255, 255, 255);
  EsploraTFT.line(0, 0, 0, EsploraTFT.height());
  for (int i = columnWidth-1; i <= EsploraTFT.width(); i+=columnWidth) {
    xStarts += String(i) + " ";
    EsploraTFT.line(i, 0, i, EsploraTFT.height());
  }
  Serial.println("Column xStarts: " + xStarts);
}

void loop() {
  // put your main code here, to run repeatedly:

}
