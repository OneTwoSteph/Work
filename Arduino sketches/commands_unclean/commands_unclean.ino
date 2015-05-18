/*
 Software serial communication for motor command.
 
 Receives wheel motor commands from the hardware serial and
 sends them to software serial which represents wheel motors.
 
 RX = receiving pin
 TX = transmitting pin
 
 The circuit:
 * RX is digital pin 10 (connect to TX of motors)
 * TX is digital pin 11 (connect to RX of motors)
 
 String format to send to hardware communication port :
 leftsign leftspeed rightsign rightspeed 
 
 The first character has to be anything but "@".
 The sign of the speeds has to be given before their value.
 */

// Library for serial communication (UART) which allows to replicate the functionality
// of UART of pin 0 and 1 on other pins of the board to allowa communication with them.
#include <SoftwareSerial.h>    

// Global variables and parameters
int ticks = 663;                          // number of ticks per wheel revolution
int rpm = 61, vel_units;                  // 
int increment = 1;
String vel;                               // String is an object which allows complex operations with strings
unsigned long lastUpdateTime;             // contains last update time of the ports in ms
int heartBeatChar = '@';
int heartBeatTimeout = 500;

SoftwareSerial mySerial(10, 11);         // SoftwareSerial object for motors: RX, TX

void setup() {
  // Make the program wait 2s
  delay(2000);
  
  // Define baud rate of serial communication (Arduino and software ports)
  // Serial is the hardware serial port (pin 0 = RX, pin 1 = TX)
  // mySerial is the software serial port created for the motors
  Serial.begin(9600);
  mySerial.begin(9600);
  
  // Initialize left motor (1) by starting it and give ticks
  // printIn accepts any data type as input and converts it to ASCII
  mySerial.println("1,start");
  mySerial.println("1, units 1000 = 663");
  //Serial.println("1,home");
  
  // Initialize right motor (2) by starting it and give ticks
  mySerial.println("2,start");
  mySerial.println("2, units 1000 = 663");
  //Serial.println("2,home");
  
  // Make the program wait 2s
  delay(2000);
  
  // Set forward speeds to motors
  mySerial.println("1, s200");
  mySerial.println("2, s200");
  
  // Make the program wait 1s
  delay(1000);
  
  // Set backward speeds to motors
  mySerial.println("1, s-200");
  mySerial.println("2, s-200");
  delay(1000);
  
  // Set speeds to zero
  mySerial.println("1, s0");
  mySerial.println("2, s0");
  
  // Make the program wait 1s
  delay(1000);
  
  // Get time since Arduino board began running the program in ms
  lastUpdateTime = millis();
}

void loop() {
  // Get commands only if hardware serial port availaible
  if(Serial.available())
  {
    // Update last update time
    lastUpdateTime = millis();
    
    // Read first byte (first character) in RX pin of hardware serial port
    int firstChar = Serial.read();
    
    // Send motor commands if there are any
    if(firstChar != heartBeatChar)
    {
      // Read left speed and its sign
      // parseInt() allows to check for next valid integer in RX stream
      int leftSign = firstChar;
      int leftSpeed = Serial.parseInt();          
      if(leftSign == '-') leftSpeed = -leftSpeed;
      
      // Read right speed and its sign 
      int rightSign = Serial.read();
      int rightSpeed = Serial.parseInt();
      if(rightSign == '-') rightSpeed = -rightSpeed;
        
      // Read char to skip
      Serial.read();
      
      // Test if connection is working
      Serial.println("test");
      
      // Write speeds into motor ports in the form id, s+/-speed
      // The + sign is redefined for String objects and concatenates two strings
      // so here the int is converted to String
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
