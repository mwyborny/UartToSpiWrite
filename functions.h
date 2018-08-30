/*
 * File:   functions.c
 * Author: miwyborn
 *
 * Created on August 27, 2018, 4:17 PM
 */


#include "xc.h"
#include "mcc_generated_files/uart1.h"
#include "newxc16_header.h"
#include "mcc_generated_files/tmr1.h"


uint8_t readStat();
void writeByte(uint16_t , uint8_t );
uint8_t readByte(uint16_t , uint8_t );
void clearTMR1();



uint8_t readStat()
{
    
    uint8_t n;
    
    CSLow;
    
    
    n = SPI1_Exchange8bit(RDSTAT);    
    n = SPI1_Exchange8bit(0);
    CSHigh;
    Nop();
    
    return n;    
  
}

void writeByte(uint16_t addr, uint8_t data)
{
    
    CSLow;
    SPI1_Exchange8bit(WREN);  //wren bit
    CSHigh;
    Nop();
    
    CSLow;
    SPI1_Exchange8bit(WR);  //write command
    
    SPI1_Exchange8bit(addr >> 8);  //top byte of 16 bit addr
    SPI1_Exchange8bit(addr ); //bottom byte of 16 bit addr
   
    
    SPI1_Exchange8bit(data);   //8 bits
    CSHigh;
//    Nop();
//    CSLow;
//    SPI1_Exchange8bit(WRDIS);  //wren bit
//    CSHigh;
//    Nop();
   
}
 
uint8_t readByte(uint16_t addr, uint8_t data)
{
    uint8_t recieve;
    CSLow;
    SPI1_Exchange8bit(RD);

    SPI1_Exchange8bit(addr >> 8);
    SPI1_Exchange8bit(addr );
 
    recieve = SPI1_Exchange8bit(0);
    
    // recieve = SPI1_Exchange8bit(0);
    
    CSHigh;
    
    return recieve;
}
 
