#include <Arduino.h>
#include <TFT_eSPI.h>
#include "Application.h"

Application *application;

void setup()
{
  Serial.begin(115200);
  TFT_eSPI *display = new TFT_eSPI();
  display->begin();
  display->setRotation(1);

  application = new Application(*display);
}

void loop()
{
  // service the application
  application->loop();
}