/*==============================================================================
 Nom:      COULIBALY Korota Arsène
 Filière : Systèmes embarqués et info indus.
  ==============================================================================
 */

#include <Arduino_FreeRTOS.h>

#define led1 10
#define led2 11
#define led3 12

void myTask1(void *pvParameters);
void myTask2(void *pvParameters);
void myTask3(void *pvParameters);

void setup() {
  //initialisation du port série avec 9600 baud rate
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  //Creéation d'une tache rtos
  xTaskCreate(myTask1,//pointeur vers la définition de fonction de la tache
              "my Task1",  //le nom de la tâche 
              1000,       // La taille de la pile
              NULL,       //Paramètre de la fonction tâche
              1,          //La priorité
              NULL        //Le descripteur de tâche.
              );
  xTaskCreate(myTask2,//pointeur vers la définition de fonction de la tache
              "my Task2",  //le nom de la tâche 
              1000,       // La taille de la pile
              NULL,       //Paramètre de la fonction tâche
              1,          //La priorité
              NULL        //Le descripteur de tâche.
              );
              
  xTaskCreate(myTask3,//pointeur vers la définition de fonction de la tache
              "my Task3",  //le nom de la tâche 
              1000,       // La taille de la pile
              NULL,       //Paramètre de la fonction tâche
              1,          //La priorité
              NULL        //Le descripteur de tâche.
              );
  vTaskStartScheduler();

}

void loop() {}

//Fonction appélée par la tache1.
void myTask1(void *pvParameters)
{
  while(1)
  {
    Serial.println("This is my Task1");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    //Période d'exécution de la tache 1s
    vTaskDelay(100/portTICK_PERIOD_MS);
  }
}
//Fonction appélée par la tache2.
void myTask2(void *pvParameters)
{
  while(1)
  {
    Serial.println("This is my Task2");
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    //Période d'exécution de la tache 1s
    vTaskDelay(110/portTICK_PERIOD_MS);
  }
}

//Fonction appélée par la tache2.
void myTask3(void *pvParameters
{
  while(1)
  {
    Serial.println(F("This is my Task3"));
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    //Période d'exécution de la tache3 1s
     vTaskDelay(120/portTICK_PERIOD_MS);
  }
}
