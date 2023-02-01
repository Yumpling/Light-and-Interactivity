

const int ledPin = 5;
int analogValue = 0;
int brightness = 0;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  analogValue = analogRead(A0);
  brightness = analogValue /3;
  if (analogValue > 400 && analogValue < 450) {
    digitalWrite(ledPin, brightness);
  }
  else {
    analogWrite(ledPin, brightness/10);
  }
  Serial.println(analogValue);
}
