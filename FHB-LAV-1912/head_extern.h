#ifndef __head_extern_H
#define __head_extern_H	

extern BYTE	Sys_Flag;
extern BIT		f_work		:	Sys_Flag.0;		//���ػ�
extern BIT		f_charging	:	Sys_Flag.1;		//���
extern bit     f_key_scan	:	Sys_Flag.2;		//����ɨ��
extern bit     f_charging_full:Sys_Flag.3;		//����
extern byte motor_state;		//��﹤��ģʽ0~7
extern byte motor_state2;
extern byte count;//T16����
extern byte s2_count,s3_count;//��������
extern word S1_count;
extern word  motor_time;
extern word motor_time2;
extern byte pwm_num;
extern word pwm_num2;
extern WORD sleep_time;
extern bit pwm_bit;
extern byte rate;
extern byte pwm_duty,pwm_cnt;
extern byte pwm_speed;   
extern byte  pwm_hz; 
extern byte led_time;
extern byte vol_low_temp;
extern  byte vol_low;
extern  bit  led_flash_flag;
extern byte speed,speed_temp;
#endif