
const int tempPin = A0;
const int motorPin = 9;

float temperature;
int sensorValue;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);

  digitalWrite(motorPin, LOW);
}

void loop() {
  sensorValue = analogRead(tempPin);

  // Convert LM35 analog reading to Celsius
  temperature = sensorValue * (5.0 / 1023.0) * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  // Motor ON when temperature reaches 30 C
  if (temperature >= 30.0) {
    digitalWrite(motorPin, HIGH);
    Serial.println("Motor: ON");
  } 
  else {
    digitalWrite(motorPin, LOW);
    Serial.println("Motor: OFF");
  }

  delay(1000);
}


