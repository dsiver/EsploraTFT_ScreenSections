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
  delay(1000);
  Serial.println("EsploraTFT.width(): " + String(EsploraTFT.width()) + " EsploraTFT.height(): " + String(EsploraTFT.height()));
  Serial.println("columnWidth: " + String(columnWidth) + " rowHeight: " + String(rowHeight));
  EsploraTFT.stroke(255, 255, 255);
  drawColumns();
  drawRows();
}

/*
 * Stroke: EsploraTFT.stroke(red, green, blue);
 * Fill: EsploraTFT.fill(red, green, blue);
 * Lines: EsploraTFT.line(xStart, yStart, xEnd, yEnd);
 * Rect: EsploraTFT.rect(xStart, yStart, width, height);
 */
void drawColumns() {
  String xStarts = "";
  int columnEnd = EsploraTFT.height() - 2;
  EsploraTFT.line(0, 0, 0, columnEnd);
  for (int i = columnWidth - 1; i <= EsploraTFT.width(); i += columnWidth) {
    xStarts += String(i) + " ";
    EsploraTFT.line(i, 0, i, columnEnd);
  }
  Serial.println("Column xStarts: " + xStarts);
}

void drawRows() {
  String yStarts = "";
  EsploraTFT.line(0, 0, EsploraTFT.width(), 0);
  for (int i = rowHeight - 1; i <= EsploraTFT.height(); i += rowHeight) {
    yStarts += String(i) + " ";
    EsploraTFT.line(0, i, EsploraTFT.width(), i);
  }
  Serial.println("Column yStarts: " + yStarts);
}

void loop() {
  // put your main code here, to run repeatedly:

}
