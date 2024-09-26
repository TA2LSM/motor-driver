#ifndef _MAIN_H__
#define _MAIN_H__

#include <Arduino.h>

// --- Defaults ---------------------------------------
// --- Inputs ---
#define DEF_MOTOR1_ENC_A_PIN                    PA6
#define DEF_MOTOR1_ENC_B_PIN                    PA7
#define DEF_MOTOR1_DIR_PIN                      PA8
#define DEF_MOTOR1_STEP_PIN                     PA5

// --- Outputs ---
#define DEF_PWM1_OUT                            PB0
#define DEF_PWM2_OUT                            PB1

#define DEF_STATUS_LED_PIN                      PC13



#define DEF_LED_DRIVE_LOW
#ifdef DEF_LED_DRIVE_LOW
  #define DEF_LED_OFF                           HIGH
  #define DEF_LED_ON                            LOW
#else
  #define DEF_LED_OFF                           LOW
  #define DEF_LED_ON                            HIGH
#endif
#endif
