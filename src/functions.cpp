#include "functions.h"

uint32_t cnt = 0;
uint16_t pwm1_duty = 500;
uint16_t pwm2_duty = 250;
HardwareTimer *Timer2 = new HardwareTimer(TIM2);
HardwareTimer *Timer3 = new HardwareTimer(TIM3);


void stepRead(void);
void TIM2_IRQHandler(void);


//--- ISR (interrupt) Functions ---------------
void stepRead(void)
{ 
  if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_5))
  {
    __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_5);


    if(++cnt > 500)
    {
      digitalWrite(DEF_STATUS_LED_PIN, !digitalRead(DEF_STATUS_LED_PIN));
      cnt = 0;
    }
    // digitalWrite(DEF_STATUS_LED_PIN, HIGH);
  }
}

void TIM2_IRQHandler(void)
{
  if (TIM2->SR & TIM_SR_UIF)
  {
    TIM2->SR &= ~TIM_SR_UIF;  // clear interrupt flag
    // digitalWrite(DEF_STATUS_LED_PIN, !digitalRead(DEF_STATUS_LED_PIN));  
  }

  // if(++cnt >= 50)
  // {
  //   digitalWrite(DEF_STATUS_LED_PIN, HIGH);
  // }
  // else if(cnt >= 100)
  // {
  //   digitalWrite(DEF_STATUS_LED_PIN, LOW);
  //   cnt = 0;
  // }
}


void initTIM2(uint32_t freq)
{
  Timer2->setOverflow(freq, HERTZ_FORMAT);
  Timer2->attachInterrupt(TIM2_IRQHandler);
  Timer2->resume();
}

void initTIM3(uint32_t freq)
{
  Timer3->setMode(DEF_PWM1_OUT, TIMER_OUTPUT_COMPARE); // Set mode for PWM
  Timer3->setMode(DEF_PWM2_OUT, TIMER_OUTPUT_COMPARE); // Set mode for PWM

  Timer3->setOverflow(freq, HERTZ_FORMAT); // Set the timer overflow (1000 = 1 kHz)

  Timer3->setCaptureCompare(DEF_PWM1_OUT, pwm1_duty); // Set the initial duty cycle (0-1000)
  Timer3->setCaptureCompare(DEF_PWM2_OUT, pwm2_duty); // Set the initial duty cycle (0-1000)

  Timer3->resume(); // Start the timer
}
