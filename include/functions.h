#ifndef _FUNCTIONS_H__
#define _FUNCTIONS_H__

#include "main.h"

#define HAL_TIM_MODULE_ENABLED

// --- Externs ---
extern void stepRead(void);
extern void initTIM2(uint32_t freq);
extern void initTIM3(uint32_t freq);


#endif
