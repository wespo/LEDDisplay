#include "LEDSixteen.h"
//requires LEDControl library to be installed

#define BUF_SIZE
char msg[BUF_SIZE]="        FOUR SCORE AND SEVEN YEARS AGO";    //message buffer. I left the first four characaters as spaces so the string appears to scroll in.
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
  int ndigits = 4
  for (int i = 0; i < BUF_SIZE; i++)
  {
    if(msg[i+ndigits-1]=='\0') //stop if the last digit is the end of the string.
    {
      break;
    }
    for (int j = 0; j < ndigits; j++)
    {
      printSixteen(msg[i+j],j); //print to digit 0
    }
    delay(750); //pause at each letter for 3/4 second.
  }
  delay(3000); //pause at the end of the string for 3 seconds,

}
