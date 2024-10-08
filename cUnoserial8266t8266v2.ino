#include <Wire.h> 

/////////// variable ESP8266 , Uno serial to ESP8266  ///////////
byte countr0 = 0 ;
int checkserial = 0 , reUno1 = 0 , seUno1 = 0 , ctime1 = 1 ;

void setup() {
Serial.begin(115200);
pinMode(D4, OUTPUT) ;
delay(500) ;
   Serial.print("Wait data from Uno");  
   Serial.print("\n");  
   delay(1000) ;
 ///// end void setup loop    
}

void loop() {
///////////////////  wait command wifi success //////////////    
  while ( countr0 < 1 ) {
    checkserial = Serial.available() ;   
   while ( checkserial > 0) /// While loop 1
  {
    int  reUno1 = Serial.parseInt();
   Serial.print(" reUno1 checkserial ");  
   Serial.print(reUno1);  
   Serial.print("\n");  
        Serial.println("Receive data from Uno read() ");
     if ( reUno1 == 1234 ){ //  if ( Serial.read() == '\n')
        countr0 = 5 ;
        digitalWrite(D4,HIGH) ;
   Serial.print(" Uno send data reUno1 is = ");  
   Serial.print(reUno1);  
   Serial.print("\n");   
    delay(1000) ;  
        checkserial = 0 ;  
        countr0 = 5 ;
        seUno1 = 2222 ;
  Serial.print("amount of receving 1234 and sending 2222= ") ;
  Serial.print(ctime1) ;
  Serial.print("\n") ;
    Serial.print("ESP8266 Send seUno1 = 2222 to Uno is ");
    Serial.println(seUno1); 
    delay(1000) ; // 100
    Serial.print(seUno1) ;
    Serial.print("\n") ;
  //  delay(100) ;
    Serial.flush(); 
    delay(100) ;
  digitalWrite(D4,LOW) ;
  ctime1++ ;
     }  ////// END   ( reUno1 == 1234 ) {

    }  //// END  while ( Serial.available() > 0)

  }  ////// END while ( countr0 < 1 ) //////////////
  countr0 = 0 ;
  delay(500) ;
 ////////////// end void loop  /////////////////
}

