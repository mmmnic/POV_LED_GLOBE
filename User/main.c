#include <Function.h>

int main(void)
{
	//-------------------- INIT --------------------
	Init_GPIO();
	Init_Timer();
	Init_Interrupt();
	
	
	uint32_t time,i;
	uint8_t loop;
	uint16_t TempPos=0;
	
	
	//wait to get enough speed before entering infinity loop
	DisplayLine(255,255,255,255,255);
	while(TimePerAngle<=20)
	{
	}
	
	
	while (1)
	{
		time=750000;
		while(time>0)
		{
			DisplayWordGlobe(340,"","CE","DAY","","");
			time--;
		}
		for (loop=0; loop<2; loop++)
		{
			for (i=340; i!=341; i--)
			{
				time=2500;
				while(time<=2500)
				{
					DisplayWordGlobe(i,"","CE","DAY","","");
					time--;
				}
				if (i==1)
					i=363;
			}
		}
		
		time=750000;
		while(time>0)
		{
			DisplayWordGlobe(340,"","CLB","CEEC","","");
			time--;
		}
		for (loop=0; loop<2; loop++)
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
					i=363;
			}
		}
		
		time=200000;
		while(time>0)
		{
			DisplayLogoUIT(320);
			DisplayLogoUIT(145);
			time--;
		}
		for (loop=0; loop<3; loop++)
		{
			for (i=320; i!=319; i++)
			{
				time=2500;
				while(time<=2500)
				{
					DisplayLogoUIT(i);
					TempPos = i + 170;
					if (TempPos>362)
					{
						TempPos = TempPos - 360;
					}
					DisplayLogoUIT(TempPos);
					time--;
				}
				if (i==363)
					i=0;
			}
		}
		
		for (i=360; i>0; i--)
		{
			time=2000;
			while(time<=2000)
			{
				DisplayWordGlobe(i,"","","WE", "", "");
				time--;
			}
		}
		for (i=360; i>0; i--)
		{
			time=2000;
			while(time<=2000)
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
				DisplayWordGlobe(i,"","CEEC","   CEEC", "       CEEC", "");
				time--;
			}
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
		
	}
}
