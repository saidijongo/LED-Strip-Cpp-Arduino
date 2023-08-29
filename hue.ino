const int RED_PIN = 5;
const int GREEN_PIN = 6;
const int BLUE_PIN = 7;

const int NUM_LEDS = 143;
const int DELAY_MS = 10; // Delay between color changes

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

void rainbowEffect() {
  int hue = 0; // Starting hue value
  
  while (true) {
    for (int i = 0; i < NUM_LEDS; i++) {
      // Convert hue to RGB color
      int rgbColor[3];
      hsvToRgb(hue, 255, 255, rgbColor);
      
      setColor(rgbColor[0], rgbColor[1], rgbColor[2]);
      delay(DELAY_MS);
      
      hue += 1; // Increment hue for the next LED
      hue %= 256; // Wrap around to keep it within valid range
    }
  }
}

void hsvToRgb(int h, int s, int v, int rgb[]) {
  float f = (h % 60) / 60.0;
  float p = (v * (1 - s)) * 255.0;
  float q = (v * (1 - f * s)) * 255.0;
  float t = (v * (1 - (1 - f) * s)) * 255.0;

  switch (h / 60) {
    case 0: rgb[0] = v; rgb[1] = t; rgb[2] = p; break;
    case 1: rgb[0] = q; rgb[1] = v; rgb[2] = p; break;
    case 2: rgb[0] = p; rgb[1] = v; rgb[2] = t; break;
    case 3: rgb[0] = p; rgb[1] = q; rgb[2] = v; break;
    case 4: rgb[0] = t; rgb[1] = p; rgb[2] = v; break;
    case 5: rgb[0] = v; rgb[1] = p; rgb[2] = q; break;
  }
}

void loop() {
  rainbowEffect();
}
