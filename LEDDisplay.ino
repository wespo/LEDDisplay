#include "LEDSixteen.h"
//requires LEDControl library to be installed

char msg[32]="    HELLO MIKE";    //message buffer. I left the first four characaters as spaces so the string appears to scroll in.
void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600); //Legacy, for "serial terminal mode.
  setupSixteen();

  testSixteen(true);
  delay(1000);
  testSixteen(false);
  
}

bool toggle = true;
void loop() {
  // Uncomment this section if you want a serial terminal for a single letter.
  // while(!Serial.available() ){
  // }
  // char c = Serial.read();
  // Serial.println(c);
  // printSixteen(c,1);

  // This code loops over the msg string defined at the top.
  for (int i = 0; i < 32; i++)
  {
    if(msg[i+3]=='\0') //stop if the last digit is the end of the string.
    {
      break;
    }
    printSixteen(msg[i],0); //print to digit 0
    printSixteen(msg[i+1],1); //print to digit 1
    printSixteen(msg[i+2],2); //print to digit 2
    printSixteen(msg[i+3],3); //print to digit 3
    delay(750); //pause at each letter for 3/4 second.
  }
  delay(3000); //pause at the end of the string for 3 seconds,

}
