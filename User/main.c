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
		time=1000000;
		while(time>0)
		{
			DisplayWordGlobe(273,""," CHAO MUNG","DAI HOI IV","","");
			time--;
		}
		for (loop=0; loop<3; loop++)
		{
			for (i=273; i!=274; i--)
			{
				time=2500;
				while(time<=2500)
				{
					DisplayWordGlobe(i,""," CHAO MUNG","DAI HOI IV","","");
					time--;
				}
				if (i==1)
					i=359;
			}
		}

		time=1000000;
		while(time>0)
		{
			DisplayWordGlobe(270,"","HOI SINH VIEN","  VIET NAM  ","","");
			time--;
		}
		for (loop=0; loop<3; loop++)
		{
			for (i=270; i!=271; i--)
			{
				time=3000;
				while(time<=3000)
				{
					DisplayWordGlobe(i,"","HOI SINH VIEN","   VIET NAM","","");
					time--;
				}
				if (i==1)
					i=359;
			}
		}
	
		
		time=1000000;
		while(time>0)
		{
			DisplayWordGlobe(273,"","  DAI HOI","2018 - 2020","","");
			time--;
		}
		for (loop=0; loop<3; loop++)
		{
			for (i=273; i!=274; i--)
			{
				time=3000;
				while(time<=3000)
				{
					DisplayWordGlobe(i,"","  DAI HOI","2018 - 2020","","");
					time--;
				}
				if (i==1)
					i=359;
			}
		}

			time=1500000;
			while(time>0)
			{
				DisplayHSVLogo(273);
				time--;
			}
			for (loop=0; loop<3; loop++)
			{
				for (i=273; i!=272; i++)
				{
					time=5000;
					while(time<=5000)
					{
						DisplayHSVLogo(i);
						time--;
					}
					if (i==359)
						i=0;
				}
			}
			time=1500000;
			while(time>0)
			{
				DisplayHSVLogo(273);
				time--;
			}
			
		time=1000000;
		while(time>0)
		{
			DisplayWordGlobe(281,"","   UIT   ","WE ARE ONE","","");
			time--;
		}
		for (loop=0; loop<3; loop++)
		{
			for (i=281; i!=282; i--)
			{
				time=2500;
				while(time<=2500)
				{
					DisplayWordGlobe(i,"","   UIT   ","WE ARE ONE","","");
					time--;
				}
				if (i==1)
				{
					i=355;
				}
			}
		}
		
		for (loop=0; loop<7; loop++)
		{
			time=250000;
			while(time<=250000)
			{
				DisplayHeart(335);
				time--;
			}
			time=250000;
			while(time<=250000)
			{
				DisplayWordGlobe(347,"","","UIT", "", "");
				time--;
			}
		}
			
		for (loop=0; loop<3; loop++)
		{
			for (i=0; i<360; i++)
			{
				time=1500;
				while(time<=1500)
				{
					DisplayEarth(i);
					time--;
				}
			}
		}
	}
}
