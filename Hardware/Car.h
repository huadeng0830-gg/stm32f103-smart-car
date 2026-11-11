#ifndef __CAR_H
#define __CAR_H


void duty(uint16_t SetDuty);									//同速度占空比设置

void Stop(void);												//停止

void Forwardspeed(uint16_t right, uint16_t left);			//前进左右轮速度

void AllForward_Speed1(void);								//前进速度1

void AllForward_Speed2(void);								//前进速度2

void AllForward_Speed3(void);								//前进速度3

void AllBackward(void);										//倒车

void Rightturn(void);										//右转

void Leftturn(void);											//左转

void SL(void);												//左移

void SR(void);												//右移

void IPL(void);												//原地左旋（逆时针）

void IPR(void);												//原地右旋（顺时针）


#endif
