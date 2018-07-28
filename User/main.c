#include <Function.h>

int main(void)
{
	Init_GPIO();
	Init_SysTick();
	Init_Timer();
	Init_Interrupt();
	
	while (1)
	{
		DelayUs(TimePerAngle*270);
		DisplayWord("Hello");
		DelayUs(TimePerAngle*5);
		DisplayWord("World");
	}
}
