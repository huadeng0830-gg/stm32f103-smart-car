#include "stm32f10x.h"
#include "OLED.h"
#include "Car.h"
#include "Motor.h"
#include "PWM.h"

int main(void)
{
	OLED_Init();
	PWM_Init();
	Motor_Init();
    OLED_ShowString(1, 1, "VR:       VL:");
	OLED_ShowString(2, 1, "direction:");
	while(1)
    {
//		AllForward_Speed1();
	}
}
