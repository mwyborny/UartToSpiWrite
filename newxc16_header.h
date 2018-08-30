#define FOSC 32000000L
#define FCY 16000000UL
#define WREN 0X6
#define WR 0x2
#define RD 0x3
#define RDSTAT 0x5
#define WRDIS 0x04

#define ACK  0x06 
#define NAK  0x15 
#define SOH  0x01
#define EOT  0x04
#define ETB  0x17


#define CSLow LATDbits.LATD12 = 0
#define CSHigh LATDbits.LATD12 = 1
#define delay_ms __delay_ms



 
#include <xc.h> 
#include <libpic30.h>


#include <math.h>
#include <p24FJ1024GB610.h>

uint8_t readByte(uint16_t addr, uint8_t data);

void writeByte(uint16_t addr, uint8_t data);
uint8_t readStat();


void clearTMR1();



