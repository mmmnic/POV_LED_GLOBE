#include <Function.h>

int main(void)
{
	Init_GPIO();
	Init_SysTick();
	Init_Timer();
	Init_Interrupt();


	
	while (1)
	{
		DisplayLine(0,0,0,0,0);
		if (StartPos(90))
		{
			DisplayLine(255,255,255,255,255);
		}
	}
}
