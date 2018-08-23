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
	uint32_t time,i;
	uint8_t loop;
	while (1)
	{
		// Display all globe
		DisplayLine(255,255,255,255,255);
		Delay(150000);
		
		// blink 10 times
		loop=10;
		while (loop)
		{
			ClearData();
			Delay(20000);
			DisplayLine(255,255,255,255,255);
			Delay(20000);
			loop--;
		}
		
		// display half size 10 times
		for (loop=0; loop<10; loop++)
		{
			time=200000;
			while(time)
			{
				if (StartPos(0))
				{
					DisplayLine(255,255,255,255,255);
				}
				if (StartPos(180))
				{
					ClearData();
				}
				time--;
			}
			time=200000;
			while(time)
			{
				if (StartPos(0))
				{
					ClearData();
				}
				if (StartPos(180))
				{
					DisplayLine(255,255,255,255,255);
				}
				time--;
			}
		}	

		// Display "WELCOME TO UIT"
		for (loop=0; loop<5; loop++)
		{
			for (i=370;i<=370; i--)
			{
				time=1500;
				while(time)
				{
					time--;
					DisplayWordGlobe(i, "", "WELCOME", "  TO  ", "  UIT ", "");
				}
			}	
		}
		
		// Display "WELCOME TO COMPUTER ENGINEERING"
		for (loop=0; loop<5; loop++)
		{
			for (i=370;i<=370; i--)
			{
				time=2500;
				while(time)
				{
					time--;
					DisplayWordGlobe(i, "", " COMPUTER", "ENGINEERING", "   CEEC", "");
				}
			}
		}
		
		// Display earth
		for (loop=0; loop<5; loop++)
		{
			for (i=370;i<=370; i--)
			{
				time=2750;
				while(time)
				{
					time--;
					DisplayEarth(i);
				}
			}
		}
		
		// Display Heart
		time=450000;
		while(time)
		{
			DisplayHeart(335);
			ClearData();
			DisplayHeart(60);
			ClearData();
			DisplayHeart(120);
			ClearData();
			DisplayHeart(180);
			ClearData();
			DisplayHeart(24);
			ClearData();
			DisplayHeart(270);
			ClearData();
			time--;
		}
		
	}
}
