
const int gasPin = A0;       // MQ-2 gas sensor OUT
const int trigPin = 9;       // Ultrasonic TRIG
const int echoPin = 8;       // Ultrasonic ECHO
const int pirPin = 2;        // PIR sensor OUT
const int buzzerPin = 10;    // Buzzer
const int ledPin = 11;       // LED

int gasValue;
int pirValue;
long duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("SMART SENSOR MONITORING SYSTEM");
  Serial.println("------------------------------");
}

void loop() {
  // Read gas sensor
  gasValue = analogRead(gasPin);

  // Read PIR motion sensor
  pirValue = digitalRead(pirPin);

  // Measure ultrasonic distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    distance = -1;
  } else {
    distance = duration * 0.0343 / 2;
  }

  // Display readings in Virtual Terminal
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  Serial.print("Distance: ");
  if (distance < 0) {
    Serial.println("No Echo");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  Serial.print("Motion: ");
  Serial.println(pirValue == HIGH ? "DETECTED" : "NOT DETECTED");

  // Alert conditions
  bool gasAlert = gasValue > 400;
  bool objectAlert = distance > 0 && distance < 20;
  bool motionAlert = pirValue == HIGH;

  if (gasAlert || objectAlert || motionAlert) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

    Serial.println("!!! ALERT DETECTED !!!");

    if (gasAlert) Serial.println("Gas level is high!");
    if (objectAlert) Serial.println("Object is nearby!");
    if (motionAlert) Serial.println("Motion detected!");
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.println("System Normal");
  }

  Serial.println("------------------------------");
  delay(1000);
}
