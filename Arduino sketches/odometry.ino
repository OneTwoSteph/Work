/*
 Software serial communication for odometry communication.
 
 ??
 
 RX = receiving pin
 TX = transmitting pin
 
 The circuit:
 * RX is digital pin 10 (connect to TX of motors)
 * TX is digital pin 11 (connect to RX of motors)
 
 String format of odometry sent:
 ?? 
 
 */

/**** Libraries ****/
// Library for serial communication (UART) which allows to replicate the functionality
// of UART of pin 0 and 1 on other pins of the board to allowa communication with them.
#include <SoftwareSerial.h>

/**** Global variables and parameters ****/
SoftwareSerial mySerial(10, 11);            // SoftwareSerial object for motors: RX, TX

int ticks = 1856;                           // number of ticks per wheel revolution  
int rpm = 61, vel_units;                    // ??
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
int updateOdometryDelta = 75;               // sample time for odometry [ms]

int midBoundary = 16384;

long leftWheelUpdateMillis = 0;

bool flag = false;

int lastChangeSpeed;

//String odometryData;
//AltSoftSerial mySerial; // RX, TX
//now		-> yellow in 8, green in 9
//before	-> yellow was in 10 - RX, green was in 11 - TX

/**** Initialization function ****/
void setup() {
  //delay(2000);

  // Define baud rate of serial communication (Arduino and software ports)
  // Serial is the hardware serial port (pin 0 = RX, pin 1 = TX)
  // mySerial is the software serial port created for the motors
  // Delays of 0.2 and 0.3s are introduced
  delay(200);  
  Serial.begin(9600);
  delay(300);
  mySerial.begin(9600);
  delay(200);

  // Initialize left motor (1) by starting it and give ticks
  // printIn accepts any data type as input and converts it to ASCII
  // Kangaroo text format: motor ID (1 = left, 2 = right), command (start, units
  // p = position, s = speed) value (!!! the commas are important)
  // The start command must be done before any other command (initialization)
  mySerial.println("1, start");
  mySerial.println("1, units 1000 = " + ticks);
  
  // Initialize right motor (2) by starting it and give ticks
  mySerial.println("2, start");
  mySerial.println("2, units 1000 = " + ticks);
  
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
  
  // Save current time (millis() returns the nb of ms since Arduino started)
  lastUpdateTime = millis();
  leftWheelLastUpdate = millis();
  rightWheelLastUpdate = leftWheelLastUpdate + 6;
  lastChangeSpeed = millis();
  
  // Set motor speeds to 0.1 rev/s
  mySerial.println("1, s100");
  mySerial.println("2, s100");
}

/*** Function to get wheel increments after dt ****/
int GetIncrement(int oldPosition, int newPosition)
{
  // Compute increment with special case when - to + boundary is crossed
  if((abs(newPosition) < midBoundary) || ((oldPosition > 0) && (newPosition > 0)) || ((oldPosition < 0) && (newPosition < 0)))
    return newPosition - oldPosition;
  else
  {
    int res = 65536 - abs(oldPosition) - abs(newPosition);

    // -32768 to 32767 (negative move) or 32767 to -32768 (positive move)
    return newPosition < 0 ? res : -res;
  }
}

/**** Loop function ***/
void loop() {
  /*
  // Save time at the beginning of the loop's iteration
  int now = millis();
 
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
  }

  String odometryData;
  odometryData += '1';
  odometryData += ',';
  odometryData += 'p';
  odometryData += '1';
  odometryData += '9';
  odometryData += '2';
  odometryData += '\r';
  odometryData += '\n';

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
  }
  
  while (mySerial.available() > 0)
  {
    String data;
    int received = mySerial.read();
    data += received;
    Serial.println(data);
  }
  
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

// Get current time
int currentTime = millis();

// Check if odometry sample time reached and if so, get position of the wheel
// getp command returns: motor ID, p (P = movement finished, p = movement in action)
// and position value in int (!!! commas are improtant)
if(currentTime - leftWheelLastUpdate > updateOdometryDelta)
{
  mySerial.println("1, getp");
  leftWheelLastUpdate = currentTime;
}
if(currentTime - rightWheelLastUpdate > updateOdometryDelta)
{
  mySerial.println("2, getp");
  rightWheelLastUpdate = currentTime;
}

// Only if software serial port sends bytes (received positons from motors)
if(mySerial.available() > 0)
{
  // Write odometry in hardware serial port 
  // Odometry is written only when position of both wheels is known for a given dt (can
  // be upon two different loops)
  // The format of the odometry sent is : in 1 in 2 RightIncrement * LeftIncrement
  // @ CurrentLeftPos * CurrentRightPos \n
  // Read returns only one byte and -1 if nothing in port
  Serial.println("in");                   // write in

  char motor = mySerial.read();           // read first character (motor ID)
  Serial.println(motor);                  // write motor ID
  delay(2);

  char comma = mySerial.read();           // read comma
  delay(2);

  char c = mySerial.read();               // read p or P

  int number = mySerial.parseInt();       // read position value
  
  if((c == 'P') || (c == 'p'))            // check to be sure position was sent
  { 
    if(motor == '1')
    { 
      // Update motor position
      lastLeftPosition = currentLeftPosition;
      currentLeftPosition = number;
    }
    else if(motor == '2')
    {
      // Write to hardware serial port
      Serial.print(String(GetIncrement(lastLeftPosition, currentLeftPosition)) + '*' + String(GetIncrement(lastRightPosition, number)));
      Serial.print(" @ " + String(currentLeftPosition) + '*' + String(number) + '\n');

      lastRightPosition = number;
    }
  }

  // Empty buffer
  while(c != '\n')
  {
    c = mySerial.read();
  }
}

 
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