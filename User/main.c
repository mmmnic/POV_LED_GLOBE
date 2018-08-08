#include <Function.h>

int main(void)
{
	Init_GPIO();
	Init_SysTick();
	Init_Timer();
	Init_Interrupt();
	Timer_On(TIM2, 1);
	

	
	while (1)
	{
		DisplayLine(0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111);
//		if (StartPos(150))
//		{
//			DisplayWord("Hello");
//		}
//		if (StartPos(200))
//		{
//			DisplayWord("CEEC");
//		}
	}
}
