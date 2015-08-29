/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "Arduino.h"
#include "NS_RainbowWrapper.h"
#include <NS_Rainbow.h>

class box
{
  public:
    int startRow,endRow,startCol,endCol; // x = left most x; X = right most X
    int midRow,midCol;
    int length;
    int halfLength;
    int height;
    int halfHeight;
  public: box(int x,int y,int length,int height)
  {
    this->startRow = x;
    this->startCol = y;

    this->endRow = this->startRow + height - 1;
    this->midRow = (this->startRow + this->endRow)/2;

    this->endCol = this->startCol + length - 1;
    this->midCol = (this->startCol + this->endCol)/2;

    this->length = length;
    this->halfLength = length/2;

    this->height = height;
    this->halfHeight = height/2;
  }
};


NS_RainbowWrapper::NS_RainbowWrapper(int N_CELL,int PIN) // Initializes the matrix
{
  ns_matrix = new NS_Rainbow(N_CELL,PIN);
}

void NS_RainbowWrapper::NS_RainbowStarter()
{
  ns_matrix->begin();
  ns_matrix->clear();
  ns_matrix->show();
}

void NS_RainbowWrapper::setBrightness(int brightness)
{
  ns_matrix->setBrightness(brightness);
}

void NS_RainbowWrapper::clear()
{
  ns_matrix->clear();
  ns_matrix->show();
}

void NS_RainbowWrapper::show()
{
  ns_matrix->show();
}

void NS_RainbowWrapper::setRGB(int red,int green,int blue)
{
  this->red=red;
  this->green=green;
  this->blue=blue;
}

int NS_RainbowWrapper::getLed(int row,int column)
{
  return((((row-1)*8)+column)-1);
}

void NS_RainbowWrapper::clearLed(int row,int column)
{
  int LED = getLed(row,column);
  ns_matrix->setColor(LED,0,0,0);
}

void NS_RainbowWrapper::lightLed(int row,int column)
{
  int LED = getLed(row,column);
  ns_matrix->setColor(LED,red,green,blue);
}

void NS_RainbowWrapper::redLed(int row,int column)
{
  int LED = getLed(row,column);
  ns_matrix->setColor(LED,255,0,0);
}

void NS_RainbowWrapper::greenLed(int row,int column)
{
  int LED = getLed(row,column);
  ns_matrix->setColor(LED,0,255,0);
}

void NS_RainbowWrapper::blueLed(int row,int column)
{
  int LED = getLed(row,column);
  ns_matrix->setColor(LED,0,0,255);
}

void NS_RainbowWrapper::colorLed(int row,int column)
{
  int LED = getLed(row,column);
  ns_matrix->setColor(LED,red,green,blue);
}

void NS_RainbowWrapper::colorGrid()
{
  int row=1,column=1;
  while(row<=8)
  {
    column=1;
    while(column<=8)
    {
      colorLed(row,column);
      column++;
    }
    row++;
  }
}


void NS_RainbowWrapper::colorVerticalLine(int row,int column,int height)
{
  int max_row = row + height;
  while(row<max_row)
  {
    colorLed(row,column);
    row = row+1;
  }
}

void NS_RainbowWrapper::colorHorizontalLine(int row,int column,int length)
{
  int max_column = column + length;
  while(column<max_column)
  {
    colorLed(row,column);
    column++;
  }
}

void NS_RainbowWrapper::colorFrontSlash(int row,int column,int length,int height)
{
  int max_column = column + length;
  int max_row = row + height;
  while(column<max_column || row<max_row)
  {
    colorLed(row,column);
    if(column<max_column)
      column++;
    if(row<max_row)
      row++;
  }
}

void NS_RainbowWrapper::colorBackSlash(int row,int column,int length,int height)
{
  int min_column = column - length;
  int max_row = row + height;
  while(column>min_column || row<max_row)
  {
    colorLed(row,column);
    if(column>min_column)
      column--;
    if(row<max_row)
      row++;
  }
}

