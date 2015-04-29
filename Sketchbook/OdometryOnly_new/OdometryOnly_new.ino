#include <AltSoftSerial.h>

int ticks = 663;
int rpm = 61, vel_units;
int increment = 1;
String vel;
unsigned long lastUpdateTime, newUpdateTime;
int delta=0;
int heartBeatChar = '@';
int heartBeatTimeout = 500;

int lastLeftPosition = 0;
int currentLeftPosition = 0;
int lastRightPosition = 0;

int leftWheelLastUpdate = 0;
int rightWheelLastUpdate = 0;
int updateOdometryDelta = 75;

//String odometryData;

int midBoundary = 16384;

long leftWheelUpdateMillis = 0;

bool flag=false;

AltSoftSerial mySerial; // RX, TX
//now		-> yellow in 8, green in 9
//before	-> yellow was in 10 - RX, green was in 11 - TX


int lastChangeSpeed;
long count=0;

void setup() {
  //delay(2000);

  delay(200);  
  Serial.begin(9600);
  delay(300);
  mySerial.begin(9600);
  delay(200);
    
  mySerial.println("1,start");
  mySerial.println("1, units 1000 = 480");
  //mySerial.println("1,home");
  
  mySerial.println("2,start");
  mySerial.println("2, units 1000 = 480");
  //mySerial.println("2,home");
  
  //Serial.println("2,home");
  /*delay(2000);
  
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
//mySerial.println("1,s300");
//mySerial.println("2,s300");
  //mySerial.println("1, s100\n2, s100\n1, s200");
  
  //mySerial.println("1,getpi");
  //delay(30);
  //mySerial.println("2,getpi");
  
  lastUpdateTime = millis();
  leftWheelLastUpdate = millis();
  rightWheelLastUpdate = leftWheelLastUpdate + 6;
  
  lastChangeSpeed = millis();
  
  mySerial.println("1,s1000");
  mySerial.println("2,s2000");
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
  
  int now = millis();
  /*
  if(now - lastChangeSpeed > 500)
  {
    if(flag)
    {
      mySerial.println("1,s-800");
      mySerial.println("2,s-800");
    }
    else
    {
      mySerial.println("1,s-500");
      mySerial.println("2,s-500");
    }
    flag = !flag;
    lastChangeSpeed = now;
  }*/
  
  String odometryData;
  /*odometryData += '1';
  /*
  odometryData += ',';
  odometryData += 'p';
  odometryData += '1';
  odometryData += '9';
  odometryData += '2';
  odometryData += '\r';
  odometryData += '\n';*/
/*
  for(int i = 0 ; i < odometryData.length() ; i++)
  {
    int received = odometryData[i];
    
    if (received == '\n')
    {
        //odometryData += received;
        Serial.println(odometryData);
	//read newline
	//mySerial.read();
        //odometryData = ""; // Clear received buffer
    }
    else
      odometryData2 += received;
    
  }*/
  
 
  /*
  while (mySerial.available() > 0)
  {
    String data;
    int received = mySerial.read();
    data += received;
    Serial.println(data);
  }
  */
  
  /*
  if(mySerial.available() > 0)
  {
    delay(20);
    if(!flag)
          mySerial.println("1,getpi");
        else
          mySerial.println("2,getpi");
          
    flag = !flag;
    
    char motor = mySerial.read();
    
    //read comma
    mySerial.read();
    //read letter
    char c = mySerial.read();
    
    int number = mySerial.parseInt();
    
    Serial.println(motor);
    //Serial.println("char: " + c);
    //Serial.println("number: " + number);
    
    
    if(c == 'P' || c == 'p')
    {
      if(motor == '1')
      {
        currentLeftPosition = number - lastLeftPosition;
        lastLeftPosition = number;
      }
      else if(motor == '2')
      {
        Serial.println('l' + String(currentLeftPosition)+ 'r' + String(number - lastRightPosition));
        lastRightPosition = number;
      }
    }
  }
*/


/************* GOOD STUFF ******************/
/*
  if(mySerial.available() > 0)
  {
    if(flag)
          mySerial.println("1,getpi");
        else
          mySerial.println("2,getpi");
          
    flag = !flag;
  }

  bool isRunning = false;
  do
  {
    if (mySerial.available() > 0)
    {
      isRunning = true;
      char received = mySerial.read();
      
      if (received == '\n')
      {
          Serial.println(millis() - lastUpdateTime);
          lastUpdateTime = millis();
  
          Serial.println(odometryData);
          isRunning = false;
      }
      else
        odometryData += received;
      
      //todo: try less delay!
      //delay(2);
    }
    else{//Serial.println("boom");
      delay(1);}
  }
  while(isRunning);
  */
 
/*******************************************/

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
        
        Serial.print(String(millis()) + String(" ") + String(count) + String(" ") + String(GetIncrement(lastLeftPosition, currentLeftPosition)) + '*' + String(GetIncrement(lastRightPosition, number)) /*+ '\n'*/);
        Serial.print(" @ " + String(currentLeftPosition) + '*' + String(number) + '\n');
        
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

 count=count+1;
  //odometry query
/*
  if(!flag)
    mySerial.println("1,getpi");
  //delay(1);
  else
  mySerial.println("2,getpi");
  //delay(1);
  
  flag=!flag;
  
    newUpdateTime = millis();
    delta=newUpdateTime-lastUpdateTime;
      
  if(delta<20)
     delay(20-delta);
     
  lastUpdateTime = millis();
  Serial.println(delta);
 */   
    /*
   int now = millis();
  if(now - lastUpdateTime > 500)
  {
    //Serial.println(now - lastUpdateTime);
    //mySerial.println("1,getp\r\n2,getp");
    mySerial.println("1,getpi");
    mySerial.println("2,getpi");
    lastUpdateTime = millis();
  }
    */
    
    
    
  /*
  //receives and sends motor commands
  if(Serial.available() > 0)
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
  else
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

