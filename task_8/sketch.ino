#include <FastLED.h>

#define LED_PIN      6
#define MATRIX_WIDTH  8
#define MATRIX_HEIGHT 8
#define NUM_LEDS     64
#define LED_TYPE     WS2812
#define COLOR_ORDER  GRB

CRGB leds[NUM_LEDS];

uint16_t XY(uint8_t x, uint8_t y) {
  if (y % 2 == 0) return (y * MATRIX_WIDTH) + x;
  else            return (y * MATRIX_WIDTH) + (MATRIX_WIDTH - 1 - x);
}

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(200);
  FastLED.clear();
  FastLED.show();
}

void modeWalk() {
  for (int i = 0; i < NUM_LEDS; i++) {
    FastLED.clear();
    leds[i] = CRGB::White;
    FastLED.show();
    delay(120);
  }
}

void modeFill() {
  CRGB colors[] = {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, CRGB::Magenta, CRGB::Cyan, CRGB::White, CRGB::Orange};
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      leds[XY(x, y)] = colors[y % 8];
    }
    FastLED.show();
    delay(400);
  }
  delay(600);
  FastLED.clear();
  FastLED.show();
  delay(300);
}

void modeChess() {
  for (int phase = 0; phase < 2; phase++) {
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
        if ((x + y + phase) % 2 == 0) {
          leds[XY(x, y)] = CRGB::White;
        } else {
          leds[XY(x, y)] = CRGB::Black;
        }
      }
    }
    FastLED.show();
    delay(800);
  }
}

void loop() {
  modeWalk();
  delay(500);
  modeFill();
  delay(500);
  modeChess();
  delay(500);
}
