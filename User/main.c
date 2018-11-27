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
		DisplayLogoUIT(300);
		/*
		time=750000;
		while(time>0)
		{
			DisplayWordGlobe(310,"","","WELCOME","","");
			time--;
		}
		for (loop=0; loop<2; loop++)
		{
			for (i=310; i!=311; i--)
			{
				time=2500;
				while(time<=2500)
				{
					DisplayWordGlobe(i,"","","WELCOME","","");
					time--;
				}
					if (i==1)
					i=359;
			}
		}
		
		time=750000;
		while(time>0)
		{
			DisplayWordGlobe(340,"","CLB","CEEC","","");
			time--;
		}
		for (loop=0; loop<1; loop++)
		{
			for (i=340; i!=341; i--)
			{
				time=2500;
				while(time<=2500)
				{
					DisplayWordGlobe(i,"","CLB","CEEC","","");
					time--;
				}
				if (i==1)
					i=359;
			}
		}
		
		time=1000000;
		while(time>0)
		{
			DisplayLogoVNU(280);
			time--;
		}
		for (loop=0; loop<1; loop++)
		{
			for (i=280; i!=279; i++)
			{
				time=5000;
				while(time<=5000)
				{
					DisplayLogoVNU(i);
					time--;
				}
				if (i==359)
					i=0;
			}
		}
		time=1000000;
		while(time>0)
		{
			DisplayLogoVNU(280);
			time--;
		}
		
		time=500000;
		while(time>0)
		{
			DisplayEarth(220);
			time--;
		}
		for (loop=0; loop<2; loop++)
		{
			for (i=220; i!=219; i++)
			{
				time=1500;
				while(time<=1500)
				{
					DisplayEarth(i);
					time--;
				}
				if (i==360)
				{
					i=0;
				}
			}
		}
		time=500000;
		while(time>0)
		{
			DisplayEarth(220);
			time--;
		}
		
		time=1000000;
		while(time>0)
		{
			DisplayCityHSVLogo(280);
			time--;
		}
		for (loop=0; loop<2; loop++)
		{
			for (i=280; i!=279; i++)
			{
				time=5000;
				while(time<=5000)
				{
					DisplayCityHSVLogo(i);
					time--;
				}
				if (i==359)
					i=0;
			}
		}
		time=500000;
		while(time>0)
		{
			DisplayCityHSVLogo(280);
			time--;
		}
		
		for (loop=0; loop<1; loop++)
		{
			time=250000;
			while(time>0)
			{
				DisplayHeart(335);
				time--;
			}
			time=250000;
			while(time>0)
			{
				DisplayHeart(65);
				time--;
			}
			time=250000;
			while(time>0)
			{
				DisplayHeart(155);
				time--;
			}
			time=250000;
			while(time>0)
			{
				DisplayHeart(245);
				time--;
			}
		}
		for (loop=0; loop<2; loop++)
		{
			time=125000;
			while(time>0)
			{
				DisplayHeart(335);
				time--;
			}
			time=125000;
			while(time>0)
			{
				DisplayHeart(65);
				time--;
			}
			time=125000;
			while(time>0)
			{
				DisplayHeart(155);
				time--;
			}
			time=125000;
			while(time>0)
			{
				DisplayHeart(245);
				time--;
			}
		}
		for (loop=0; loop<3; loop++)
		{
			time=62500;
			while(time>0)
			{
				DisplayHeart(335);
				time--;
			}
			time=62500;
			while(time>0)
			{
				DisplayHeart(65);
				time--;
			}
			time=62500;
			while(time>0)
			{
				DisplayHeart(155);
				time--;
			}
			time=62500;
			while(time>0)
			{
				DisplayHeart(245);
				time--;
			}
		}
		for (loop=0; loop<5; loop++)
		{
			time=31250;
			while(time>0)
			{
				DisplayHeart(335);
				time--;
			}
			time=31250;
			while(time>0)
			{
				DisplayHeart(65);
				time--;
			}
			time=31250;
			while(time>0)
			{
				DisplayHeart(155);
				time--;
			}
			time=31250;
			while(time>0)
			{
				DisplayHeart(245);
				time--;
			}
		}
		time=250000;
		while(time>0)
		{
			DisplayHeart(335);
			time--;
		}
		*/
	}
}
