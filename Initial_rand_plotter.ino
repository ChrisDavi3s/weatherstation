
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int VAL[122];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
   // Serial.println(("SSD1306 allocation failed"));
   // for (;;);
 // }
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(1000);
  display.clearDisplay();
  display.drawLine(0, 60 , 127, 60, WHITE);
  display.drawLine(5, 0 , 5, 127, WHITE);
  display.display();

}


void printScreen(int x[])
{
  display.clearDisplay();
  
  for (int i = 0; i < 122; i++)
  {
    Serial.println(x[i]);
    display.drawPixel(i, 64 - x[i], WHITE);
  }
  
  display.drawLine(0, 60 , 127, 60, WHITE);
  display.drawLine(5, 0 , 5, 127, WHITE);
  display.display();
}




void looparray(int inputtoplot)
{
  int sizeofarray = sizeof(VAL) / sizeof(VAL[0]);
  for (int i = 0; i < sizeofarray  ; i++)
  {
    VAL[i] = VAL[i + 1];
  }
  VAL[121] =  inputtoplot;
  printScreen(VAL);
}


void loop() {
  
  looparray(random(65));
  //delay(5);
}
