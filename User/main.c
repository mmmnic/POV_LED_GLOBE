#include <Function.h>


int main(void)
{
	Init_GPIO();
	Init_Timer();
	Init_Interrupt();

	
	while (1)
	{
		uint16_t i, loop=3;
		
		// Display "WELCOME TO UIT" 3 times
		while (loop)
		{
			for (i=0; i<355; i++)
			{
				Timing=750*TimePerAngle;
				while(Timing<750*TimePerAngle)
					DisplayWordGlobe(i, "", "WELCOME", "  TO  ", "  UIT ", "");
			}
			loop--;
		}
		
		// Display "WELCOME TO COMPUTER ENGINEERING" 3 times 
		loop=3;
		while (loop)
		{
			for (i=0; i<355; i++)
			{
				Timing=750*TimePerAngle;
				while(Timing<750*TimePerAngle)
					DisplayWordGlobe(i, "", "WELCOME TO ", " COMPUTER ", "ENGINEERING", "");
			}
			loop--;
		}
		
		// Display Earth 3 times
		loop=3;
		while (loop)
		{
			for (i=0; i<355; i+=5)
			{
				DisplayEarth(i);
			}
		loop--;
		}
		loop=3;
	}
}
