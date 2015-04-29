/*
 Alternative software serial communication for motor 
 command and odometry.
 
 The alternative software serial communication allows to 
 send and receive at the same time which is not the case 
 with the software serial communication. This is important
 for the Kangaroo commands needed for odometry.
 
 Make sure you have the additionnal library installed.
 
 Receives wheel motor commands from the hardware serial and
 sends them to software serial which represents wheel motors.
 
 Updates odometry every dt by sending request to motor and
 receiving the position of the wheels (16 bits encoder ticks
 counter)
 
 The pins cannot be chosen, the correct pins for each time of
 board need to be checked out on the librairies website.
 In the case of Arduino Uno (also ok for Mini Pro):
 RX = receiving pin = pin 8 (connect to TX of motors -> yellow)
 TX = transmitting pin = pin 9 (connect to RX of motors -> green)
 
 String format to send motor commands to hardware
 communication port :
 leftsign leftspeed rightsign rightspeed 
 
 !!!  The sign of the speeds has to be given before their value.
 
 String format of odometry received :
 units (1000 = value) leftincrement * rightincrement
 */


/**** Libraries ****/
// Library for serial communication (UART) which allows to replicate the functionality
// of UART of pin 0 and 1 on other pins of the board to allow communication with them.
// The alternate library allows to receive and transmit at the same time.
#include <AltSoftSerial.h>


/**** Global variables and parameters ****/
AltSoftSerial mySerial;

// General      
int baudrate = 9600;            // serial communication baud rate
int ticks = 480;                // nb ticks per rev of the encoder
int heartBeatChar = '@';
int midBoundary = 16384;        // mid abs number for a signed 16bits int

// Odometry
bool useOdometry = true;         // true if odometry used

int lastLeftPosition = 0;
int currentLeftPosition = 0;
int lastRightPosition = 0;

int leftWheelLastUpdate = 0;
int rightWheelLastUpdate = 0;

int updateOdometryDelta = 50;    // odometry sample time

unsigned long lastUpdateTime;


/**** Initialization function ****/
void setup(){
  delay(300); 
  Serial.begin(baudrate);
  delay(300);
  mySerial.begin(baudrate);
  delay(300);
  
  // Initialize left motor (1) by starting it and give ticks units
  // printIn accepts any data type as input and converts it to ASCII
  // Kangaroo text format: motor ID (1 = left, 2 = right), command (start, units
  // p = position, s = speed) value (!!! the commas are important)
  // The start command must be done before any other command (initialization)
  mySerial.println("1, start");
  mySerial.println(String("1, units 1000 = ") + String(ticks));
  
  // Initialize right motor (2) by starting it and give ticks units
  mySerial.println("2,start");
  mySerial.println(String("2, units 1000 = ") + String(ticks));
  
  lastUpdateTime = millis();
  if(useOdometry){
    leftWheelLastUpdate = lastUpdateTime;
    rightWheelLastUpdate = leftWheelLastUpdate + 6;
  }
}


/*** Function to get wheel increments after dt ****/
int GetIncrement(int oldPosition, int newPosition){
   // Compute increment with special case when - to + boundary is crossed
   if(abs(newPosition) < midBoundary || oldPosition > 0 && newPosition > 0 || oldPosition < 0 && newPosition < 0)
     return newPosition - oldPosition;
   else{
     int res = 65536 - abs(oldPosition) - abs(newPosition);
   
     //-32768 to 32767 (negative move) or 32767 to -32768 (positive move)
     return newPosition < 0 ? res : -res;
   }
}


/**** Loop function ***/
void loop(){
  // Read motor commands if any
  if(Serial.available() > 0){ 
    // First character
    int firstChar = Serial.read();
    
    // Read and send commands if first character isn't @
    if(firstChar != heartBeatChar){
      if(firstChar == '+' || firstChar == '-'){
        // Left wheel
        int leftSign = firstChar;
        int leftSpeed = Serial.parseInt();
        if(leftSign == '-') leftSpeed = -leftSpeed;
        
        // Right wheel
        int rightSign = Serial.read();
        int rightSpeed = Serial.parseInt();
        if(rightSign == '-') rightSpeed = -rightSpeed;

        // Send commands to motors
        mySerial.println(String("1, s") + leftSpeed);
        mySerial.println(String("2, s") + rightSpeed);
        
        // Empty buffer
        Serial.readString();
      }
      else
        while(firstChar != '\n' && firstChar > 0)
          firstChar = mySerial.read();
    }
  }
  
  // Update odometry
  if(useOdometry){
    String odometryData;
    int currentTime = millis();
  
    // Check if odometry sample time passed for left and right wheel
    if(currentTime - leftWheelLastUpdate > updateOdometryDelta){
      mySerial.println("1,getp");
      leftWheelLastUpdate = currentTime;
    }
    
    if(currentTime - rightWheelLastUpdate > updateOdometryDelta){
      mySerial.println("2,getp");
      rightWheelLastUpdate = currentTime;
    }

    // Get the wheel position to compute odometry
    if(mySerial.available() > 0){
      char motor = mySerial.read();      // get the wheel ID
      delay(2);

      mySerial.read();                   // get rid of the comma
      delay(2);
      
      char c = mySerial.read();          // read the p
      
      int number = mySerial.parseInt();  // read the value of the position
    
      // Create odometry message to send to hardaware serial port
      if(c == 'P' || c == 'p'){ 
        if(motor == '1'){
          lastLeftPosition = currentLeftPosition;
          currentLeftPosition = number;
        }
        else if(motor == '2')
        {
          String e = " ";
          int leftInc = GetIncrement(lastLeftPosition, currentLeftPosition);
          int rightInc = GetIncrement(lastRightPosition, number);
          Serial.print(String(ticks) + e + String(millis()) + e + String(leftInc) + e + String(rightInc) + '\n');
          
          lastRightPosition = number;
        }
      }

      // Read chars until next line because next line could be already written if left first called
      // followed by right with getp
      while(c != '\n'){
        c = mySerial.read();
      }
    }
  }
}
