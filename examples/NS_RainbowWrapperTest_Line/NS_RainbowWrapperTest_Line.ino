
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
  grid.setBrightness(60);
  grid.setRGB(100,0,100);  
  

}

void loop() {
       int t = 100;
       while(Serial.available() <= 0) // wait  for random input
        ;
       int whichLine = Serial.read();
       Serial.write(whichLine);
       switch (whichLine)
       {
        case '1':grid.clear();
                 delay(100); 
                 grid.colorVerticalLine(1,1,3);
                 grid.show();
                 break;
        case '2':grid.clear();
                 delay(100); 
                 grid.colorHorizontalLine(1,1,3);
                 grid.show();
                 break; 
        case '3':grid.clear();
                 delay(100); 
                 grid.colorFrontSlash(1,1,3,3);
                 grid.show();
                 break;
        case '4':grid.clear();
                 delay(100); 
                 grid.colorBackSlash(1,3,3,3);
                 grid.show();
                 break;
       }
}


