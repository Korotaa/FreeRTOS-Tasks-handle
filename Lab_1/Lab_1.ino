int pin_LED = 12;
int pin_button = 2;
int state=LOW;
void setup() {
  pinMode(pin_LED, OUTPUT);
  pinMode(pin_button, INPUT);
  
}

void loop() {
  if(digitalRead(pin_button)== HIGH)
    state=!state;
  digitalWrite(pin_LED, state);
}
