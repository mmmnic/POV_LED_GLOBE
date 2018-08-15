#include <Function.h>

int main(void)
{
	Init_GPIO();
	Init_Timer();
	Init_Interrupt();

	while (1)
	{
		if (StartPos(310))
			DisplayWord("HELLO");
	}
	
}
