
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/uart1.h"
#include "newxc16_header.h"
#include "functions.h"

extern tmr1_obj;

bool IFlag = 0;


int main(void)
{
 
    SYSTEM_Initialize();
    
    
    uint8_t n, x, data, y = 0 ;
    uint16_t addr, i16;
    uint8_t UData[133];
   
        writeByte( 0x0000,  0xfa);
      
        Nop();
        
        n = readByte(0x0000, data);
        
        Nop();

   while(1)
   {
  
    printf("\r\nReady to receive 16-bit color, 128x160 .bmp over xmodem  \n\r");
     printf("\r\press anykey and then send...  \n\r");
//     UART1_Read();
    
    addr = 0;
    
   

    
    while(!( U1STAbits.URXDA == 1) )
      {
        delay_ms(1000);
        printf("%c", 0x43);
       // delay_ms(1);
      }
    TMR1_Start();
    while(1)
     {
         for(i16 = 0; i16 < 133; i16++)
             {
                UData[i16] = UART1_Read();
            }
         if(IFlag == 1)
            {
                 IFlag = 0;
                if(UData[0] == NAK)
                    {
                        printf("ACK");
                 
                        if(ETB == UART1_Read() )
                            {
                                printf("ACK");
                                goto done;
                            }
                    }
            }
             
         TMR1_Stop();
        
         for(n = 3;n<128+3;n++)
             {
                writeByte(addr++, UData[n]);
             }
       
         TMR1 = 0;
         TMR1_Start();
     
         printf("%c",ACK);
       
    
    }
    
    
     
done:
 TMR1_Stop();
    for(i16 = 0; i16 < 132; i16++)
        {
        printf("%x ", UData[i16]);
        }
   }
           
    
    
    Nop();
    for(i16=0;i16<200;i16++)
        {
            n = readByte(i16, 0);
            printf("%x ", n);
            delay_ms(100);
    
        }   
    
 
};
