#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "PWM.h"
#include "Car.h"
#include "OLED.h"
#include "Car.h"

void duty(uint16_t SetDuty)			//同速度占空比设置
{
	PWM_SetCompare1(SetDuty);
	PWM_SetCompare2(SetDuty);
	PWM_SetCompare3(SetDuty);
	PWM_SetCompare4(SetDuty);
}
void Stop(void)
{
	duty(0);
}

void Forwardspeed(uint16_t right, uint16_t left)
{
	Stop();
	PWM_SetCompare1(right);//右前轮速度
	PWM_SetCompare2(right);//右后轮速度
	PWM_SetCompare3(left);//左前轮速度
	PWM_SetCompare4(left);//左后轮速度
	Motor_M1_Forward();
	Motor_M2_Forward();
	Motor_M3_Forward();
	Motor_M4_Forward();
}


void AllForward_Speed1(void)
{
	Forwardspeed(60, 60);
}

void AllForward_Speed2(void)
{
	Forwardspeed(80, 80);
}

void AllForward_Speed3(void)
{
	Forwardspeed(100, 100);
}

void AllBackward(void)
{
	Stop();
    Motor_M1_Backward(); 
	Motor_M2_Backward();
    Motor_M3_Backward();
	Motor_M4_Backward();
    duty(50);
}

void Rightturn(void)
{
	Forwardspeed(40, 70);
}

void Leftturn(void)
{
	Forwardspeed(70, 40);
}

void SL(void)			//左移
{
	Motor_M1_Forward();
	Motor_M2_Backward();
	Motor_M3_Backward();
	Motor_M4_Forward();
	duty(50);
}

void SR(void)			//右移
{
	Motor_M1_Backward();
	Motor_M2_Forward();
	Motor_M3_Forward();
	Motor_M4_Backward();
	duty(50);
}

void IPL(void)			//原地左旋（逆时针）
{
	Motor_M1_Forward();
	Motor_M2_Forward();
	Motor_M3_Backward();
	Motor_M4_Backward();
	duty(50);
}

void IPR(void)			//原地右旋（顺时针）
{
	Motor_M1_Backward();
	Motor_M2_Backward();
	Motor_M3_Forward();
	Motor_M4_Forward();
	duty(50);
}
