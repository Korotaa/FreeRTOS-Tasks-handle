#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include "driver/gpio.h"

void xTask1(void *parameter);
void xTask2(void *parameter);
void xTask3(void *parameter);


void app_main() 
{
    
}