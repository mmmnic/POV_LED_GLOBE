#include <Function.h>

int main(void)
{
	Init_GPIO();
	Init_Timer();
	Init_Interrupt();

	
	while (1)
	{
		DisplayWordGlobe(330, "", "CHAO", "CAC", "BAN", "");
	}
}
