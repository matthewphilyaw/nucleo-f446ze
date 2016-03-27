#include "main.h"

void Red_Led_On();
void Blue_Led_On();
void Green_Led_On();
void Leds_Off();

void Clear_Leds();

void (*state_table[])() = {
  Leds_Off,
  Green_Led_On,
  Blue_Led_On,
  Red_Led_On
};

typedef enum {
  LED_OFF,
  GREEN_ON,
  BLUE_ON,
  RED_ON
} state_type;

state_type current_state;

int main(void) {
  HAL_Init();
  SystemClock_Config();

  MX_GPIO_Init();
  BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);
  BSP_LED_Init(LED1);
  BSP_LED_Init(LED2);
  BSP_LED_Init(LED3);

  current_state = LED_OFF;

  while (1) {
    if (BSP_PB_GetState(BUTTON_USER) > 0) {
      state_table[current_state]();
      HAL_Delay(250);
    }
  }
}

void Clear_Leds() {
  BSP_LED_Off(LED1);
  BSP_LED_Off(LED2);
  BSP_LED_Off(LED3);
}

void Leds_Off() {
  Clear_Leds();
  BSP_LED_On(LED1);
  current_state = GREEN_ON;
}

void Green_Led_On() {
  Clear_Leds();
  BSP_LED_On(LED2);
  current_state = BLUE_ON;
}

void Blue_Led_On() {
  Clear_Leds();
  BSP_LED_On(LED3);
  current_state = RED_ON;
}

void Red_Led_On() {
  Clear_Leds();
  current_state = LED_OFF;
}
