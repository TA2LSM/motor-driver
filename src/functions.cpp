#include "functions.h"

uint32_t cnt = 0;
HardwareTimer *Timer2 = new HardwareTimer(TIM2);


void stepRead(void);
void TIM2_IRQHandler(void);


//--- ISR (interrupt) Functions ---------------
void stepRead(void)
{ 
  if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_5))
  {
    __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_5);

    ++cnt;
    if(cnt >= 500 && cnt < 1000)
    {
      digitalWrite(DEF_STATUS_LED_PIN, DEF_LED_ON);
    }
    else if(cnt >= 1000)
    {
      digitalWrite(DEF_STATUS_LED_PIN, DEF_LED_OFF);   
      cnt = 0;  
    }

    // digitalWrite(DEF_STATUS_LED_PIN, !digitalRead(DEF_STATUS_LED_PIN));
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