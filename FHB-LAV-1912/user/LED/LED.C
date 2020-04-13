#include	"led.h"
#include "../../head_extern.h"
#include	"../key/key.h"
#include	"../motor/motor.h"
#define led_on	1
#define led_off 0
void led_init(void)
{ 
	$ led_blue out,low;
	$ led_blue2 out,low;
	led_blue=led_off;
	led_blue2=led_off;
}

void led_even(void)
{
	blue_even();
}
void blue_even(void)
{
	if(f_charging)
	{
		if(f_charging_full)
		{
			led_blue=led_off;
		}
		else
		{
		//	if(motor_time<1953)
			{
				led_blue=led_on;
			}
	//		else if(motor_time<1953*2)
			{
	//			led_blue=led_off;
			}
	//		else
			{
		//		motor_time=0;
			}
			
		}
	}
	else
	{
		if(f_work)
		{
			if(motor_state)
			{
				if(motor_pin) led_blue=led_on;
				else			led_blue=led_off;
			}
			else
			{
				led_blue=led_on;
			}
		}
		else
		{
			led_blue=led_off;
		}
	}
	
}
