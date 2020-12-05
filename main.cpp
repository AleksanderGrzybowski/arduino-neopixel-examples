#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN      6
#define NUMPIXELS 15

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

// jedna dioda, inicjalizacja
void loop_1() {

  pixels.clear();
  pixels.setBrightness(10);
  
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.show();

  
  delay(5);
}

// mieszanie kolorów
void loop_2() {

  pixels.clear();
  pixels.setBrightness(10);
  
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.setPixelColor(1, pixels.Color(0, 255, 0));
  pixels.setPixelColor(2, pixels.Color(0, 0, 255));
  pixels.setPixelColor(3, pixels.Color(255, 255, 255));
  pixels.show();

  delay(5);
}

// miganie
void loop_3() {

  pixels.clear();
  pixels.setBrightness(10);

  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.setPixelColor(1, pixels.Color(255, 0, 0));
  pixels.setPixelColor(2, pixels.Color(255, 0, 0));
  pixels.show();
  delay(1000);
  
  pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.setPixelColor(1, pixels.Color(0, 255, 0));
  pixels.setPixelColor(2, pixels.Color(0, 255, 0));
  pixels.show();
  delay(1000);
  
  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  pixels.setPixelColor(1, pixels.Color(0, 0, 255));
  pixels.setPixelColor(2, pixels.Color(0, 0, 255));
  pixels.show();
  delay(1000);
  
  pixels.show();

  delay(5);
}

// latająca jedna dioda
void loop_4() {

  pixels.clear();
  pixels.setBrightness(10);

  for (int i = 0; i < 16; ++i) {
    pixels.clear();
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
    delay(100);
  }
  
  delay(5);
}

// jasność
void loop_5() {

  pixels.clear();
  pixels.setBrightness(50);

  for (int i = 0; i < 255; ++i) {
    pixels.clear();
    pixels.fill(pixels.Color(i, 0, 0), 0, 15);
    pixels.show();
    delay(10);
  }
  
  for (int i = 0; i < 255; ++i) {
    pixels.clear();
    pixels.fill(pixels.Color(0, i, 0), 0, 15);
    pixels.show();
    delay(10);
  }
  
  for (int i = 0; i < 255; ++i) {
    pixels.clear();
    pixels.fill(pixels.Color(0, 0, i), 0, 15);
    pixels.show();
    delay(10);
  }
  
  delay(5);
}

// hsv
void loop() {

  pixels.clear();
  pixels.setBrightness(10);

  for (uint16_t i = 0; i <= 255; i++) {
    pixels.clear();
    for (int j = 0; j < 16; ++j) {
      pixels.setPixelColor(j, pixels.ColorHSV(i*256 + 2000*j, 255, 255));
    }
    pixels.show();
    delay(20);
}
  
  delay(5);
}
