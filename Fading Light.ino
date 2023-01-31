const int ledPin = 9;
int analogValue = 0;
int brightness = 0;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  analogValue = analogRead(A0);
  brightness = (analogValue /4) *10;
  if (analogValue > 400 && analogValue < 450) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    analogWrite(ledPin, brightness);
  }
  Serial.println(analogValue);
}
