//Arduino language (C++)

//#include <Arduino.h>

unsigned long old_time = 0;
bool state = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long new_time = millis();
//  Serial.print(new_time);
//  Serial.print("   ");
//  Serial.println(old_time);
  if ((new_time - old_time) > 500) {
    state = !state;
    digitalWrite(LED_BUILTIN, state);
    old_time = new_time;
    Serial.print("LED state = ");
    Serial.println(state);
    Serial.print("New time = ");
    Serial.println(new_time);
  }
}