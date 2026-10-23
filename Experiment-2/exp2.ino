
const int red1 = 6;
const int yellow1 = 5;
const int green1 = 4;

const int red2 = 3;
const int yellow2 = 2;
const int green2 = 1;

void setup() {
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);

  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);

  Serial.begin(9600);
  Serial.println("TRAFFIC LIGHT SYSTEM STARTED");
}

void loop() {
  // Direction 1: GREEN, Direction 2: RED
  digitalWrite(green1, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(red1, LOW);

  digitalWrite(red2, HIGH);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);

  Serial.println("Direction 1: GREEN | Direction 2: RED");
  delay(5000);

  // Direction 1: YELLOW, Direction 2: RED
  digitalWrite(green1, LOW);
  digitalWrite(yellow1, HIGH);

  Serial.println("Direction 1: YELLOW | Direction 2: RED");
  delay(2000);

  // Both directions RED
  digitalWrite(yellow1, LOW);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);

  Serial.println("Both Directions: RED");
  delay(1000);

  // Direction 1: RED, Direction 2: GREEN
  digitalWrite(red2, LOW);
  digitalWrite(green2, HIGH);

  Serial.println("Direction 1: RED | Direction 2: GREEN");
  delay(5000);

  // Direction 1: RED, Direction 2: YELLOW
  digitalWrite(green2, LOW);
  digitalWrite(yellow2, HIGH);

  Serial.println("Direction 1: RED | Direction 2: YELLOW");
  delay(2000);

  // Both directions RED
  digitalWrite(yellow2, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(red1, HIGH);

  Serial.println("Both Directions: RED");
  delay(1000);
}


