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
		//Display word "welcome"
		time=750000;
		while(time>0)
		{
			DisplayWordGlobe(310,"","","WELCOME!","","");
			time--;
		}
		for (loop=0; loop<2; loop++)
		{
			for (i=310; i!=311; i--)
			{
				time=3000;
				while(time<=3000)
				{
					DisplayWordGlobe(i,"","","WELCOME!","","");
					time--;
				}
					if (i==1)
					i=363;
			}
		}
		
		// display word "VNU" and "HCM"
		time=750000;
		while(time>0)
		{
			DisplayWordGlobe(340,"","VNU","HCM","","");
			time--;
		}
		for (loop=0; loop<2; loop++)
		{
			for (i=340; i!=341; i--)
			{
				time=5000;
				while(time<=5000)
				{
					DisplayWordGlobe(i,"","VNU","HCM","","");
					time--;
				}
					if (i==1)
					i=363;
			}
		}
		
		// display logo VNU HCM
		time=1000000;
		while(time>0)
		{
			DisplayLogoVNU(280);
			time--;
		}
		for (loop=0; loop<2; loop++)
		{
			for (i=280; i!=279; i++)
			{
				time=5000;
				while(time<=5000)
				{
					DisplayLogoVNU(i);
					time--;
				}
				if (i==363)
					i=0;
			}
		}
		time=1000000;
		while(time>0)
		{
			DisplayLogoVNU(280);
			time--;
		}
		
		// display word "WE ARE" and " UIT"
		time=750000;
		while(time>0)
		{
			DisplayWordGlobe(320,"","WE ARE"," UIT","","");
			time--;
		}
		for (loop=0; loop<2; loop++)
		{
			for (i=320; i!=321; i--)
			{
				time=3000;
				while(time<=3000)
				{
					DisplayWordGlobe(i,"","WE ARE"," UIT","","");
					time--;
				}
				if (i==1)
					i=363;
			}
		}
		
		// display logo UIT
		time=1000000;
		while(time>0)
		{
			DisplayLogoUIT(320);
			time--;
		}
		for (loop=0; loop<2; loop++)
		{
			for (i=320; i!=319; i++)
			{
				time=5000;
				while(time<=5000)
				{
					DisplayLogoUIT(i);
					time--;
				}
				if (i==363)
					i=0;
			}
		}
		time=1000000;
		while(time>0)
		{
			DisplayLogoUIT(320);
			time--;
		}
		
		// display CLB CEEC
		time=1000000;
		while(time>0)
		{
			DisplayWordGlobe(330,"","CEEC","CLUB","","");
			time--;
		}
		for (loop=0; loop<1; loop++)
		{
			for (i=330; i!=331; i--)
			{
				time=2500;
				while(time<=2500)
				{
					DisplayWordGlobe(i,"","CEEC","CLUB","","");
					time--;
				}
					if (i==1)
					i=363;
			}
		}
		time=500000;
		while(time>0)
		{
			DisplayWordGlobe(330,"","CEEC","CLUB","","");
			time--;
		}
	}
}
