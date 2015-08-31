
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
  

}

void loop() {
       int t = 100;
       Serial.write("\nDraw what (A-Z):");
       while(Serial.available() <= 0) // wait  for random input
        ;
       int whichLine = Serial.read();
       Serial.print("\nDraw :");
       Serial.write(whichLine);
       
       Serial.write("\nWhat Length:");
       while(Serial.available() <= 0) // wait  for random input
        ;
       int length = Serial.parseInt();
       Serial.print("\nLength ");
       Serial.print(length);
       
       Serial.write("\nWhat Height:");
       while(Serial.available() <= 0) // wait  for random input
        ;
       int height = Serial.parseInt();
       Serial.print("\nHeight ");
       Serial.print(height);
       
       
       switch (whichLine)
       {
        case 'A':grid.clear();
                 delay(100); 
                 grid.colorA(1,1,length,height);
                 grid.show();
                 break;
        case 'B':grid.clear();
                 delay(100); 
                 grid.colorb(1,1,length,height);
                 grid.show();
                 break; 
        case 'C':grid.clear();
                 delay(100); 
                 grid.colorC(1,1,length,height);
                 grid.show();
                 break;
        case 'D':grid.clear();
                 delay(100); 
                 grid.colord(1,1,length,height);
                 grid.show();
                 break;
        case 'P':grid.clear();
                 delay(100); 
                 grid.colorP(1,1,length,height);
                 grid.show();
                 break;
                      
        case 'H':grid.clear();
                 delay(100); 
                 grid.colorH(1,1,length,height);
                 grid.show();
                 break; 
        case 'Y':grid.clear();
                 delay(100); 
                 grid.colorY(1,1,length,height);
                 grid.show();
                 break;   
         case '1':grid.clear();
                 delay(100); 
                 grid.colorLine(1,1,5,4);
                 grid.show();
                 break;                    
                                
       }
}


