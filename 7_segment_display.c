/* 
 * File:   main.c
 * Author: ckris
 *
 * Created on September, 2021, 6:14 AM
 */
// PIC16F1717 Configuration Bit Settings
// CONFIG1
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

// digit one enable
#define DIGITONE LATB0
// digit two enable
#define DIGITTWO LATB1

void initMain(){
// Run at 16 MHz

// Set PORTD as output
// Analog disabled
TRISD = 0;
ANSELD = 0;
// Set PORTB as output
// Analog disabled
TRISB = 0;
ANSELB = 0;

// Set RC4 and RC5 as input
_TRISC4 = 1;
_TRISC5 = 1;
// Turn of analog on C
ANSELC = 0;
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
// count variable
int count = 0;
// most significant digit
int MSD;
// least significant digit
int LSD;
initMain();


// Keep displaying digits 0-F
// and update it ever second
while(1)
{
// If RC4 pressed increment count
if(RC4 == 0){
__delay_ms(100);
if (RC4 == 0){
count++;
}
}
// IF RC5 pressed decrement count
if (RC5 == 0)
{
__delay_ms(100);
if(RC5 == 0){
count--;
}
}
// Get MSD and LSD
MSD = count/10;
LSD = count%10;
// Display MSD
LATD = Display(MSD);
DIGITTWO = 1;
__delay_ms(20);
DIGITTWO = 0;


// Display LSD
LATD = Display(LSD);
DIGITONE = 1;
__delay_ms(20);
DIGITONE = 0;
// If value invalid set to 0
if (count > 99 || count < 0){
count = 0;
}
__delay_ms(1);
}
return;
}

unsigned char Display(unsigned char digit)
{
// variable representing numbers
unsigned char numbers;


// an array of the digits 0-F
unsigned char DIGITS[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D,
0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
// assign index given by user to variable
numbers = DIGITS[digit];
// return it
return numbers;
}
    