void setup() {
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial.begin(9600);

}



void loop() {
  
 if(Serial2.available()){
  // String p = Serial2.readString();
   String x = Serial2.readStringUntil('X');
   String y = Serial2.readStringUntil('Y');
  // int xa = p.indexOf('X');
 //  int ya = p.indexOf('Y');
    
  //  String b = Serial2.readStringUntil('B');
   String x1 ;
   String y1 ; 
   x1.concat(x[23]);
   x1.concat(x[24]);
   x1.concat(x[25]);
   x1.concat('X');
   y1.concat(y[20]);
   y1.concat(y[21]);
   y1.concat(y[22]);
   y1.concat('Y');
   Serial1.println(y1);
   Serial1.println(x1);
   Serial.println(y1);
   Serial.println(x1);
 }
 
}
