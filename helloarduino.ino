int switchState = 0;
int delayState = 1000;
int decrementDelayState = 100;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2);
  if (switchState == LOW) {

    if (delayState == 100) {
      decrementDelayState = 1;
    }

    if (delayState == 50) {
      decrementDelayState = 0;
    }

    digitalWrite(5, HIGH);
    digitalWrite(3, LOW);

    delay(delayState);

    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay(delayState);
    
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);

    delay(delayState);

    delayState = delayState - decrementDelayState;
        
  } else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

    delayState = 1000;
    decrementDelayState = 100;
  }
}
