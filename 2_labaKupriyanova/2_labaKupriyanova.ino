#include <TaskManagerIO.h>
//2 лаба

int leds[] = {3, 5, 6, 9, 10, 11};
int State[] = {LOW, LOW, LOW, LOW, LOW, LOW};
int intervals[] = {500, 1000, 2000, 4000, 8000, 16000};

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
  }

  //for (int i = 0; i < 6; i++) {
  //  taskManager.scheduleFixedRate(intervals[i], [] {
  //  led(State[i], leds[i]);
  //}, TIME_MICROS);
  //}  
  taskManager.scheduleFixedRate(intervals[0], [] {
    led(State[0], leds[0]);
  }, TIME_MICROS);
  taskManager.scheduleFixedRate(intervals[1], [] {
    led(State[1], leds[1]);
  }, TIME_MICROS);
  taskManager.scheduleFixedRate(intervals[2], [] {
    led(State[2], leds[2]);
  }, TIME_MICROS);
  taskManager.scheduleFixedRate(intervals[3], [] {
    led(State[3], leds[3]);
  }, TIME_MICROS);
  taskManager.scheduleFixedRate(intervals[4], [] {
    led(State[4], leds[4]);
  }, TIME_MICROS);
  taskManager.scheduleFixedRate(intervals[5], [] {
    led(State[5], leds[5]);
  }, TIME_MICROS);
  
}

void loop() {
  taskManager.runLoop();
}

void led(int &ledState, int led)
{
  ledState = !ledState;
  digitalWrite(led, ledState);
}