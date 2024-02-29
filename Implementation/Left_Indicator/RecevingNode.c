#include"CANheader.h"
#define LED 1<<17

int main()
{
	CAN2_MSG m1; //Structure Variables
	unsigned int i;
	CAN_Config();
	UART0_Config(115200);
	IODIR0=LED;
	IOSET0=LED;
	UART0_String("Testing\r\n");
	while(1)
	{		
		CAN_Rx(&m1);
		UART0_String("CAN Received:\r\n");
		UART0_Hex(m1.id);
		if(m1.id==0x10)
		{
			for(i=0;i<10;i++)
			{
				IOCLR0=LED;
				delay_milliseconds(500);
				IOSET0=LED;
				delay_milliseconds(500);
			}
		}		
	}
}
