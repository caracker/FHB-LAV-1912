#ifndef __HEAD_H
#define __HEAD_H	

//*************************************************//
//�����Ķ��壬�޸ı�������ͬ���޸�head_extern.h
//***********************************************//

BYTE	Sys_Flag;
BIT		f_work		:	Sys_Flag.0;		//���ػ�
BIT		f_charging	:	Sys_Flag.1;		//���
bit     f_key_scan	:	Sys_Flag.2;		//����ɨ��
bit     f_charging_full:Sys_Flag.3;		//����
byte motor_state;		//��﹤��ģʽ0~7
byte count;//T16����
byte s2_count,s3_count;//��������
word S1_count;
word motor_time;
WORD sleep_time;
byte speed,speed_temp;
#endif