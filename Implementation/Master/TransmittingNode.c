#include"CANheader.h"
#include"LCD_4bitheader.h"

#define Sw1 (IOPIN0&(1<<14))
#define Sw2 (IOPIN0&(1<<15))
#define Sw3 (IOPIN0&(1<<16))

int main()
{
	CAN2_MSG m1,m2,m3; //Structure Variables
	//unsigned int i;
	UART0_Config(115200);
	CAN_Config();
	LCD_Config();
	
	//Left Indicator
	m1.id=0x010; //11-bit message ID
	m1.rtr=0; // RTR bit=0 for selecting Data frame
	m1.dlc=0; 
	m1.byteA=0;
	m1.byteB=0;
	
	//Right Indicator
	m2.id=0x020; //11-bit message ID
	m2.rtr=0; // RTR bit=0 for selecting Data frame
	m2.dlc=0; 
	m2.byteA=0;
	m2.byteB=0;
	
	//Wiper Motor
	m3.id=0x030; //11-bit message ID
	m3.rtr=0; // RTR bit=0 for selecting Data frame
	m3.dlc=0; 
	m3.byteA=0;
	m3.byteB=0;
	
	while(1)
	{
		LCD_Command(0x01);
		LCD_String("Body Control");
		LCD_Command(0xC7);
		LCD_String("Module");
		delay_milliseconds(200);
		
		if(Sw1==0)
		{
			delay_milliseconds(200);
			CAN_Tx(m1);
			LCD_Command(0x01);
			LCD_Command(0x80);
			LCD_String("Left Indicator ON");
			delay_milliseconds(1000);
			while(Sw1==0);
		}
		
		if(Sw2==0)
		{
			delay_milliseconds(200);
			CAN_Tx(m2);
			LCD_Command(0x01);
			LCD_Command(0x80);
			LCD_String("Right Indicator ON");
			delay_milliseconds(1000);
			while(Sw2==0);
		}
		
		if(Sw3==0)
		{
			delay_milliseconds(200);
			CAN_Tx(m3);
			LCD_Command(0x01);
			LCD_Command(0x80);
			LCD_String("Wiper Motor ON");
			delay_milliseconds(1000);
			while(Sw3==0);
		}
	}
}
