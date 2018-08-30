

#define WRENABLE 0X6
#define WRITE 0x2
#define READ 0x3
#define RDSTAT 0x5

#define CSLow LATDbits.LATD12 = 0;
#define CSHigh LATDbits.LATD12 = 1;         



#include "mcc_generated_files/mcc.h"



           

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    uint16_t n, data = 0xaa;

    while (1)
    {
        
        
    // writeByte( 0x00 , data );
         
        LATDbits.LATD12 = 0;
        LATDbits.LATD12 = 1;   
         
       
    }


}


/*
void writeByte(uint16_t addr, uint8_t data)
{
    
    CSLow;
    SPI1_Exchange8bit(WRENABLE);  //wren bit
    CSHigh;
    
    CSLow;
    SPI1_Exchange8bit(WRITE);  //write command
    
    SPI1_Exchange8bit(addr >> 8);  //top byte of 16 bit addr
    SPI1_Exchange8bit(addr ); //bottom byte of 16 bit addr
   
    
    SPI1_Exchange8bit(data);   //8 bits
    CSHigh;
    
}  */