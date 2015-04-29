/**** Libraries ****/
// Library for serial communication (UART) which allows to replicate the functionality
// of UART of pin 0 and 1 on other pins of the board to allowa communication with them.
#include <SoftwareSerial.h>

/**** Global variables and parameters ****/
SoftwareSerial mySerial(10, 11);            // SoftwareSerial object for motors: RX, TX

int flag = 1;
int counter = 0;

/**** Initialization function ****/
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  
  // Initialize left motor (1) by starting it and give ticks
  // printIn accepts any data type as input and converts it to ASCII
  // Kangaroo text format: motor ID (1 = left, 2 = right), command (start, units
  // p = position, s = speed) value (!!! the commas are important)
  // The start command must be done before any other command (initialization)
  mySerial.println("1,start");
  mySerial.println("1, units 1000 = 1856");
  
  // Initialize right motor (2) by starting it and give ticks
  mySerial.println("2,start");
  mySerial.println("2, units 1000 = 1856");
  
  // Set motor speeds to 0.1 rev/s
  mySerial.println("1,s100");
  mySerial.println("2,s100");
}

void loop() {
  int bytes = mySerial.available();
  Serial.println(String(bytes));
  
  if(flag)
  {
    mySerial.println("1,getp");
    flag = 0;
  }
  
  if((counter > 10) && (bytes >0))
  {
    //int wtf = mySerial.parseInt();
    char wtf = mySerial.read();
    Serial.println(String("received : ") + String(wtf));
  }
  
  counter++;
}
