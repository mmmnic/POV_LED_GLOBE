#include <Function.h>

int main(void)
{
	Init_GPIO();
	Init_Timer();
	Init_Interrupt();

	
	while (1)
	{
		Timing=200000;
		while (Timing<=200000)
		{
			DisplayWordGlobe(315,"","HELLO", " UIT ", "","");
		}
		Timing=200000;
		while (Timing<=200000)
		{
			DisplayWordGlobe(270,"","   HELLO   ", "  COMPUTER  ", "ENGINEERING","");
		}
//		TimingDelay=3000000;
//		while (TimingDelay)
//			DisplayWordGlobe(315,"","HELLO", " CEEC", "","");
//		TimingDelay=3000000;
//		while (TimingDelay)
//			DisplayWordGlobe(315,"","HELLO", "MYSELF", "","");
	}
}
