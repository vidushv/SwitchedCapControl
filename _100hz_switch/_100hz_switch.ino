#include "msp430g2553.h" 

// Testing switching speed of pin 2.3 and 2.4 at 100kHz  
//using delay cycles after setting clock speed to 16MHz

void setup() {                
P2DIR = 0x00;    // initialize all p2 pins default as inputs 
P2DIR |= 0x1F ;  //now make pin 2.0 - 2.4 outputs

WDTCTL = WDTPW + WDTHOLD; //disabling watchdog timer to prevent reset blips

BCSCTL1 = CALBC1_1MHZ; //set clock to 16MHz
DCOCTL = CALDCO_1MHZ;

}

// the loop routine runs over and over again to switch the I/O's
void loop() {
  
  while(1)
  {P2OUT  = 0x1D;
  __delay_cycles(4995);           //1:1 topology
  P2OUT = 0x1B;
    __delay_cycles(4993);
  } 
  
    // Dump Charge Here (maybe not needed since Cfly has PV volts anyways every mode)

 /* while(1)
  {P2OUT  = 0x1D;
  __delay_cycles(74);           //1:2 topology
  P2OUT = 0x12;
    __delay_cycles(72);
  } */
 
   // Dump Charge Here

  /*while(1)
  {P2OUT  = 0x0C;
  __delay_cycles(74);           //2:1 topology
  P2OUT = 0x1B;
    __delay_cycles(72);
  }*/
  
    // Dump Charge Here
        
       
}
