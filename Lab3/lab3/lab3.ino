#include <Arduino_FreeRTOS.h>

void myTask(void *pvParameters);

void setup() {
  //initialisation du port série avec 9600 baud rate
  Serial.begin(9600);
  //Creéation d'une tache rtos
  xTaskCreate(myTask,//pointeur vers la définition de fonction de la tache
              "my Task",  //le nom de la tâche 
              1000,       // La taille de la pile
              NULL,       //Paramètre de la fonction tâche
              1,          //La priorité
              NULL        //Le descripteur de tâche.
              );
  vTaskStartScheduler();

}

void loop() {

  //Affichage de la tache arduino
  Serial.println("This is Arduino Task");
  delay(1000);

}

//Fonction appélée par la tache.
void myTask(void *pvParameters)
{
  while(1)
  {
    Serial.println("This is my Task");
    //Période d'exécution de la tache 1s
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}
