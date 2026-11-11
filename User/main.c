#include "stm32f10x.h"
#include "OLED.h"
#include "Car.h"
#include "Motor.h"
#include "PWM.h"
#include "HC-05.h"

int main(void)
{
	uint8_t Command;
	char *Direction = "STOP    ";

	OLED_Init();
	PWM_Init();
	Motor_Init();
	HC05_Init();
    OLED_ShowString(1, 1, "VR:000    VL:000");
	OLED_ShowString(2, 1, "Dir:STOP    ");
	while(1)
    {
		if (HC05_ReceiveData(&Command))
		{
			/* Send single ASCII characters: 1/2/3, B, L/R, A/D, Q/E, S. */
			switch (Command)
			{
				case '1':
					AllForward_Speed1();
					Direction = "FORWARD1";
					break;
				case '2':
					AllForward_Speed2();
					Direction = "FORWARD2";
					break;
				case '3':
					AllForward_Speed3();
					Direction = "FORWARD3";
					break;
				case 'B':
					AllBackward();
					Direction = "BACKWARD";
					break;
				case 'L':
					Leftturn();
					Direction = "LEFT    ";
					break;
				case 'R':
					Rightturn();
					Direction = "RIGHT   ";
					break;
				case 'A':
					Stop();
					SL();
					Direction = "SLIDE_L ";
					break;
				case 'D':
					Stop();
					SR();
					Direction = "SLIDE_R ";
					break;
				case 'Q':
					Stop();
					IPL();
					Direction = "CCW     ";
					break;
				case 'E':
					Stop();
					IPR();
					Direction = "CW      ";
					break;
				case 'S':
					Stop();
					Direction = "STOP    ";
					break;
				default:
					continue;
			}
			OLED_ShowNum(1, 4, TIM2->CCR1, 3);
			OLED_ShowNum(1, 14, TIM2->CCR3, 3);
			OLED_ShowString(2, 5, Direction);
		}
	}
}
