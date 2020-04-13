void motor_init(void);
void motor_even(void);

#define motor_on 	tm2c = 0b_0001_10_1_0;	 // 系统时钟, 输出 = Pb2, PWM 模式
#define motor_off 	tm2c = 0b_0001_00_1_0;	 // 系统时钟, 输出 = Pb2, PWM 模式

#define motor2_on	pwmg1c=0B_0_0_0_0_011_0;	 //PA4
#define motor2_off 	pwmg1c=0B_0_0_0_0_000_0;


void motor_init2(void);


motor_pin equ pa.3
motor2_pin equ pa.4