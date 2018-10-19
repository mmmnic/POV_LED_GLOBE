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
				time=4000;
				while(time<=4000)
				{
					DisplayCityHSVLogo(i);
					time--;
				}
				if (i==359)
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
					i=359;
			}
		}
		
		
//		time=500000;
//		while(time>0)
//		{
//			DisplayWordGlobe(273,""," CHAO MUNG","DAI HOI IV","","");
//			time--;
//		}
//		for (loop=0; loop<2; loop++)
//		{
//			for (i=273; i!=274; i--)
//			{
//				time=2000;
//				while(time<=2000)
//				{
//					DisplayWordGlobe(i,""," CHAO MUNG","DAI HOI IV","","");
//					time--;
//				}
//				if (i==1)
//					i=359;
//			}
//		}

//		
//		time=1500000;
//		while(time>0)
//		{
//			DisplayHSVLogo(273);
//			time--;
//		}
//		for (loop=0; loop<3; loop++)
//		{
//			for (i=273; i!=272; i++)
//			{
//				time=3000;
//				while(time<=3000)
//				{
//					DisplayHSVLogo(i);
//					time--;
//				}
//				if (i==359)
//					i=0;
//			}
//		}
//		time=1000000;
//		while(time>0)
//		{
//			DisplayHSVLogo(273);
//			time--;
//		}
//			
//		time=1000000;
//		while(time>0)
//		{
//			DisplayWordGlobe(300,""," TU TE ","TAI NANG"," TIEN BO","");
//			time--;
//		}
//		for (loop=0; loop<2; loop++)
//		{
//			for (i=300; i!=301; i--)
//			{
//				time=3000;
//				while(time<=3000)
//				{
//					DisplayWordGlobe(i,""," TU TE ","TAI NANG"," TIEN BO","");
//					time--;
//				}
//				if (i==1)
//				{
//					i=355;
//				}
//			}
//		}
//		
	}
}
