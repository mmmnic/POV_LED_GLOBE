#include <Function.h>


int main(void)
{
	Init_GPIO();
	Init_Timer();
	Init_Interrupt();

//	if (StartPos(0))
//		DisplayLine(255,255,255,255,255);
//	if (StartPos(90))
//		DisplayLine(255,255,255,255,255);
//	if (StartPos(180))
//		DisplayLine(255,255,255,255,255);
//	if (StartPos(270))
//		DisplayLine(255,255,255,255,255);
//	ClearData();
	uint8_t  t;
	uint16_t i=1;
	uint16_t loop;
	while (1)
	{
		for (t=0; t<5; t++)
		{
			for (i=370;i<=370; i--)
			{
				loop=2500;
				while(loop)
				{
					loop--;
					DisplayWordGlobe(i, "", "WELCOME", "  TO  ", "  UIT ", "");
				}
			}	
		}
		
		for (t=0; t<5; t++)
		{
			for (i=370;i<=370; i--)
			{
				loop=2500;
				while(loop)
				{
					loop--;
					DisplayWordGlobe(i, "", "WELCOME TO ", " COMPUTER ", "ENGINEERING", "");
				}
			}
		}
		for (t=0; t<2; t++)
		{
			for (i=0;i<370; i++)
			{
				loop=2750;
				while(loop)
				{
					loop--;
					DisplayEarth(i);
				}
			}
		}
	}
}
