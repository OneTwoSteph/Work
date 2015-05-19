/*
 Alternative software serial communication for motor 
 command.
 
 The alternative software serial communication allows to 
 send and receive at the same time which is not the case 
 with the software serial communication.
 
 Make sure you have the additionnal library installed.
 
 Receives wheel motor commands from the hardware serial and
 sends them to software serial which represents wheel motors.
 
 The pins cannot be chosen, the correct pins for each time of
 board need to be checked out on the librairies website.
 In the case of Arduino Uno (also ok for Mini Pro):
 RX = receiving pin = pin 8 (connect to TX of motors -> yellow)
 TX = transmitting pin = pin 9 (connect to RX of motors -> green)
 
 String format to send motor commands to hardware
 communication port :
 leftsign leftspeed rightsign rightspeed 
 
 !!!  The sign of the speeds has to be given before their value.
 
 The first character has to be anything but "@".
 The sign of the speeds has to be given before their value.
 */


/**** Libraries ****/
// Library for serial communication (UART) which allows to replicate the functionality
// of UART of pin 0 and 1 on other pins of the board to allow communication with them.
// The alternate library allows to receive and transmit at the same time.
#include <AltSoftSerial.h>    


/**** Global variables and parameters ****/
int ticks = 480;                          // number of ticks per wheel revolution                         
int heartBeatChar = '@';

AltSoftSerial mySerial;                   // SoftwareSerial object for motors: RX, TX


/**** Initialization function ****/
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
  mySerial.println("1, start");
  mySerial.println("1, units 1000 = 663");

  // Initialize right motor (2) by starting it and give ticks
  mySerial.println("2, start");
  mySerial.println("2, units 1000 = 663");
  
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
}


/**** Loop function ***/
void loop() {
  // Only if hardware serial port sends bytes (received commands)
  if(Serial.available())
  {    
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
        
      // Empty buffer
      Serial.readString();
      
      // Write speeds into motor ports in the form id, s+/-speed
      // The + sign is redefined for String objects and concatenates two strings
      // so here the int is converted to String
      // String is an object which allows complex operations with strings
      mySerial.println(String("1, s") + leftSpeed);
      mySerial.println(String("2, s") + rightSpeed);
    }
  }
}
