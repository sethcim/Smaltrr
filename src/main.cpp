
//Library includes
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>

//Additional font files
#include <Fonts/FreeSans18pt7b.h>
#include <Fonts/FreeSans24pt7b.h>

//Project Source Includes
#include <bitmaps.h>
#include "disco.h"

//Constants

//const uint16_t PixelCount = 19; // make sure to set this to the number of pixels in your strip

//Global manager objects
Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);

//NeoPixelBus<DotStarBgrFeature, DotStarSpiMethod> strip(PixelCount);
//NeoPixelAnimator animations(2); // only ever need 2 animations

//Global variables

void setup()
{
  //Hardware pin setup
  pinMode(A0, INPUT);        //State of charge analog input
  pinMode(0, INPUT);         //Red LED & Switch A
                             //pin 1 TX to computer
  pinMode(2, INPUT);         //Blue LED & Switch C
                             //pin 2 RX from computer
                             //pin 4 SDA to screen
                             //pin 5 SCL to screen
  pinMode(12, INPUT_PULLUP); //Main switch
                             //pin 13 MOSI LED data
                             //pin 14 SCK LED clock
  pinMode(15, OUTPUT);       //motor
  pinMode(16, INPUT);        //WAKE & Switch B TODO

  //Serial messages over USB
  Serial.begin(112500);

  //disco lights setup
  strip.Begin();
  setupAnimations();
  strip.Show();

  //oled
  delay(150);
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.setRotation(2);
  oled.drawBitmap(0, 0, fsLogo, 128, 32, SSD1306_WHITE);
  oled.display();
  delay(1000);
  oled.clearDisplay();
  oled.display();
}

void loop()
{
  //code to run every 15 ms
  static uint32_t millis10ms = millis();
  if ((millis() - millis10ms) >= 15)
  {
    static int16_t spriteOffset = -18;
    millis10ms = millis();
    oled.clearDisplay();
    oled.drawBitmap(spriteOffset, 10 * sin((float)spriteOffset / 30.1), shakebot, 18, 32, SSD1306_WHITE);
    oled.display();
    spriteOffset++;
    if (spriteOffset >= 128)
    {
      spriteOffset = -18;
    }
  }

  //code to run every 60 ms
  static uint32_t millis60ms = millis();
  if ((millis() - millis60ms) >= 253)
  {
    millis60ms = millis();
    updateAnimations();
    strip.Show();
  }
  /*
  // text display tests
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 0);
  oled.print("Connecting to SSID\n'adafruit':");
  oled.print("connected!");
  oled.println("IP: 10.0.1.23");
  oled.print("Sending: ");
  oled.print(analogRead(A0));
  oled.setCursor(0, 0);
  oled.display(); // actually display all of the above
  delay(200);*/
}