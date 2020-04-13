#include	"KEY.h"
#include "../../head_extern.h"
#include	"../motor/motor.h"
#include	"../comparator/comparator.h"
extern byte motor_state_temp;
extern byte motor_state_temp2;
void key_init(void)
{
	$ s1 IN,pull;
	$ s2 IN,pull;
	$ s3 IN,pull;
	$ power_full IN,pull;	
	$ power_in in,nopull;
}
byte char_cnt;
void check_charging(void)
{
	if(power_in)
	{
		f_work=0;
		motor_state=0;
		sleep_time=0;
		f_charging=1;
		speed=1;
		motor_state=1;
		motor_state_temp=99;
		if(power_full)
		{
			char_cnt++;
			if(char_cnt>100)	
			{
				char_cnt=0;
				f_charging_full=1;
			}
			
		}
		else
		{
			char_cnt=0;
		//	f_charging_full=0;
		}
	}
	else
	{
		char_cnt=0;
		f_charging=0;	
		f_charging_full=0;
	}
	
}
void key_scan(void)
{
	if(f_key_scan)
	{
		f_key_scan=0;
		check_charging();
		if(!f_charging)
		{
			s1_even();
			s2_even();
			s3_even();
			check_vol_low();
		}		
	}
}

void s1_even(void)
{
	if(s1==0)
	{
		if(S1_count<500)	S1_count++;
		if(S1_count>300&&S1_count<310) //长按
		{
			S1_count=320;
			if(f_work)
			{
				speed=1;
				motor_state=1;
				motor_state_temp=99;
			}
		
		}
	}
	else
	{
		if(S1_count>2&&S1_count<300)
		{	
			if(f_work)
			{
				f_work=0;
			}
			else
			{
				f_work=1;
			//	speed=1;
			}
			motor_state_temp=99;
		}
		S1_count=0;
	}
}

void s2_even(void)
{
	if(s2==0)
	{
		if(S2_count<250)	S2_count++;
		if(S2_count>200&&S2_count<210) //长按
		{
			S2_count=220;
		
		}
	}
	else
	{
		if(S2_count>2&&S2_count<200)
		{	
			if(f_work)
			{
				speed++;
				if(speed>8)	speed=1;
			}
		
		}
		S2_count=0;
	}
}
void s3_even(void)
{
	if(s3==0)
	{
		if(S3_count<250)	S3_count++;
		if(S3_count>200&&S3_count<210) //长按
		{
			S3_count=220;
		
		}
	}
	else
	{
		if(S3_count>2&&S3_count<200)
		{	
			if(f_work)
			{
				motor_state++;
				if(motor_state>20)motor_state=1;
				motor_state_temp=99;
			}
		
		}
		S3_count=0;
	}
}