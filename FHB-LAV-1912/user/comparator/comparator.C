#include	"comparator.h"
#include "../../head_extern.h"
#include	"../motor/motor.h"
void comparator_test(void);
void comparator_init(void)
{
//	(gpcs.5=0 & gpcs.4=0)		V internal R = (9+n)/32*VDD, n = gpcs[3:0] in decimal
//	(gpcs.5=1 & gpcs.4=1)		V internal R = (n+1)/32*VDD, n = gpcs[3:0] in decimal					
//	(gpcs.5=0 & gpcs.4=1)		V internal R = (n+1)/24* VDD, n = gpcs[3:0] in decimal
//	(gpcs.5=1 & gpcs.4=0)		V internal R = (9+n)/40*VDD, n = gpcs[3:0] in decimal

// gpcs = 0x20 | 8;					// choose case 3 and R=8 => 2.8V
//	gpcc = 0b1_0_00_010_0;			 // 启用比较器, 负输入=band-gap, 正输入=Vinternal R
//	$ gpcs = 0b1_0_10_1000;
		/*	At bit 5 ~ 0, you can use the follow items
				VDD*(9~24)/32
				VDD*(1~16)/24
				VDD*(9~24)/40
				VDD*(1~16)/32

                        Ex :    $ GPCS  Output, VDD*15/32
                                $ GPCS  Output, VDD/2
		*/
	$ gpcs   VDD*13/32;
//	$ gpcs  VDD*9/24;    	//3.3v
//	$ gpcs  VDD*16/40;   	 //3.0v
	$ gpcc  Enable, BANDGAP,P_R;  // 启用比较器, 负输入=band-gap, 正输入=Vinternal R
/*
	$ pa.7 out,low;
	while(1)
	{
		comparator_test();
	}
*/	
}
void vol_int(void)
{

	$ gpcs  VDD*8/24;    	//3.6v
	$ gpcc  Enable, BANDGAP,P_R; 
}
byte low_cnt;
void check_vol_low(void)
{
	if(!f_charging)
	{
		if(f_work)
		{
			$ gpcs   VDD*13/32;
			if(gpcc.6 )  //VDD大于3.0v
			{
				low_cnt=0;

			}
			else	//VDD小于3.0v
			{
				low_cnt++;
				if(low_cnt>100)
				{
					low_cnt=0;
					f_work=0;
				}
			}
		}
		else
		{
			low_cnt=0;
		}
	}
	else
	{
		low_cnt=0;
	}
}
void comparator_test(void)
{
	if(gpcc.6 )  //VDD大于3.6v
	{
		pa.7=1;

	}
	else	//VDD小于3.6v
	{
		pa.7=0;
	}
}