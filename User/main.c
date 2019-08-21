#include <Function.h>

int main(void)
{
	//-------------------- INIT --------------------
	Init_GPIO();
	Init_Timer();
	Init_Interrupt();
	
	uint32_t time,i;
	uint8_t loop;
	uint16_t TempPos=0;
	
	//wait to get enough speed before entering infinity loop
	DisplayLine(255,255,255,255,255);
	while(TimePerAngle<=20)
	{
	}
	
	while (1)
	{
		DisplayWordsGlobe(0,"","","HELLO","","");
	}
}
