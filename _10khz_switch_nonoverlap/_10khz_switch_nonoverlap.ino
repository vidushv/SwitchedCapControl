#include "msp430g2553.h" 

// Testing switching speed of pin 2.3 and 2.4 at 100kHz  
//using delay cycles after setting clock speed to 1MHz

void setup() {                
P2DIR = 0x00;    // initialize all p2 pins default as inputs 
P2DIR |= 0x1F ;  //now make pin 2.0 - 2.4 outputs

WDTCTL = WDTPW + WDTHOLD; //disabling watchdog timer to prevent reset blips

BCSCTL1 = CALBC1_1MHZ; //set clock to 1MHz
DCOCTL = CALDCO_1MHZ;

}

// the loop routine runs over and over again to switch the I/O's
void loop() {
  
  while(1)
  {
    P2OUT = 0x16;
    P2OUT  = 0x1D;
  __delay_cycles(40);  //1:1 topology
  P2OUT = 0x16;
  P2OUT = 0x1B;
    __delay_cycles(37);
  
  } 
             
}
