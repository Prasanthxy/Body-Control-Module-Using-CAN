#include"CANheader.h"
#define LED 1<<17
#define M_1A 1<<12
#define M_2A 1<<13

int main()
{
	CAN2_MSG m1; //Structure Variables
	unsigned int i;
	CAN_Config();
	UART0_Config(115200);
	IODIR0=LED|M_1A|M_2A;
	IOSET0=LED;
	UART0_String("Testing\r\n");
	while(1)
	{		
		CAN_Rx(&m1);
		IOCLR0= M_1A|M_2A;
		UART0_String("CAN Received:\r\n");
		UART0_Hex(m1.id);
		if(m1.id==0x30)
		{
			for(i=0;i<10;i++)
			{
				IOCLR0=M_1A;
				IOSET0=M_2A;
				IOCLR0=LED;
				delay_milliseconds(2000);
				IOSET0=LED;
				IOSET0=M_1A;
				IOCLR0=M_2A;
				delay_milliseconds(2000);
			}
		}		
	}
}
