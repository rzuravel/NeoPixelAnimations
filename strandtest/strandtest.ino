#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
  #include <avr/pgmspace.h>
#endif

#define NUM_PIXELS 93
#define PIN 6
#define COLORS 256
#define BRIGHTNESS 50
#define RGB 3
#define R 0
#define G 1
#define B 2
#define OFF strip.Color(0,0,0)
#define RED strip.Color(255,0,0)
#define GREEN strip.Color(0,255,0)
#define BLUE strip.Color(0,0,255)
#define YELLOW strip.Color(0,255,255)
#define WHITE strip.Color(255,255,255)

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint16_t RINGS [6] = {32, 24, 16, 12, 8, 1};

#define FRAMES 3
const uint8_t testframe [FRAMES][NUM_PIXELS][RGB] PROGMEM = {
                                                {
                                                  {255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},
                                                  {255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},
                                                  {255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},
                                                  {255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},
                                                  {255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},
                                                  {255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},
                                                  {255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},
                                                  {255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},
                                                  {255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},
                                                  {255,255,255},{255,255,255},{255,255,255}
                                                },
                                                {
                                                  {0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},
                                                  {0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},
                                                  {0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},
                                                  {0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},
                                                  {0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},
                                                  {0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},
                                                  {0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},
                                                  {0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},
                                                  {0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},{0,0,255},
                                                  {0,0,255},{0,0,255},{0,0,255}
                                                },
                                                {
                                                  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},
                                                  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},
                                                  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},
                                                  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},
                                                  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},
                                                  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},
                                                  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},
                                                  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},
                                                  {255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0},
                                                  {255,0,0},{255,0,0},{255,0,0}
                                                }
                                              };

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  
  strip.begin();
  
  strip.setBrightness(BRIGHTNESS);
  
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  //colorWipe(strip.Color(255, 0, 0), 50); // Red
  //colorWipe(strip.Color(0, 255, 0), 50); // Green
  //colorWipe(strip.Color(0, 0, 255), 50); // Blue
//colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW
  // Send a theater pixel chase in...
  //theaterChase(strip.Color(127, 127, 127), 50); // White
  //theaterChase(strip.Color(127, 0, 0), 50); // Red
  //theaterChase(strip.Color(0, 0, 127), 50); // Blue

  //drawBitMap(testframe, FRAMES, 1024);
  //rainbow(1);
  //rainbowCycle(1);
  //theaterChaseRainbow(50);
  //colorSpin(strip.Color(255, 0, 0), 20);
  //randomFillUp(100);
  //colorBreathe(strip.Color(255, 0, 0), 20);
  //colorSpin(Wheel(random() % COLORS), 2);
  //colorBounce(Wheel(random() % COLORS), 2);

  //rainbow(5);
  //bullsEye(1, 64);
  //bullsEyeOneRingAtaTime(200,64, true);
  //fadeOut(5, 25);
  //fadeIn(5, 25);
}

void drawBitMap(const uint8_t bitmaps [][NUM_PIXELS][RGB], uint8_t frames, uint16_t wait)
{
  for (int curFrame = 0; curFrame < frames; curFrame++)
  {
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
      strip.setPixelColor(pixel, pgm_read_dword(&(bitmaps[curFrame][pixel][R])), pgm_read_dword(&(bitmaps[curFrame][pixel][G])), pgm_read_dword(&(bitmaps[curFrame][pixel][B])));
    }
    strip.show();
    delay(wait);
  }
}

void fadeInAndOut(uint8_t wait, uint32_t c) {
    uint16_t i;

}

void fadeIn(uint8_t wait, uint32_t c) {
  uint16_t i, p;

  for (i = 0; i < BRIGHTNESS; i++)
  {
    for (p = 0; p < strip.numPixels(); p++) {
      strip.setPixelColor(p, i, i, i);
    }
    strip.show();
    delay(wait);
  }
}

void fadeOut(uint8_t wait, uint32_t c) {
  uint16_t i, p;

  for (i = BRIGHTNESS; i > 0; i--)
  {
    for (p = 0; p < strip.numPixels(); p++) {
      strip.setPixelColor(p, i, i, i);
    }
    strip.show();
    delay(wait);
  }
}

