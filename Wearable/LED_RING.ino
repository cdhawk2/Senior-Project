#include <Adafruit_NeoPixel.h>

#define PIN 1 // Marked D1 on GEMMA
#define NUM_LEDS 64

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type:
//   NEO_GRB  Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB  Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB);

uint32_t color = strip.Color(255, 0, 0); // Change RGB color value here

// These are the pixels in order of animation-- 16 pixels in total:
int play[] = {
   0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

void setup() {
  strip.begin();
  strip.show();            // Initialize all pixels to 'off'
  strip.setBrightness(40); // 40/255 brightness (about 15%)
}

void loop() {
  for(int i=0; i<16; i++) {
    strip.setPixelColor(play[i], color);             // Draw 'head' pixel
    strip.setPixelColor(play[i - 2], 0); // Erase 'tail'
    strip.show();
    delay(40);
  }
}

