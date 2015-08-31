
#include <NS_RainbowWrapper.h>
#include <NS_Rainbow.h>

#define PIN 9
#define N_CELL 64

NS_RainbowWrapper grid = NS_RainbowWrapper(N_CELL,PIN);
  
void setup() {
  Serial.begin(9600);
  delay(100);
  grid.NS_RainbowStarter();
  grid.setBrightness(60);
  grid.setRGB(100,0,100); // set default color 
  while(Serial.available() <= 0) // wait  for random inputœ
    ;

}

void loop() {
   unsigned int   t = 100;   // t: delay time in miliseconds
    grid.clear();
    delay(t);
    grid.colorGrid();
    grid.show();
    delay(t);
}


