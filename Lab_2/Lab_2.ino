volatile int state = LOW;
const int interruptPin = 2;
void setup() {

  Serial.begin(9600);
   pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), isr_func, RISING);
}

void loop() {
  int i = 0;

  while(1){
    Serial.println(i);
    delay(1000);
    i++;
    }
}

void isr_func(){
  state = !state;
  }
