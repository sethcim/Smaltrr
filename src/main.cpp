
#include <Arduino.h>
#include <bitmaps.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>
#include "disco.h"

//Constants
const uint8_t oledWidth = 128;
const uint8_t oledHeight = 32;
//const uint16_t PixelCount = 19; // make sure to set this to the number of pixels in your strip

//Global manager objects
Adafruit_SSD1306 display = Adafruit_SSD1306(oledWidth, oledHeight, &Wire);

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

  //Display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);
  /*display.clearDisplay();
  display.display();*/

  //disco lights setup
  strip.Begin();
  strip.Show();
  SetupAnimations();
}

void loop()
{ /*
  // text display tests
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Connecting to SSID\n'adafruit':");
  display.print("connected!");
  display.println("IP: 10.0.1.23");
  display.print("Sending: ");
  display.print(analogRead(A0));
  display.setCursor(0, 0);
  display.display(); // actually display all of the above
  delay(200);*/

  //disco lights updates
  animations.UpdateAnimations();
  strip.Show();
}