void NS_RainbowWrapper::colorLine(int startRow,int startCol,int endRow,int endCol)
{
  int row = startRow;
  int col = startCol;
  while(1)
  {
    colorLed(row,col);
    if(startRow<=endRow && startCol<=endCol)
    {
      if(row<endRow || col<endCol)
      {
        if(row<endRow)
          row++;
        if(col<endCol)
          col++;
      }
      else
        break;
    }
    else if(startRow<=endRow && startCol>=endCol)
    {
      if(row<endRow || col>endCol)
      {
        if(row<endRow)
          row++;
        if(col>endCol)
          col--;
      }
      else
        break;
    }
    else if(startRow>=endRow && startCol<=endCol)
    {
      if(row>endRow || col<endCol)
      {
        if(row>endRow)
          row--;
        if(col<endCol)
          col++;
      }
      else
        break;
    }
    else if(startRow>=endRow && startCol>=endCol)
    {
      if(row>endRow || col>endCol)
      {
        if(row>endRow)
          row--;
        if(col>endCol)
          col--;
      }
      else
        break;
    }

  }
}

void NS_RainbowWrapper::colorBoxPoints(int row,int column,int length,int height)
{
  box b(row,column,length,height);
  colorLed(b.startRow,b.startCol);
  colorLed(b.endRow,b.startCol);
  colorLed(b.startRow,b.endCol);
  colorLed(b.endRow,b.endCol);
  colorLed(b.midRow,b.startCol);
  colorLed(b.midRow,b.endCol);
  colorLed(b.startRow,b.midCol);
  colorLed(b.endRow,b.midCol);

}
void NS_RainbowWrapper::colorA(int row,int column,int length,int height)
{

  int midRow = row + (height/2);
  int midColumn = column + (length/2);
  colorVerticalLine(row+1,column,height-1);
  colorHorizontalLine(row,column+1,length-2);
  colorVerticalLine(row+1,column+length-1,height-1);
  colorHorizontalLine(midRow,column,length);
}

void NS_RainbowWrapper::colorb(int row,int column,int length,int height)
{
  box b(row,column,length,height);
  colorVerticalLine(b.startRow,b.startCol,b.height);
  colorHorizontalLine(b.midRow,b.startCol,b.length);
  colorVerticalLine(b.midRow,b.endCol,b.halfHeight);
  colorHorizontalLine(b.endRow,b.startCol,b.length);
}

void NS_RainbowWrapper::colorC(int row,int column,int length,int height)
{
  box b(row,column,length,height);
  colorHorizontalLine(b.startRow,b.startCol,b.length);
  colorVerticalLine(b.startRow,b.startCol,b.height);
  colorHorizontalLine(b.endRow,b.startCol,b.length);

}

void NS_RainbowWrapper::colord(int row,int column,int length,int height)
{
  box b(row,column,length,height);
  colorVerticalLine(b.startRow,b.endCol,b.height);
  colorHorizontalLine(b.midRow,b.startCol,b.length);
  colorVerticalLine(b.midRow,b.startCol,b.halfHeight);
  colorHorizontalLine(b.endRow,b.startCol,b.length);
}

/*void NS_RainbowWrapper::colore(int row,int column,int length,int height)
{
  box b(row,column,length,height);
  colorVerticalLine(b.startRow,b.endCol,b.height);
  colorHorizontalLine(b.midRow,b.startCol,b.length);
  colorVerticalLine(b.midRow,b.startCol,b.halfHeight);
  colorHorizontalLine(b.endRow,b.startCol,b.length);
}*/

void NS_RainbowWrapper::colorP(int row,int column,int length,int height)
{
  box b(row,column,length,height);
  colorVerticalLine(b.startRow,b.startCol,b.height);
  colorHorizontalLine(b.startRow,b.startCol,b.length);
  colorVerticalLine(b.startRow,b.endCol,b.halfHeight);
  colorHorizontalLine(b.midRow,b.startCol,b.length);
}



void NS_RainbowWrapper::colorH(int row,int column,int length,int height)
{
  box b(row,column,length,height);
  colorVerticalLine(b.startRow,b.startCol,b.height);
  colorHorizontalLine(b.midRow,b.startCol,b.length);
  colorVerticalLine(b.startRow,b.endCol,b.height);
}

void NS_RainbowWrapper::colorY(int row,int column,int length,int height)
{
  box b(row,column,length,height);
  colorLine(b.startRow,b.startCol,b.midRow+1,b.midCol);
  colorLine(b.startRow,b.endCol,b.midRow+1,b.midCol);
  colorVerticalLine(b.midRow+1,b.midCol,b.halfHeight);
}


