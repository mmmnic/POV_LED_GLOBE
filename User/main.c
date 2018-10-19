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
		time=1500000;
		while(time>0)
		{
			DisplayCityHSVLogo(280);
			time--;
		}
		for (loop=0; loop<3; loop++)
		{
			for (i=280; i!=279; i++)
			{
				time=6000;
				while(time<=6000)
				{
					DisplayCityHSVLogo(i);
					time--;
				}
				if (i==362)
					i=0;
			}
		}
		
		
		time=1500000;
		while(time>0)
		{
			DisplayWordGlobe(280,"","CHAO MUNG","DAI HOI X","","");
			time--;
		}
		for (loop=0; loop<3; loop++)
		{
			for (i=280; i!=281; i--)
			{
				time=3000;
				while(time<=3000)
				{
					DisplayWordGlobe(i,"","CHAO MUNG","DAI HOI X","","");
					time--;
				}
				if (i==1)
					i=365;
			}
		}
		
		time=500000;
		while(time>0)
		{
			DisplayWordGlobe(305,"","A.QUOC","DESIGN","","");
			time--;
		}
	}
}
