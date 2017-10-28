#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "list.h"
#include "portable.h"
//#include "freertos_evr.h"

#include <stdio.h>

//#include "Board_LED.h"                  // ::Board Support:LED
//#include "Board_Buttons.h"              // ::Board Support:Buttons

#include "MKW41Z4.h"                    // Device header

static void led3_task(void *pvParameters);
static void led4_task(void *pvParameters);

/*************************************************************************
*****************************************************************************/
int32_t  LED_Initialize   (void);
int32_t  LED_Uninitialize (void);
int32_t  LED_On           (uint32_t num);
int32_t  LED_Off          (uint32_t num);
#define NUM_LEDS  (4)                   // Number of available LEDs
                           /*   rgb_red,   rgb_blue,  rgb_green,        red */
const uint32_t led_pin[]  = {         1,         18,         19,          0};
const uint32_t led_port[] = {PORTC_BASE, PORTA_BASE, PORTA_BASE, PORTB_BASE};
const uint32_t led_gpio[] = {GPIOC_BASE, GPIOA_BASE, GPIOA_BASE, GPIOB_BASE};


int main(void)
{
    LED_Initialize();
    xTaskCreate(led3_task,"LED_D3",1000,NULL,tskIDLE_PRIORITY+3,NULL);
    xTaskCreate(led4_task,"LED_D4",configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY+3,NULL);
    
    vTaskStartScheduler();
    for (;;);
}

void led3_task(void *pvParameters)
{
    while(1)
    {
        LED_On(3);
        vTaskDelay(500/portTICK_PERIOD_MS);
        LED_Off(3);
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
}

void led4_task(void *pvParameters)
{
    while(1)
    {
        LED_On(1);
        vTaskDelay(2000/portTICK_PERIOD_MS);
        LED_Off(1);
        vTaskDelay(2000/portTICK_PERIOD_MS);
    }
}

/*************************************************************************
*****************************************************************************/
/**
  \fn          int32_t LED_Initialize (void)
  \brief       Initialize LEDs
  \returns
   - \b  0: function succeeded
   - \b -1: function failed
*/
int32_t LED_Initialize (void) {
  uint32_t i;

  SIM->SCGC5 |= ((1U << SIM_SCGC5_PORTA_SHIFT) |
                 (1U << SIM_SCGC5_PORTB_SHIFT) |
                 (1U << SIM_SCGC5_PORTC_SHIFT)  );

  /* Port Initialization */
  for (i = 0; i < NUM_LEDS; i++) {
    ((PORT_Type *)led_port[i])->PCR[led_pin[i]] = (1U << 8);
    ((PORT_Type *)led_port[i])->ISFR           &= (1U << led_pin[i]);
  }

  /* GPIO Initialization */
  for (i = 0; i < NUM_LEDS; i++) {
    ((GPIO_Type *)led_gpio[i])->PDOR           |=  (1U << led_pin[i]);
    ((GPIO_Type *)led_gpio[i])->PDDR           |=  (1U << led_pin[i]);
  }

//  LED_SetOut(0);

  return 0;
}

/**
  \fn          int32_t LED_Uninitialize (void)
  \brief       De-initialize LEDs
  \returns
   - \b  0: function succeeded
   - \b -1: function failed
*/
int32_t LED_Uninitialize (void) {

  return 0;
}

/**
  \fn          int32_t LED_On (uint32_t num)
  \brief       Turn on requested LED
  \param[in]   num  LED number
  \returns
   - \b  0: function succeeded
   - \b -1: function failed
*/
int32_t LED_On (uint32_t num) {

  if (num < NUM_LEDS) {
    ((GPIO_Type *)led_gpio[num])->PCOR  =  (1U << led_pin[num]);
  }

  return 0;
}

/**
  \fn          int32_t LED_Off (uint32_t num)
  \brief       Turn off requested LED
  \param[in]   num  LED number
  \returns
   - \b  0: function succeeded
   - \b -1: function failed
*/
int32_t LED_Off (uint32_t num) {

  if (num < NUM_LEDS) {
    ((GPIO_Type *)led_gpio[num])->PSOR  =  (1U << led_pin[num]);
  }

  return 0;
}
