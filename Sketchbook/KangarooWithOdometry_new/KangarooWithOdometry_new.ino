#include <AltSoftSerial.h>

int ticks = 1856;
int rpm = 61, vel_units;
int increment = 1;
String vel;
unsigned long lastUpdateTime;
int heartBeatChar = '@';
int heartBeatTimeout = 500;
//bool flag=false;
int midBoundary = 16384;
bool useOdometry = true; // TRUE IF USING ODOMETRY!

int lastLeftPosition = 0;
int currentLeftPosition = 0;
int lastRightPosition = 0;

int leftWheelLastUpdate = 0;
int rightWheelLastUpdate = 0;
int updateOdometryDelta = 50;

AltSoftSerial mySerial; // RX, TX
//now		-> yellow in 8, green in 9
//before	-> yellow was in 10 - RX, green was in 11 - TX

void setup() {
  delay(300); 
  Serial.begin(9600);
  delay(300);
  mySerial.begin(9600);
  delay(300);
  
  mySerial.println("1,start");
  mySerial.println("1, units 1000 = 480");
  //mySerial.println("1,powerdown");
  
  mySerial.println("2,start");
  mySerial.println("2, units 1000 = 480");
  //mySerial.println("2,powerdown");
  //delay(2000);
  /*
  mySerial.println("1, s200");
  mySerial.println("2, s200");
  delay(1000);
  
  mySerial.println("1, s-200");
  mySerial.println("2, s-200");
  delay(1000);
  
  mySerial.println("1, s0");
  mySerial.println("2, s0");
  delay(1000);
  */
  //mySerial.println("1,getp");
  
  lastUpdateTime = millis();
  if(useOdometry)
  {
    leftWheelLastUpdate = lastUpdateTime;
    rightWheelLastUpdate = leftWheelLastUpdate + 6;
  }
}


int GetIncrement(int oldPosition, int newPosition)
 {
   int absoluteNewPosition = abs(newPosition);
   if(absoluteNewPosition < midBoundary || oldPosition > 0 && newPosition > 0 || oldPosition < 0 && newPosition < 0)
     return newPosition - oldPosition;
   //-32768 to 32767 (negative move) or 32767 to -32768 (positive move)
   else
   {
     //(32768 - abs(oldPosition)) +  (32768 - abs(newPosition))
     int res = 65536 - abs(oldPosition) - absoluteNewPosition;
     return newPosition < 0 ? res : -res;
   }
 }


void loop() {

  
if(useOdometry)
{
  
  String odometryData;
  
  int currentTime = millis();
if(currentTime - leftWheelLastUpdate > updateOdometryDelta)
{
  mySerial.println("1,getp");
  leftWheelLastUpdate = currentTime;
}
if(currentTime - rightWheelLastUpdate > updateOdometryDelta)
{
  mySerial.println("2,getp");
  rightWheelLastUpdate = currentTime;
}


if(mySerial.available() > 0)
{
  char motor = mySerial.read();
  
  delay(2);
  //read comma
  char comma = mySerial.read();
  //read letter
  delay(2);
  char c = mySerial.read();
  
  //delay(6);
  int number = mySerial.parseInt();
  
  //Serial.println(motor);
  //Serial.println(comma);
   //Serial.println(c);
    //Serial.println(String(number));
    
    if(c == 'P' || c == 'p')
    { 
      if(motor == '1')
      {
        ////Serial.println(millis() - leftWheelUpdateMillis);
        //leftWheelUpdateMillis = millis();
        
        lastLeftPosition = currentLeftPosition;
        currentLeftPosition = number;
      }
      else if(motor == '2')
      {
        Serial.print(String(millis()) + String(" ") + String(GetIncrement(lastLeftPosition, currentLeftPosition)) + '*' + String(GetIncrement(lastRightPosition, number)) + '\n');
        //Serial.print(" @ " + String(currentLeftPosition) + '*' + String(number) + '\n');
        
        //long curr = millis();
        //Serial.println(curr - leftWheelUpdateMillis);
        lastRightPosition = number;
      }
    }

    while(c != '\n')
    {
      c = mySerial.read();
      //delay(2);
    }
 }
}
//
//Serial.println('-');
//


  //receives and sends motor commands
  if(Serial.available() > 0)
  {
    //test
//Serial.println("yeah");
//
    
    
    lastUpdateTime = millis();
    
    int firstChar = Serial.read();
//test
//Serial.print(firstChar);
//
    if(firstChar != heartBeatChar)
    {
      if(firstChar == '+' || firstChar == '-')
      {
        int leftSign = firstChar;
        int leftSpeed = Serial.parseInt();
//test
//Serial.print(leftSpeed);
//
        if(leftSign == '-')
          leftSpeed = -leftSpeed;
      
        int rightSign = Serial.read();
//test
//Serial.print(rightSign);
//
        int rightSpeed = Serial.parseInt();
//test
//Serial.print(rightSpeed);
//
        if(rightSign == '-')
          rightSpeed = -rightSpeed;
          
        //read char to skip
        int charIn;
      
          Serial.readString();
        
        mySerial.println(String("1, s") + leftSpeed);
        mySerial.println(String("2, s") + rightSpeed);
      }
      else
        while(firstChar != '\n' && firstChar > 0)
          firstChar = mySerial.read();
    }
    else
      lastUpdateTime = millis();
  }
  // with this code, motors stopped initially
/*  else
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

