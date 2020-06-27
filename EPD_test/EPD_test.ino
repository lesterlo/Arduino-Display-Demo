/**
 * A Demo of Arduino E-paper display (EPD)
 * 
 * Using SPI connection
 * 
 * See the README.md for more detail information.
 * 
 */
 
#include "message.h"
#include "Adafruit_EPD.h"

//Define program parameter
#define DELAY_CONST 2000
#define GRID_SEPERATION 8

//Define the PIN number
#define EPD_CS      53
#define EPD_DC      9
#define SRAM_CS     -1 //Some diplay don't have SRAM_CS Pin, set it to -1
#define EPD_RESET   5 // can set to -1 and share with microcontroller Reset!
#define EPD_BUSY    7 // can set to -1 to not use a pin (will wait a fixed delay)


// Adafruit_EPD library class

/* Uncomment the following line if you are using 1.54" tricolor EPD */
//Adafruit_IL0373 display(152, 152, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);

/* Uncomment the following line if you are using 1.54" monochrome EPD */
Adafruit_SSD1608 display(200, 200, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);

/* Uncomment the following line if you are using 2.13" tricolor EPD */
//Adafruit_IL0373 display(212, 104, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);
//#define FLEXIBLE_213

/* Uncomment the following line if you are using 2.13" monochrome 250*122 EPD */
//Adafruit_SSD1675 display(250, 122, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);

/* Uncomment the following line if you are using 2.7" tricolor or grayscale EPD */
//Adafruit_IL91874 display(264, 176, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS);

/* Uncomment the following line if you are using 2.9" EPD */
//Adafruit_IL0373 display(296, 128, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);
//#define FLEXIBLE_290

/* Uncomment the following line if you are using 4.2" tricolor EPD */
//Adafruit_IL0398 display(300, 400, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);

//Define the EPD_COLOR 
#define COLOR1 EPD_BLACK
#define COLOR2 EPD_GRAY
#define COLOR3 EPD_WHITE

//Some of the display only support Black and White color, no mid-gray color



void setup() {

  display.begin(); // Start the EPD Library


//A Flexible display handling
#if defined(FLEXIBLE_213) || defined(FLEXIBLE_290)
  // The flexible displays have different buffers and invert settings!
  display.setBlackBuffer(1, false);
  display.setColorBuffer(1, false);
#endif

// Display a 5x Font Size demo
  display.clearBuffer();
  display.setCursor(0, 0);
  display.setTextColor(COLOR1);
  display.setTextSize(5);
  display.setTextWrap(true);
  display.print(MESSAGE_1);
  display.display();


  // Display Full screen size picture demo
  delay(DELAY_CONST);
  display.clearBuffer(); //Clear the diplay
  for (int16_t i=0; i<display.width(); i+=4) 
  {
    display.drawLine(0, 0, i, display.height()-1, COLOR1);
  }

  for (int16_t i=0; i<display.height(); i+=4) 
  {
    display.drawLine(display.width()-1, 0, 0, i, COLOR2);  // on grayscale this will be mid-gray
  }
  display.display();



  // Display Another picture demo
  delay(DELAY_CONST);
  display.clearBuffer(); //Clear the diplay
  for (int16_t i=0; i<display.width(); i+=GRID_SEPERATION) 
  {
      display.drawLine(i, 0, i, display.height(), COLOR1);
  }
  display.display();
  //Don't erase the buffer
  delay(DELAY_CONST);
  for (int16_t i=0; i<display.height(); i+=GRID_SEPERATION) 
  {
      display.drawLine(0, i, display.width(), i, COLOR1);
  }
  display.display();


  delay(DELAY_CONST);
  // Display A 5x Font Size demo
  display.clearBuffer();
  display.setCursor(0, 0);
  display.setTextColor(COLOR1);
  display.setTextSize(5);
  display.setTextWrap(true);
  display.print(MESSAGE_2);

  display.setCursor(0, 50);
  display.setTextColor(COLOR1);
  display.setTextSize(2);
  display.setTextWrap(true);
  display.print(MESSAGE_3);

  display.setCursor(0, 100);
  display.setTextColor(COLOR1);
  display.setTextSize(1);
  display.setTextWrap(true);
  display.print(MESSAGE_4);

  display.display();

}

void loop() 
{
  //don't do anything!
}
