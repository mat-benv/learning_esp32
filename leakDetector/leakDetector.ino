#define WATER_SENSOR_PIN 25
#define BUZZER_PIN 33
int water_state;
int prev_water_state;

void setup() {
Serial.begin(9600);
pinMode(WATER_SENSOR_PIN, INPUT_PULLUP);
pinMode(BUZZER_PIN, OUTPUT);
water_state = digitalRead(WATER_SENSOR_PIN);
Serial.println("Ready.");
}

void loop() {
  prev_water_state = water_state;
  water_state = digitalRead(WATER_SENSOR_PIN);
  if(prev_water_state == HIGH && water_state == LOW){
    Serial.println("Water leakage is detected!");
    digitalWrite(BUZZER_PIN, HIGH);
  }
}
