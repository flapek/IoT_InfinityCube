#include <FastLED.h>

#define NUM_LEDS_PER_STRIP 3
#define NUM_STRIPS 2
#define BRIGHTNESS 64
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
#define DELAY 100

CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, 23, COLOR_ORDER>(leds[0], NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 22, COLOR_ORDER>(leds[1], NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
    
    FastLED.setBrightness( BRIGHTNESS );
}


void loop()
{
  
}

void monoColorBlue(){
  for(int x = 0; x < NUM_STRIPS; x++) {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      leds[x][i] = CRGB::Blue;
      FastLED.show();
      leds[x][i] = CRGB::Black;
      delay(DELAY);
    }
  }
}


void monoColorGreen(){
  for(int x = 0; x < NUM_STRIPS; x++) {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      leds[x][i] = CRGB::Green;
      FastLED.show();
      leds[x][i] = CRGB::Black;
      delay(DELAY);
    }
  }
}
