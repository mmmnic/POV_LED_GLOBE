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
	uint16_t TempPos=0;
	while (1)
	{
		for (loop=0; loop<1; loop++)
		{
			for (i=255; i!=254; i++)
			{
				time=2500;
				while(time<=2500)
				{
					DisplayLightBulb(i);
					TempPos = i + 168;
					if (TempPos>362)
					{
						TempPos = TempPos - 360;
					}
					DisplayWordGlobe(TempPos,"","","SISI","","");
					time--;
				}
				if (i==363)
					i=0;
			}
		}
		
		// display logo VNU HCM
		time=500000;
		while(time>0)
		{
			DisplayLogoVNU(280);
			time--;
		}
		for (loop=0; loop<1; loop++)
		{
			for (i=280; i!=279; i++)
			{
				time=4000;
				while(time<=4000)
				{
					DisplayLogoVNU(i);
					time--;
				}
				if (i==363)
					i=0;
			}
		}
		time=250000;
		while(time>0)
		{
			DisplayLogoVNU(280);
			time--;
		}
	}
}
