#pragma config FOSC = INTOSC // Oscillator Selection Bits(INTOSC oscillator:I/Ofunction on CLKIN pin)
#pragma config WDTE = OFF // Watchdog Timer Enable(WDTdisabled)

#pragma config PWRTE = OFF // Power-up Timer Enable(PWRTdisabled)

#pragma config MCLRE = OFF // MCLR Pin Function Select(MCLR/VPP pin function isMCLR)

#pragma config CP = OFF // Flash Program Memory CodeProtection (Program\memorycode protection is disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable(Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF // Clock Out Enable (CLKOUTfunction is disabled.I/O or oscillator functionon the CLKOUT pin)

#pragma config IESO = ON // Internal/External SwitchoverMode (Internal/ExternalSwitchover Mode is enabled)
#pragma config FCMEN = OFF // Fail-Safe Clock MonitorEnable (Fail-Safe ClockMonitor is enabled)\Chapter 6 Input and Output97

// CONFIG2
#pragma config WRT = OFF // Flash Memory Self-WriteProtection (Write protection off)

#pragma config PPS1WAY = ON // Peripheral Pin Select one-way control (The PP\SLOCK bitcannot be cleared once it isset by software)

#pragma config ZCDDIS = ON // Zero-cross detect disable(Zero-cross detect circuit isdisabled at POR and can beenabled with ZCDSEN bit.)
#pragma config PLLEN = OFF // Phase Lock Loop enable (4x PLL is enabled when software sets the SPLLEN bit)

#pragma config STVREN = ON // Stack Overflow/Underflow Reset Enable (Stack\Overflow or Underflow will cause a Reset)
#pragma config BORV = LO // Brown-out Reset Voltage Selection (Brown-out\Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = OFF // Low-Voltage Programming Enable (High-voltage\on MCLR/VPP must be used for programming)

//XC8 Standard Include
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>


//Other Includes
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
//For delay routines
#define _XTAL_FREQ 16000000
void initMain(){

TRISD = 0;
// Turn off analog
ANSELD = 0;
}
/**************************************************************
*****************
* Function: Main
*
* Returns: Nothing
*
* Description: Program entry point
***************************************************************
***************/
void main(void) {
initMain();
while(1){
LATD = 0b00001001; // Step 1
__delay_ms(500);
LATD = 0b00000101; // Step 2
__delay_ms(500);


LATD = 0b00000110; // Step 3
__delay_ms(500);
LATD = 0b00001010; // Step 4
__delay_ms(500);
}
return;
}