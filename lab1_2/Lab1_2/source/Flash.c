#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "list.h"
#include "portable.h"
//#include "freertos_evr.h"

#include <stdio.h>

#include "Board_LED.h"                  // ::Board Support:LED
//#include "Board_Buttons.h"              // ::Board Support:Buttons

#include "MKW41Z4.h"                    // Device header

static void led3_task(void *pvParameters);
static void led4_task(void *pvParameters);

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