//void spokes(uint8_t wait, uint32_t c) {
//  uint16_t i;
//  
//  for (i=0; i<OUTER_LENGTH; i++) {
//    if (i > 0) {
//      strip.setPixelColor(outer[i-1], OFF);
//      strip.setPixelColor(inner[(uint16_t)(i / ((float)OUTER_LENGTH/INNER_LENGTH)) - 1], OFF);
//      strip.setPixelColor(jewel[(uint16_t)(i / ((float)OUTER_LENGTH/JEWEL_LENGTH)) - 1], OFF);
//    }
//    else if(i == 0) {
//      strip.setPixelColor(outer[OUTER_LENGTH-1], OFF);
//      strip.setPixelColor(inner[INNER_LENGTH-1 % INNER_LENGTH], OFF);
//      strip.setPixelColor(jewel[JEWEL_LENGTH-1 % JEWEL_LENGTH], OFF);
//    }
//    
//    strip.setPixelColor(outer[i], Wheel(c % 255));
//    strip.setPixelColor(inner[(uint16_t)(i / ((float)OUTER_LENGTH/INNER_LENGTH))], Wheel(c % 255));
//    strip.setPixelColor(jewel[(uint16_t)(i / ((float)OUTER_LENGTH/JEWEL_LENGTH))], Wheel(c % 255));
//    strip.setPixelColor(center[0], Wheel(c % 255));
//    strip.show();
//    delay(wait);
//  }
//}

void bullsEyeOneRingAtaTime(uint16_t wait, uint8_t gapValue, bool towardsIn) {
  uint16_t i, j, k, idxSoFar;

  for(k=0; k<COLORS*5; k++) { // 5 cycles of all colors on wheel
    if (towardsIn) {
      idxSoFar = 0;
      for (j=0; j < sizeof(RINGS)/sizeof(uint16_t); j++){
        allOff();
        for (i=0; i<RINGS[j]; i++) {
          strip.setPixelColor(i + idxSoFar, Wheel(k % 255)); 
        }
  
        idxSoFar += RINGS[j];
        strip.show();
        delay(wait/(j+1));
      }
    }
    else {
      idxSoFar = NUM_PIXELS - 1;
      for (j=-1 + sizeof(RINGS)/sizeof(uint16_t); j >= 0; j--) {
        allOff();
        for (i=0; i<RINGS[j]; i++) {
          strip.setPixelColor(idxSoFar - i, Wheel(k % 255)); 
        }
  
        idxSoFar -= RINGS[j];
        strip.show();
        delay(wait);
      }
    }
  }
}

