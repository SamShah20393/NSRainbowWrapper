/*
  NS_Rainbow wrapper
  NS_RainbowWrapper.h
*/
#ifndef NS_RainbowWrapper_h
#define NS_RainbowWrapper_h

#include "Arduino.h"
#include <NS_Rainbow.h>

class NS_RainbowWrapper
{
  public:
    NS_RainbowWrapper(int,int);
    void NS_RainbowStarter();
    void setBrightness(int);
    void clear();
    void show();
    int getLed(int row,int column);
    void clearLed(int row,int column); // Turns off the LED with black color
    void lightLed(int row,int column); // Turn on the LED with white light
    void redLed(int row,int column);  // Turn on the LED with Red
    void greenLed(int row,int column);  // Turn on the LED with Green
    void blueLed(int row,int column); // Turn on the LED with Blue
    void setRGB(int red,int green,int blue); // sets default color RGB
    void colorLed(int row,int column);
    void colorGrid();
    void colorVerticalLine(int row,int column,int length);
    void colorHorizontalLine(int row,int column,int length);
    void colorFrontSlash(int row,int column,int length,int height);
    void colorBackSlash(int row,int column,int length,int height);
    void colorBoxPoints(int row,int column,int length,int height);

    /* characater Wrapper */
    void colorA(int row,int column,int length,int height);
    void colorb(int row,int column,int length,int height);
    void colorC(int row,int column,int length,int height);
    void colord(int row,int column,int length,int height);
    void colorP(int row,int column,int length,int height);
    void colorH(int row,int column,int length,int height);
    void colorY(int row,int column,int length,int height);
    void colorLine(int startRow,int startCol,int endRow,int endCol);

  private:
    NS_Rainbow *ns_matrix;
    int red;
    int green;
    int blue;
};

#endif
