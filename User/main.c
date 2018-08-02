#include <Function.h>

int main(void)
{
	Init_GPIO();
	Init_SysTick();
	Init_Timer();
	Init_Interrupt();
	Timer_On(TIM2, 1);
	uint8_t t=0;
	
//	for (t=0; t<40; t++)
//	{
//		InputData(1);
//		ShiftLED();
//	}
//	SendData();
//	DisplayLine(0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111);
	while (1)
	{
		if (StartPos(150))
		{
			DisplayWord("Hello");
		}
		if (StartPos(200))
		{
			DisplayWord("CEEC");
		}
	}
}