//void bullsEyeSlowFade(uint8_t wait, uint8_t gapValue) {
//  uint16_t i, j;
//
//  for(j=0; j<COLORS*5; j++) { // 5 cycles of all colors on wheel
//
//    for (i=0; i<sizeof(outer)/sizeof(uint16_t); i++) {
//      strip.setPixelColor(outer[i], Wheel(j % 255)); 
//    }
//
//    strip.show();
//    delay(wait);
//
//    for (i=0; i<sizeof(inner)/sizeof(uint16_t); i++) {
//      strip.setPixelColor(inner[i], Wheel(j+gapValue*1 % 255)); 
//    }
//
//    strip.show();
//    delay(wait);
//
//    for (i=0; i<sizeof(jewel)/sizeof(uint16_t); i++) {
//      strip.setPixelColor(jewel[i], Wheel(j+gapValue*2 % 255)); 
//    }
//
//    strip.show();
//    delay(wait);
//    
//    for (i=0; i<sizeof(center)/sizeof(uint16_t); i++) {
//      strip.setPixelColor(center[i], Wheel(j+gapValue*3 % 255)); 
//    }
//    
//    strip.show();
//    delay(wait);
//  }
//}
//
//void bullsEye(uint8_t wait, uint8_t gapValue) {
//  uint16_t i, j;
//
//  for(j=0; j<COLORS*5; j++) { // 5 cycles of all colors on wheel
//
//    for (i=0; i<sizeof(outer)/sizeof(uint16_t); i++) {
//      strip.setPixelColor(outer[i], Wheel(j % 255)); 
//    }
//
//    for (i=0; i<sizeof(inner)/sizeof(uint16_t); i++) {
//      strip.setPixelColor(inner[i], Wheel(j+gapValue*1 % 255)); 
//    }
//
//    for (i=0; i<sizeof(jewel)/sizeof(uint16_t); i++) {
//      strip.setPixelColor(jewel[i], Wheel(j+gapValue*2 % 255)); 
//    }
//    
//    for (i=0; i<sizeof(center)/sizeof(uint16_t); i++) {
//      strip.setPixelColor(center[i], Wheel(j+gapValue*3 % 255)); 
//    }
//    
//    strip.show();
//    delay(wait);
//  }
//}
//
//void bullsEyeReverse(uint8_t wait, uint8_t gapValue) {
//  uint16_t i, j;
//  uint16_t oneC, twoC, threeC, fourC;
//
//  for(j=0; j<COLORS*5; j++) { // 5 cycles of all colors on wheel
//
//    for (i=0; i<sizeof(center)/sizeof(uint16_t); i++) {
//      strip.setPixelColor(center[i], Wheel(j % 255)); 
//    }
//
//    for (i=0; i<sizeof(jewel)/sizeof(uint16_t); i++) {
//      strip.setPixelColor(jewel[i], Wheel(j+gapValue*1 % 255)); 
//    }
//    
//    for (i=0; i<sizeof(inner)/sizeof(uint16_t); i++) {
//      strip.setPixelColor(inner[i], Wheel(j+gapValue*2 % 255)); 
//    }
//
//    for (i=0; i<sizeof(outer)/sizeof(uint16_t); i++) {
//      strip.setPixelColor(outer[i], Wheel(j+gapValue*3 % 255)); 
//    }
//    
//    strip.show();
//    delay(wait);
//  }
//}

void randomFillUp(uint8_t wait) {
  allOff();
  bool Lit [strip.numPixels()];
  int num = 0;
  for (int i = 0; i < strip.numPixels(); i++) {
    Lit[i] = false;
  }

  uint16_t pixel = rand() % strip.numPixels();

  while (num != strip.numPixels()) {
    while(Lit[pixel]) {
      pixel = rand() % strip.numPixels();
    }
    
    strip.setPixelColor(pixel, Wheel(rand() % COLORS));
    Lit[pixel] = true;
    num++;
    
    strip.show();
    delay(wait);
  }

  allOff();
}

// randomly light a random pixel
void randomLight(uint8_t wait) {
  uint16_t pixel = rand() % strip.numPixels();
  strip.setPixelColor(pixel, Wheel(rand() % COLORS));
  strip.show();
  delay(wait);
  strip.setPixelColor(pixel, OFF);
}

// Light one at a time around the ring
void colorSpin(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    if (i == 0) {
      strip.setPixelColor(strip.numPixels()-1, strip.Color(0, 0, 0));
    }
    else {
      strip.setPixelColor(i-1, strip.Color(0, 0, 0));
    }
    strip.show();
    delay(wait);
  }
}

void colorBounce(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels()*2; i++) {
    if (i < strip.numPixels())
    {
      strip.setPixelColor(i, c);
      if (i == 0) {
        strip.setPixelColor(strip.numPixels()-1, strip.Color(0, 0, 0));
      }
      else {
        strip.setPixelColor(i-1, strip.Color(0, 0, 0));
      }
    }
    else {
      uint16_t j = strip.numPixels()*2 - i - 1;

      strip.setPixelColor(j, c);
      strip.setPixelColor(j+1, strip.Color(0, 0, 0));
    }
    strip.show();
    delay(wait);
  }
}

void colorBreathe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels()*2; i++) {
    if (i < strip.numPixels())
    {
      strip.setPixelColor(i, c);
    }
    else {
      uint16_t j = strip.numPixels()*2 - i - 1;

      strip.setPixelColor(j, c);
      strip.setPixelColor(j+1, strip.Color(0, 0, 0));
    }
    strip.show();
    delay(wait);
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void allOff() {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, OFF);
  }
  strip.show();
}

