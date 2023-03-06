#include <Adafruit_NeoPixel.h>

const int neoPixelPin = 5;
const int pixelCount = 7;
const int microphonePin = A0;
int fade = 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(pixelCount, neoPixelPin, NEO_GRBW + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(random(50)+200);
  strip.show();
}

void loop() {

  int r = random(200, 255);
  int g = random(70, 80);
  int b = random(0, 10);

  int mn = 1024;
  int mx = 0;
  for (int j = 0; j < 50; j++) {
    int val = analogRead(microphonePin);
    mn = min(mn, val);
    mx = max(mx, val);
  }
  int delta = mx - mn;
  Serial.println(delta);

  if (delta > 100) {
    for (int i = 0; i < pixelCount; i++) {
      strip.setPixelColor(i,0);
      strip.show();
      // delay(random(30,50));
    }
    // delay(1000);
  } 
  else {
    for (int i = 0; i < pixelCount; i++) {
      strip.setPixelColor(i, r,g,b);
      strip.show();
      // delay(random(30,50));
    }
    strip.clear();
  }
}