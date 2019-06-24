#include "Wire.h"
#include <SharpIR.h>
#include <Servo.h>
#define ir A0
#define SERVO 4
#define model 1080
SharpIR SharpIR(ir, model); 
Servo s; // Variável Servo
int pos; // Posição Servo
int fire=0;
void setup() {
  s.attach(SERVO);
  s.write(30);
  Serial.begin(9600);
  Wire.begin(0x10); 
 Wire.onRequest(requestEvent); 
 Wire.onReceive(Receive);

}

void loop() { 
      if(fire==0){
       for(pos = 30; pos < 135; pos++)
  {
    s.write(pos);
  delay(15);
  }
delay(1000);
  for(pos = 135; pos >= 30; pos--)
  {
    s.write(pos);
    delay(15);  }
  }
   else if(fire == 1){
     s.write(20);
   }
   else if(fire ==2)
   s.write(160);
}

void requestEvent() { 
int distancia = SharpIR.distance();  
    Wire.write(distancia);  
   
}

void Receive() { 
     fire = Wire.read();
     Serial.println(fire);
  }
