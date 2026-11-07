#ifndef __HC_05_H
#define __HC_05_H

#include <stdint.h>

/* USART1, 9600 8N1: PA9 -> HC-05 RXD, PA10 <- HC-05 TXD. */
void HC05_Init(void);
uint8_t HC05_ReceiveData(uint8_t *Data);

#endif
