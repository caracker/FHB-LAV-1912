
#include	"motor.h"
#include "../../head_extern.h"
#include	"../key/key.h"
/************************************************************************
*	PWM输出频率= FIHRC ÷ [ CB +1 ]
*	PWM输出占空比（实时） = (1/FIHRC) * [ DB10_1 + DB0 * 0.5 + 0.5]
*	这里 Duty_Bound[10:1] = {pwmgxdth[7:0],pwmgxdtl[7:6]} = DB10_1; 是占空比
*	Duty_Bound[0] = pwmgxdtl[5] = DB0
*	Counter_Bound[10:1] = {pwmgcubh[7:0], pwmgcubl[7:6]} = CB; 是计数器上限
**************************************************************************/


//M1 PA3
void motor_init(void)
{ 
	tm2ct=0;
	tm2b = 127;			 //上限寄存器    k=127
	tm2c = 0b_0001_00_1_0;	 // 系统时钟, 输出 = Pb2, PWM 模式
	tm2s = 0b_0011_1001;	 // 8位pwm:256, 预分频 = 1, 分频 = 2   S1=1  S2=1
//	tm2s = 0b_0011_1001;
	motor_off;
//	while(1)
	{
//		motor_on;
		nop;
	}
}

byte motor_state_temp;
word step;
void motor_mode1(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		motor_on;
	}
}
//模式二：[1(500ms)-0(500ms)]4次-1（2543ms）-0(500ms)
void motor_mode2(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<4)
	{
		if(motor_time<1953)
		{
			motor_on;
		}
		else if(motor_time<1953*2)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}

	}
	else
	{
		if(motor_time<9933)
		{
			motor_on;
		}
		else if(motor_time<11886)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
//模式三：[1(340ms)-0(340ms)]3次-1（3153ms）-0(340ms)
void motor_mode3(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<3)
	{
		if(motor_time<1328)
		{
			motor_on;
		}
		else if(motor_time<1328*2)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}

	}
	else
	{
		if(motor_time<12316)
		{
			motor_on;
		}
		else if(motor_time<13644)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
//模式四：[1(76ms)-0(100ms)]23次-1（2035ms）-0(88ms)
void motor_mode4(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<23)
	{
		if(motor_time<296)
		{
			motor_on;
		}
		else if(motor_time<686)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}

	}
	else
	{
		if(motor_time<7949)
		{
			motor_on;
		}
		else if(motor_time<8292)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
void motor_mode5(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(motor_time<546)
	{
		motor_on;
	}
	else if(motor_time<1721)
	{
		motor_off;
	}
	else
	{
		motor_time=0;
	}
}
//模式六：[1(178ms)-0(200ms)]3次-1（686ms）-0(188ms)
void motor_mode6(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<3)
	{
		if(motor_time<695)
		{
			motor_on;
		}
		else if(motor_time<1476)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}

	}
	else
	{
		if(motor_time<2679)
		{
			motor_on;
		}
		else if(motor_time<3413)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
//模式七：[1(51ms)-0(75ms)]18次-1（1424ms）-0(63ms)
void motor_mode7(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<18)
	{
		if(motor_time<199)
		{
			motor_on;
		}
		else if(motor_time<491)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else
	{
		if(motor_time<5562)
		{
			motor_on;
		}
		else if(motor_time<5808)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
//模式八：[1(242ms)-0(263ms)]23次-1（2798ms）-0(251ms)
void motor_mode8(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<23)
	{
		if(motor_time<945)
		{
			motor_on;
		}
		else if(motor_time<1972)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else
	{
		if(motor_time<10929)
		{
			motor_on;
		}
		else if(motor_time<11909)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
void motor_mode9(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<23)
	{
		if(motor_time<945)
		{
			motor_on;
		}
		else if(motor_time<1972)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else
	{
		if(motor_time<10929)
		{
			motor_on;
		}
		else if(motor_time<11909)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}


//模式十：[1(254ms)-0(251ms)]23次-1（2801ms）-0(201ms)-[1(202ms)-0(202ms)]3次-1(611ms)-0(50ms)-[1(38ms)-0(63ms)]18次-1(1896ms)-0(251ms)
void motor_mode10(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<23)
	{
		if(motor_time<992)
		{
			motor_on;
		}
		else if(motor_time<1972)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else if(step<24)
	{
		if(motor_time<10941)
		{
			motor_on;
		}
		else if(motor_time<11726)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else if(step<27)
	{
		if(motor_time<789)
		{
			motor_on;
		}
		else if(motor_time<789*2)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else if(step<28)
	{
		if(motor_time<2386)
		{
			motor_on;
		}
		else if(motor_time<2581)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else if(step<46)
	{
		if(motor_time<148)
		{
			motor_on;
		}
		else if(motor_time<394)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else
	{
		if(motor_time<7406)
		{
			motor_on;
		}
		else if(motor_time<8386)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
//模式十一：[1(496ms)-0(515ms)]4次-1(1018ms)-0(502ms)
void motor_mode11(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<4)
	{
		if(motor_time<1937)
		{
			motor_on;
		}
		else if(motor_time<3948)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else
	{
		if(motor_time<3976)
		{
			motor_on;
		}
		else if(motor_time<5936)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
//模式十二：[1(331ms)-0(352ms)]3次-1(877ms)-0(339ms)
void motor_mode12(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<3)
	{
		if(motor_time<1292)
		{
			motor_on;
		}
		else if(motor_time<2667)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else
	{
		if(motor_time<3425)
		{
			motor_on;
		}
		else if(motor_time<4749)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
//模式十三：[1(63ms)-0(88ms)]23次-1(508ms)-0(75ms)
void motor_mode13(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<23)
	{
		if(motor_time<246)
		{
			motor_on;
		}
		else if(motor_time<589)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else
	{
		if(motor_time<1984)
		{
			motor_on;
		}
		else if(motor_time<2276)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
//模式十四：[1(127ms)-0(301ms)]7次-1(712ms)-0(289ms)
void motor_mode14(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<7)
	{
		if(motor_time<496)
		{
			motor_on;
		}
		else if(motor_time<1671)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else
	{
		if(motor_time<2781)
		{
			motor_on;
		}
		else if(motor_time<3909)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
//模式十五：1（191ms）-0(213ms)
void motor_mode15(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}

	if(motor_time<746)
	{
		motor_on;
	}
	else if(motor_time<1578)
	{
		motor_off;
	}
	else
	{
		step=0;
		motor_time=0;
	}
}
//模式十六：[1（51ms）-0(75ms)]255次-1(3257ms)-0(63ms)
void motor_mode16(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<255)
	{
		if(motor_time<199)
		{
			motor_on;
		}
		else if(motor_time<491)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else
	{
		if(motor_time<12722)
		{
			motor_on;
		}
		else if(motor_time<12968)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
//模式十七：[1（242ms）-0(264ms)]255次-1(3258ms)-0(251ms)
void motor_mode17(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<255)
	{
		if(motor_time<945)
		{
			motor_on;
		}
		else if(motor_time<1031)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else
	{
		if(motor_time<12726)
		{
			motor_on;
		}
		else if(motor_time<13706)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
//模式十八：[1（134ms）-0(326ms)]3次-1(1018ms)-0(553ms)-[1（547ms）-0(566ms)]4次-1(738ms)-0(327ms)
void motor_mode18(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<3)
	{
		if(motor_time<523)
		{
			motor_on;
		}
		else if(motor_time<1796)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else if(step<4)
	{
		if(motor_time<3976)
		{
			motor_on;
		}
		else if(motor_time<6136)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else if(step<8)
	{
		if(motor_time<2136)
		{
			motor_on;
		}
		else if(motor_time<4346)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else
	{
		if(motor_time<2882)
		{
			motor_on;
		}
		else if(motor_time<4159)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
//模式十九：[1（76ms）-0(100ms)]24次-1(662ms)-0(289ms)-[1（134ms）-0(289ms)]7次-1(674ms)-0(88ms)
void motor_mode19(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<24)
	{
		if(motor_time<296)
		{
			motor_on;
		}
		else if(motor_time<686)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else if(step<25)
	{
		if(motor_time<2585)
		{
			motor_on;
		}
		else if(motor_time<3713)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else if(step<32)
	{
		if(motor_time<523)
		{
			motor_on;
		}
		else if(motor_time<1651)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else
	{
		if(motor_time<2632)
		{
			motor_on;
		}
		else if(motor_time<2975)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
//模式二十：[1（38ms）-0(88ms)]19次-[1(191ms)-0(188ms)]3次-1(191ms)-0(75ms)
void motor_mode20(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		step=0;
		motor_time=0;	
		motor_on;
	}
	if(step<19)
	{
		if(motor_time<148)
		{
			motor_on;
		}
		else if(motor_time<491)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else if(step<22)
	{
		if(motor_time<746)
		{
			motor_on;
		}
		else if(motor_time<1480)
		{
			motor_off;
		}
		else
		{
			step++;
			motor_time=0;
		}
	}
	else
	{
		if(motor_time<746)
		{
			motor_on;
		}
		else if(motor_time<1038)
		{
			motor_off;
		}
		else
		{
			step=0;
			motor_time=0;
		}
	}
}
/*
速度一：100%


速度二： 90.8%  78hz
速度三： 82.8%  78hz
速度四： 74.8%  78hz
速度五： 66.6%  78hz
速度六： 58.6%  78hz
速度七： 50.5%  78hz
速度八： 42.6%  78hz
速度九： 34.4%  78hz
*/
void speed_choose(void)
{
	switch(speed)
	{
		case 8:
			tm2b = 255;	
			break;
		case 7:
			tm2b = 231;	
			break;
		case 6:
			tm2b = 204;	
			break;
		case 5:
			tm2b = 192;	
			break;
		case 4:
			tm2b = 179;	
			break;
		case 3:
			tm2b = 166;	
			break;
		case 2:
			tm2b = 153;	
			break;
		case 1:
			tm2b = 140;	
			break;
		case 0:
	//		tm2b = 87;	
			break;
		default:
			break;
	}
}
void motor_even(void)
{
	if(!f_charging && f_work)
	{
	//	if(f_work)
		{
			speed_choose();
			switch(motor_state) 
			{
				case 0:
					motor_off;
					break;
				case 1:
					motor_mode1();
					break;
				case 2:
					motor_mode2();
					break;
				case 3:
					motor_mode3();
					break;
				case 4:
					motor_mode4();
					break;
				case 5:
					motor_mode5();
					break;
				case 6:
					motor_mode6();
					break;
				case 7:
					motor_mode7();
					break;
				case 8:
					motor_mode8();
					break;
				case 9:
					motor_mode9();
					break;
				case 10:
					motor_mode10();
					break;
				case 11:
					motor_mode11();
					break;
				case 12:
					motor_mode12();
					break;
				case 13:
					motor_mode13();
					break;
				case 14:
					motor_mode14();
					break;
				case 15:
					motor_mode15();
					break;
				case 16:
					motor_mode16();
					break;
				case 17:
					motor_mode17();
					break;
				case 18:
					motor_mode18();
					break;
				case 19:
					motor_mode19();
					break;
				case 20:
					motor_mode20();
					break;


				default :
				//	motor_state=0;
					break;
			}
		}
	}
	else
	{
		motor_off;
	}

}