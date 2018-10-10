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
		for (loop=0; loop<5; loop++)
		{
			for (i=360; i>0; i--)
			{
				time=2000;
				while(time<=2000)
				{
					DisplayWordGlobe(i,""," HELLO THPT ","BUI THI XUAN", "", "");
					time--;
				}
			}
		}
		for (i=360; i>0; i--)
		{
			time=2500;
			while(time<=2500)
			{
				DisplayWordGlobe(i,"","","WE", "", "");
				time--;
			}
		}
		for (i=360; i>0; i--)
		{
			time=2500;
			while(time<=2500)
			{
				DisplayWordGlobe(i,"","","ARE", "", "");
				time--;
			}
		}
		for (i=360; i>0; i--)
		{
			time=2500;
			while(time<=2500)
			{
				DisplayWordGlobe(i,"","CEEC","    CEEC", "       CEEC", "");
				time--;
			}
		}

		for (loop=0; loop<2; loop++)
		{
			for (i=360; i>0; i--)
			{
				time=5000;
				while(time<=5000)
				{
					DisplayWordGlobe(i,"","THIS" ,"IS", "EARTH", "");
					time--;
				}
			}
		}
		for (loop=0; loop<3; loop++)
		{
			for (i=0; i<360; i++)
			{
				time=3000;
				while(time<=3000)
				{
					DisplayEarth(i);
					time--;
				}
			}
		}
		
		for (loop=0; loop<2; loop++)
		{
			for (i=360; i>0; i--)
			{
				time=3000;
				while(time<=3000)
				{
					DisplayWordGlobe(i,"","","I", "", "");
					time--;
				}
			}
			
			for (i=360; i>0; i--)
			{
				time=3000;
				while(time<=3000)
				{
					DisplayHeart(i);
					time--;
				}
			}
			
			for (i=360; i>0; i--)
			{
				time=3000;
				while(time<=3000)
				{
					DisplayWordGlobe(i,"","","YOU", "", "");
					time--;
				}
			}
		}
	}
}
