
#include <p18f4580.h> 
#include "LCD.h"

#define RS PORTCbits.RC0             
#define EN PORTCbits.RC1

void lcdInit()
{
	 delay(15);                      
     lcdCommand(0x30);	
	 delay(5);         
     lcdCommand(0x30);	
	 delay(1);            
     lcdCommand(0x30);	
	 delay(2);          
     lcdCommand(0x38);                    
     lcdCommand(0x06);                     
     lcdCommand(0x01);                       
     lcdCommand(0x0C);
}

void lcdCommand(char cmd)
{
     PORTD=cmd;
     RS=0;            
     EN=1;               
     delay(4);                 
     EN=0;            
}

void lcdData(char data)
{
     PORTD=data;
     RS=1;              
     EN=1;            
     delay(4);                   
     EN=0;            
}

void sendtoLcd(const char Adr,rom const char *Lcd)
{
     lcdCommand(Adr);
     while(*Lcd!='\0')	
     {
	    lcdData(*Lcd);	
        Lcd++;	
     }  
}

void delay(int ms)
{
	int i,count;
	for(i=1;i<=ms;i++)
	{
		count=498;
		while(count!=1)
		{
			count--;
		}
	}	
}

void main()                             
{
     TRISC=0X00;                       
     TRISD=0X00;     
     lcdInit();                             
     while(1)
	 {
     	sendtoLcd(0x80,"Welcome to");
	 	sendtoLcd(0xc0,"Smart Dispenser");
     	
	 }
}

//windup
