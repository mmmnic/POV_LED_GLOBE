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
		// display logo HSV HCM
		time=500000;
		while(time>0)
		{
			DisplayCityHSVLogo(280);
			time--;
		}
		for (loop=0; loop<2; loop++)
		{
			for (i=280; i!=279; i++)
			{
				time=4000;
				while(time<=4000)
				{
					DisplayCityHSVLogo(i);
					time--;
				}
				if (i==363)
					i=0;
			}
		}
		
		time=500000;
		while(time>0)
		{
			DisplayWordGlobe(270,"","DAI HOI HSV", " VIET NAM" ,"   LAN X","");
			time--;
		}
		for (loop=0; loop <2; loop++)
		{
			for (i=270; i!=271; i--)
			{
				time=4000;
				while(time<=4000)
				{
					DisplayWordGlobe(i,"","DAI HOI HSV", " VIET NAM" ,"   LAN X","");
					time--;
				}
				if (i==1)
				{
					i=365;
				}
			}
		}
		time=250000;
		while(time>0)
		{
			DisplayWordGlobe(270,"","DAI HOI HSV", " VIET NAM" ,"   LAN X","");
			time--;
		}
	}
}
