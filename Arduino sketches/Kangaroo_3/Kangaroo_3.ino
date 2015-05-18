#include <SoftwareSerial.h>
 
int ticks = 663;
int rpm = 61, vel_units;
int increment = 1;
String vel;
unsigned long lastUpdateTime;
int heartBeatChar = '@';
int heartBeatTimeout = 500;

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  delay(2000);
  
  Serial.begin(9600);
  mySerial.begin(9600);
  
  mySerial.println("1,start");
  mySerial.println("1, units 1000 = 663");
  //Serial.println("1,home");
  
  mySerial.println("2,start");
  mySerial.println("2, units 1000 = 663");
  //Serial.println("2,home");
  delay(2000);
  
  mySerial.println("1, s200");
  mySerial.println("2, s200");
  delay(1000);
  
  mySerial.println("1, s-200");
  mySerial.println("2, s-200");
  delay(1000);
  
  mySerial.println("1, s0");
  mySerial.println("2, s0");
  delay(1000);
  
  lastUpdateTime = millis();
}

void loop() {
  
  if(Serial.available())
  {
    lastUpdateTime = millis();
    
    int firstChar = Serial.read();
    if(firstChar != heartBeatChar)
    {
      int leftSign = firstChar;
      int leftSpeed = Serial.parseInt();
      if(leftSign == '-')
        leftSpeed = -leftSpeed;
                
      int rightSign = Serial.read();
      int rightSpeed = Serial.parseInt();
      if(rightSign == '-')
        rightSpeed = -rightSpeed;
        
      //read char to skip
      Serial.read();
      
      mySerial.println(String("1, s") + leftSpeed);
      mySerial.println(String("2, s") + rightSpeed);
    }
  }
/* else
  {
      //windows program may have crashed...
      //stop the robot
      if(millis() - lastUpdateTime > heartBeatTimeout)
      {
        mySerial.println("1, s0");
        mySerial.println("2, s0");
      }
  }*/
}

