#include<Arduino_FreeRTOS.h>

void setup() {
  
  // put your setup code here, to run once:
    Serial.begin(9600);
    xTaskCreate(Task1, "Led1", 100, NULL, 1, NULL);
    xTaskCreate(Task2, "Led2", 100, NULL, 2, NULL);
}

void loop() {}

void Task1()
{
    while(1)
    {
      Serial.println("Task1 is running...");
      digitalWrite(13,digitalRead(2)); 
    }
}

void Task2()
{
    while(1)
    {
      Serial.println("Task2 is running...");
      digitalWrite(12,digitalRead(3)); 
    }
}

 
