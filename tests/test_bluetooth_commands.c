/* Run the real main loop and car actions with host-side peripheral stubs. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __STM32F10x_H
static struct { uint32_t CCR1, CCR2, CCR3, CCR4; } timer;
#define TIM2 (&timer)

#include "../Hardware/Car.c"
#define main FirmwareMain
#include "../User/main.c"
#undef main

static const struct {
    char command;
    int direction[4]; /* M1 right-front, M2 right-rear, M3 left-front, M4 left-rear. */
    uint16_t right, left;
    const char *display;
    int updates;
} steps[] = {
    {'S', { 0,  0,  0,  0},   0,   0, "STOP    ",  1},
    {'1', { 1,  1,  1,  1},  60,  72, "FORWARD1",  2},
    {'A', { 1, -1, -1,  1}, 100, 100, "SLIDE_L ",  3},
    {'?', { 1, -1, -1,  1}, 100, 100, "SLIDE_L ",  3},
    {'D', {-1,  1,  1, -1}, 100, 100, "SLIDE_R ",  4},
    {'Q', { 1,  1, -1, -1}, 100, 100, "CCW     ",  5},
    {'E', {-1, -1,  1,  1}, 100, 100, "CW      ",  6},
    {'E', {-1, -1,  1,  1}, 100, 100, "CW      ",  7},
    {'S', {-1, -1,  1,  1},   0,   0, "STOP    ",  8},
    {'2', { 1,  1,  1,  1},  80,  92, "FORWARD2",  9},
    {'B', {-1, -1, -1, -1},  60,  60, "BACKWARD", 10},
    {'L', { 1,  1,  1,  1},  70,  50, "LEFT    ", 11},
    {'R', { 1,  1,  1,  1},  50,  70, "RIGHT   ", 12},
    {'3', { 1,  1,  1,  1}, 100, 100, "FORWARD3", 13},
    {'q', { 1,  1,  1,  1}, 100, 100, "FORWARD3", 13},
    {'\r',{ 1,  1,  1,  1}, 100, 100, "FORWARD3", 13},
    {'S', { 1,  1,  1,  1},   0,   0, "STOP    ", 14}
};

static size_t next_step;
static int motor_direction[4];
static char display[9];
static int display_updates, number_updates;
static int require_zero_pwm;

static void SetMotorDirection(unsigned int motor, int direction)
{
    if (require_zero_pwm) {
        assert(timer.CCR1 == 0 && timer.CCR2 == 0);
        assert(timer.CCR3 == 0 && timer.CCR4 == 0);
    }
    motor_direction[motor] = direction;
}

void Motor_Init(void) {}
void Motor_M1_Forward(void)  { SetMotorDirection(0,  1); }
void Motor_M1_Backward(void) { SetMotorDirection(0, -1); }
void Motor_M2_Forward(void)  { SetMotorDirection(1,  1); }
void Motor_M2_Backward(void) { SetMotorDirection(1, -1); }
void Motor_M3_Forward(void)  { SetMotorDirection(2,  1); }
void Motor_M3_Backward(void) { SetMotorDirection(2, -1); }
void Motor_M4_Forward(void)  { SetMotorDirection(3,  1); }
void Motor_M4_Backward(void) { SetMotorDirection(3, -1); }
void PWM_Init(void) {}
void PWM_SetCompare1(uint16_t value) { timer.CCR1 = value; }
void PWM_SetCompare2(uint16_t value) { timer.CCR2 = value; }
void PWM_SetCompare3(uint16_t value) { timer.CCR3 = value; }
void PWM_SetCompare4(uint16_t value) { timer.CCR4 = value; }
void OLED_Init(void) {}
void HC05_Init(void) {}

void OLED_ShowString(uint8_t line, uint8_t column, char *text)
{
    if (line == 1) {
        assert(column == 1 && strcmp(text, "VR:000    VL:000") == 0);
        return;
    }
    assert(line == 2);
    if (column == 1) {
        assert(strcmp(text, "Dir:STOP    ") == 0);
        strcpy(display, text + 4);
        return;
    }
    assert(column == 5 && strlen(text) == 8);
    strcpy(display, text);
    display_updates++;
}

void OLED_ShowNum(uint8_t line, uint8_t column, uint32_t value, uint8_t length)
{
    assert(line == 1 && length == 3);
    assert(column == 4 || column == 14);
    assert(value == (column == 4 ? timer.CCR1 : timer.CCR3));
    number_updates++;
}

uint8_t HC05_ReceiveData(uint8_t *data)
{
    if (next_step > 0) {
        size_t previous = next_step - 1;
        assert(memcmp(motor_direction, steps[previous].direction, sizeof motor_direction) == 0);
        assert(timer.CCR1 == steps[previous].right && timer.CCR2 == steps[previous].right);
        assert(timer.CCR3 == steps[previous].left && timer.CCR4 == steps[previous].left);
        assert(strcmp(display, steps[previous].display) == 0);
        assert(display_updates == steps[previous].updates);
        assert(number_updates == 2 * steps[previous].updates);
    }
    if (next_step == sizeof steps / sizeof steps[0]) {
        puts("PASS: 11 commands, transitions, repeated and invalid input, PWM and OLED output");
        exit(EXIT_SUCCESS);
    }
    *data = (uint8_t)steps[next_step++].command;
    require_zero_pwm = strchr("ADQE", *data) != NULL;
    return 1;
}

int main(void)
{
    return FirmwareMain();
}
