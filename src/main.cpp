/**
 * @file main.cpp
 * @author Semih SENOL (semihsenol@gmail.com)
 * @brief WiFi Module Configuration Software for EXT-TRLIGHTCTRL-02 Controller Board
 * @version 1.0.0
 * @date 22 Aug 2024
 * 
 * @copyright Pulsar Elektronik San. ve Tic. Ltd. Sti. Copyright (C) 2024. See: license/license.txt
 * @link http://creativecommons.org/licenses/by-nc-sa/4.0/
 */

//---------------- User Libraries ------------------
#include "main.h"


//--------------------------------------------------
// uint32_t wdtCnt = 0;
uint32_t task100msCnt = 0;
uint32_t task500msCnt = 0;
uint32_t task1000msCnt = 0;
uint32_t task3000msCnt = 0;
uint32_t task1minCnt = 0;


// ---------------- Main Setup Function ---------------
void setup(void)
{
  //--- Disable WDT -----------
  // #if defined(ESP8266)
  //   ESP.wdtDisable();
  // #elif defined(ESP32)
  //   esp_task_wdt_deinit();
  // #endif
  //---------------------------
         
  // Pin modes at startup
  pinMode(DEF_MOTOR1_ENC_A_PIN, INPUT);
  pinMode(DEF_MOTOR1_ENC_B_PIN, INPUT);
  pinMode(DEF_MOTOR1_DIR_PIN, INPUT);
  pinMode(DEF_MOTOR1_STEP_PIN, INPUT);

  pinMode(DEF_PWM1_OUT, OUTPUT);
  pinMode(DEF_PWM2_OUT, OUTPUT);
  pinMode(DEF_STATUS_LED_PIN, OUTPUT);

  // Interrupts
  // attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonRead, FALLING); // 16 no'lu pin interrupt yapılamaz

  // Pin outputs at startup
  digitalWrite(DEF_PWM1_OUT, LOW);
  digitalWrite(DEF_PWM2_OUT, LOW);
  digitalWrite(DEF_STATUS_LED_PIN, LOW);

  //--- Enable WDT -----------
  // #if defined(ESP8266)
  //   ESP.wdtEnable(DEF_WATCHDOG_TIMER_TIMEOUT);  // enable WDT
  //   ESP.wdtFeed();  // reset WD counter   
  // #elif defined(ESP32)
  //   esp_task_wdt_init(DEF_WATCHDOG_TIMER_TIMEOUT, true);  //enable panic so ESP32 restarts
  //   esp_task_wdt_add(NULL);                               //add current thread to WDT watch  
  // #endif
  
  delay(500);
  //--------------------------
}

//----------------- Main Loop -------------------------
void loop(void)
{ 
  //--- Fastest operations ----------------


  //--- Clear WDT --------------------------
  // if( millis() - wdtCnt >= 500 )
  // {
  //   #if defined(ESP8266)
  //     ESP.wdtFeed();
  //   #elif defined(ESP32)
  //     esp_task_wdt_reset();
  //   #endif

  //   #ifdef SERIAL_DEBUG
  //     // Serial.printf("\nResetting WDT...");
  //   #endif

  //   wdtCnt = millis();
  // }

  //--- Time based tasks ------------------
  if( millis() - task100msCnt >= 100)     // 100ms
  {
    task100msCnt = millis();

  }

  //---------------------------------------
  if( millis() - task500msCnt >= 500)     // 500ms
  {
    task500msCnt = millis();
   

  }

  //---------------------------------------
  if( millis() - task1000msCnt >= 1000)   // 1 second
  {
    task1000msCnt = millis();

    digitalWrite(DEF_STATUS_LED_PIN, !digitalRead(DEF_STATUS_LED_PIN));
  }

  //---------------------------------------
  // if( millis() - task3000msCnt >= 3000)   // 3 seconds
  // {
  //   task3000msCnt = millis();

  // }

  //---------------------------------------
  if( millis() - task1minCnt >= 60000)    // 1 minute
  {
    task1minCnt = millis();


  }
}
