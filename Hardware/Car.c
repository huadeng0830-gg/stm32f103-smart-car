#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "PWM.h"
#include "Car.h"
#include "OLED.h"

void Stop(void)
{
	PWM_SetCompare1(0);
	PWM_SetCompare2(0);
	PWM_SetCompare3(0);
	PWM_SetCompare4(0);
	OLED_ShowString(1, 4, "00");
	OLED_ShowString(1, 14, "00");
	OLED_ShowString(2, 11, "None");
}
void AllForward_Speed1(void)
{
	PWM_SetCompare1(60);
	PWM_SetCompare2(60);
	PWM_SetCompare3(60);
	PWM_SetCompare4(60);
	Motor_M1_Forward();
	Motor_M2_Forward();
	Motor_M3_Forward();
	Motor_M4_Forward();
	OLED_ShowString(1, 4, "60");
	OLED_ShowString(1, 14, "60");
	OLED_ShowString(2, 11, "F");
}

void AllForward_Speed2(void)
{
	PWM_SetCompare1(80);
	PWM_SetCompare2(80);
	PWM_SetCompare3(80);
	PWM_SetCompare4(80);
	Motor_M1_Forward();
	Motor_M2_Forward();
	Motor_M3_Forward();
	Motor_M4_Forward();
	OLED_ShowString(1, 4, "80");
	OLED_ShowString(1, 14, "80");
	OLED_ShowString(2, 11, "F");
}

void AllForward_Speed3(void)
{
	PWM_SetCompare1(100);
	PWM_SetCompare2(100);
	PWM_SetCompare3(100);
	PWM_SetCompare4(100);
	Motor_M1_Forward();
	Motor_M2_Forward();
	Motor_M3_Forward();
	Motor_M4_Forward();
	OLED_ShowString(1, 4, "100");
	OLED_ShowString(1, 14, "100");
	OLED_ShowString(2, 11, "F");
}
void AllBackward(void)
{
	PWM_SetCompare1(50);
	PWM_SetCompare2(50);
	PWM_SetCompare3(50);
	PWM_SetCompare4(50);
	Motor_M1_Backward();
	Motor_M2_Backward();
	Motor_M3_Backward();
	Motor_M4_Backward();
	OLED_ShowString(1, 4, "50");
	OLED_ShowString(1, 14, "50");
	OLED_ShowString(2, 11, "B");
}

void Rightturn(void)
{
	PWM_SetCompare1(70);
	PWM_SetCompare2(70);
	PWM_SetCompare3(40);
	PWM_SetCompare4(40);
	Motor_M1_Forward();
	Motor_M2_Forward();
	Motor_M3_Forward();
	Motor_M4_Forward();
	OLED_ShowString(1, 4, "70");
	OLED_ShowString(1, 14, "40");
	OLED_ShowString(2, 11, "R");
}

void Leftturn(void)
{
	PWM_SetCompare1(40);
	PWM_SetCompare2(40);
	PWM_SetCompare3(70);
	PWM_SetCompare4(70);
	Motor_M1_Forward();
	Motor_M2_Forward();
	Motor_M3_Forward();
	Motor_M4_Forward();
	OLED_ShowString(1, 4, "40");
	OLED_ShowString(1, 14, "70");
	OLED_ShowString(2, 11, "L");
}
