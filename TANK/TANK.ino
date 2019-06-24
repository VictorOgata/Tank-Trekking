#include<Wire.h>    
#include<SoftWire.h> 
#include <HardwareSerial.h>
extern struct usart_dev *USART3;
String y,x;
HardwareSerial Serial3(USART3,PB10,PB11);
char c; 
int ifl,ifr,lw,rw,a,aux=0,touch=0;
void atk(){
  if(rw==0 || ifr==0){
    aux=1;
   Wire.beginTransmission(0x10);   
    Wire.write(aux);
    Wire.endTransmission();
  }
  else if(lw==0 || ifl==0 ){
     aux=2;
   Wire.beginTransmission(0x10);   
    Wire.write(aux);
    Wire.endTransmission();
  }
  delay(2000);
  aux=0;
  Wire.beginTransmission(0x10);   
    Wire.write(aux);
    Wire.endTransmission();
  }

void checksensor(){
  touch = digitalRead(PA15);
       lw = digitalRead(PA6);
    rw = digitalRead(PA3);
   ifl = digitalRead(PA7);
   ifr = digitalRead(PB0);
}

void checkwire(){
 Wire.requestFrom(0x10,3);               
    a = Wire.read(); 
}

void setup() {
   Wire.begin(0x9);  
  Serial.begin(9600);
   Serial3.begin(9600); 
   pinMode(PA11, OUTPUT);
  pinMode(PA12, OUTPUT);
  pinMode(PB12, OUTPUT);
   pinMode(PB13, OUTPUT);
  pinMode(PB8, OUTPUT);
  pinMode(PB9, OUTPUT);
  pinMode(PB0, INPUT);
  pinMode(PA7, INPUT);
   pinMode(PA3, INPUT);
  pinMode(PA6, INPUT);
  pinMode(PA15, INPUT);
  

}
void Stop(){
   digitalWrite(PA11,LOW);
  digitalWrite(PA12,LOW);
  digitalWrite(PB12,LOW);
  digitalWrite(PB13,LOW);
   analogWrite(PB8,0);
   analogWrite(PB9,0);
  
}

void Forward(int POT){
   digitalWrite(PA11,HIGH);
  digitalWrite(PA12,LOW);
  digitalWrite(PB12,HIGH);
  digitalWrite(PB13,LOW);
   analogWrite(PB8,POT);
   analogWrite(PB9,POT);
}

void Backwards(int POT){
   digitalWrite(PA11,LOW);
  digitalWrite(PA12,HIGH);
  digitalWrite(PB12,LOW);
  digitalWrite(PB13,HIGH);
  analogWrite(PB8,POT);
   analogWrite(PB9,POT);
}

void Left(int POT){
   analogWrite(PB8,POT);
   analogWrite(PB9,POT);
   digitalWrite(PA11,LOW);
  digitalWrite(PA12,HIGH);
  digitalWrite(PB12,HIGH);
  digitalWrite(PB13,LOW);
}

void Right(int POT){
   analogWrite(PB8,POT);
   analogWrite(PB9,POT);
   digitalWrite(PA11,HIGH);
  digitalWrite(PA12,LOW);
  digitalWrite(PB12,LOW);
  digitalWrite(PB13,HIGH);
}

void checkxy(){
    if(Serial3.available()){
    x = "";
    y = "";
   y = Serial3.readStringUntil('Y'); 
    delay(100);
   x = Serial3.readStringUntil('X');
   Serial.println(x);
   Serial.println(y);
  }
}

void loop() {
  int i;
 // Serial.println("teste:\n");
//   checksensor();
 checkxy();
 //  checkwire();
      if(x.toInt()<100){
       Serial.println("LEFT"); 
       Left(y.toInt());
      }
      else if(x.toInt()>150){
        Serial.println("right"); 
       Right(x.toInt());}
       else if(y.toInt()<100){
        Serial.println("for"); 
        Forward(y.toInt());
       }
       else if(y.toInt()>150) {
        Serial.println("back"); 
         Backwards(y.toInt());}
         else{  Stop(); Serial.println("Stop"); }
         
/*    if(a<11){ 
       touch = digitalRead(PA15);
     if(touch==1){
        Stop();
        for(i=0;i<150;i++){ 
        Backwards();
        }
        if(lw==1){
        for(i=0;i<150;i++)
        Left();}
        else{
          for(i=0;i<150;i++)
        Right();     
        }
     }
     else if((ifr==0 && ifl==1) ||(rw==0 && lw==1)){
        Stop();
        Left();
        atk();}
     else if((ifr==1 && ifl==0) ||(rw==1 && lw==0)){
        Stop();
        Right();
        atk();}
     else if((ifr==0 && ifl==0) ){
        Stop();
        Backwards();         }
  }
    else {Stop();Forward();}*/
}
