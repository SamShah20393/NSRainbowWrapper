
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
       int length;
       int height;
       Serial.write("Length:");
       while(Serial.available() <= 0) // wait  for random input
        ;      
       length = Serial.read();
       length = length - 48;
       Serial.write("Length ="+length);
       Serial.write("Height:");
       while(Serial.available() <= 0) // wait  for random input
        ;      
       height = Serial.read();
       height = height - 48;
       Serial.write("Height ="+height);
       
       grid.clear();
       delay(t);
       grid.colorBoxPoints(1,1,length,height);
       grid.show();
       
      
      
}


