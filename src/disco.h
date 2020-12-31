// NeoPixelCylon
// This example will move a Cylon Red Eye back and forth across the
// the full collection of pixels on the strip.
//
// This will demonstrate the use of the NeoEase animation ease methods; that provide
// simulated acceleration to the animations.
//
//
#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>

const uint16_t PixelCount = 19; // make sure to set this to the number of pixels in your strip
const uint8_t DotClockPin = 14;
const uint8_t DotDataPin = 13;
const RgbColor CylonEyeColor(HtmlColor(0x222222));

NeoPixelBus<DotStarBgrFeature, DotStarSpiMethod> strip(PixelCount);

void setupAnimations()
{
    strip.ClearTo(HtmlColor(0x0));
    strip.SetPixelColor(0, HtmlColor(0x220000));
    strip.SetPixelColor(1, HtmlColor(0x222200));
    strip.SetPixelColor(2, HtmlColor(0x002200));
    strip.SetPixelColor(3, HtmlColor(0x002222));
    strip.SetPixelColor(4, HtmlColor(0x000022));
    strip.SetPixelColor(5, HtmlColor(0x220022));
}

void updateAnimations()
{
    strip.RotateRight(1);
    Serial.println("Rotating");
}