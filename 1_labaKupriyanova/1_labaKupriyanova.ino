//1 лаба 


int leds[] = {3, 5, 6, 9, 10, 11};
int State[] = {LOW, LOW, LOW, LOW, LOW, LOW};
int prevMillis[] = {0, 0, 0, 0, 0, 0};
int intervals[] = {500, 1000, 2000, 4000, 8000, 16000};



void setup() {
  for (int i = 0; i < 6; i++ ){
        pinMode(leds[i], OUTPUT);
      }
}

void loop() {
  
  unsigned long currentMillis = micros();
  for (int i = 0; i < 6; i++ ){
          if (currentMillis - prevMillis[i] >= intervals[i]) {
    prevMillis[i] = currentMillis;

    if (State[i] == LOW) {
      State[i] = HIGH;
    } else {
      State[i] = LOW;
    }

    digitalWrite(leds[i], State[i]);
  }
        }
  }
