
#include <NS_RainbowWrapper.h>
#include <NS_Rainbow.h>

#define PIN 9
#define N_CELL 64

NS_RainbowWrapper grid = NS_RainbowWrapper(N_CELL,PIN);
int flag = true;  
void setup() {
  Serial.begin(9600);
  delay(100);
  grid.NS_RainbowStarter();
  grid.setBrightness(10);
  grid.setRGB(100,0,100);  
  while(Serial.available() <= 0) // wait  for random input
    ;

}

void loop() {
    unsigned int   t = 100;   // t: delay time in miliseconds
    int row=1,col=1;
    while(row<=8)
    {
      col=1;
      while(col<=8)
      {
        if(flag == true)
          grid.lightLed(row,col);
        else
          grid.clearLed(row,col);
        grid.show();
        col++;
        delay(t);
      }  
      row++;
    }
    flag = !flag;    
}


