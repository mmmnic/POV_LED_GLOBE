#include <Function.h>

int main(void)
{
	Init_GPIO();
	Init_Timer();
	Init_Interrupt();

	//uint8_t i=0;
	while (1)
	{
		if (StartPos(300))
		{
			DisplayWord("HELLO UIT");
		}
	}

}
