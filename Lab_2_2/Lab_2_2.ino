volatile int actif = 3;
const int interruptPin = 2;
void setup() {
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), isr_func, RISING);
}

void loop() {
  if(actif == 4)
    Serial.println("ok");
}

void isr_func(){
  actif = 4;
  }
