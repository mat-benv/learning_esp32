#define WATER_SENSOR_PIN 12
#define BUZZER_PIN 21
int water_state;
int prev_water_state;

bool water_sensor(int analog){ //digital was not working, analog value was 1200 or less for water contact, 4095 for not
  return analog < 2000;
}

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  water_state = analogRead(WATER_SENSOR_PIN);
  Serial.println("Ready.");
}

void loop() {
  prev_water_state = water_state;
  water_state = analogRead(WATER_SENSOR_PIN);
  delay(500);
  if(!water_sensor(prev_water_state) && water_sensor(water_state)){
    Serial.println("Water leakage is detected!");
    digitalWrite(BUZZER_PIN, HIGH);
  }
  else
  if (water_sensor(prev_water_state) && !water_sensor(water_state)) {
    Serial.println("No water.");
    digitalWrite(BUZZER_PIN, LOW);
}