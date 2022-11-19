#include <Arduino.h>
#include <TFT_eSPI.h>
#include "resources/left1.h"
#include "resources/left2.h"
#include "resources/right1.h"
#include "resources/right2.h"
#include "globals.h"
#include "buttons.h"

TFT_eSPI tft=TFT_eSPI();
Buttons btn;

void setup()
{
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_GREEN);
  tft.setSwapBytes(true);
  btn.init();
}

void loop() 
{
  if (btn.is_left)
  {
    if (is_first_sprite)
    {
      is_first_sprite=false;
      tft.pushImage(0,0,135,241,left1);
      delay(TIME_DELAY);
    }
    else
    {
      is_first_sprite=true;
      tft.pushImage(0,0,135,241,left2);
      delay(TIME_DELAY);
    }
  }
  else
  {
    if (is_first_sprite)
    {
      is_first_sprite=false;
      tft.pushImage(0,0,135,241,right1);
      delay(TIME_DELAY);
    }
    else
    {
      is_first_sprite=true;
      tft.pushImage(0,0,135,241,right2);
      delay(TIME_DELAY);
    }
  }

  btn.loop(&btn_left_pressed, &btn_right_pressed);
}

void btn_left_pressed()
{
  is_first_sprite=true;
}

void btn_right_pressed()
{
  is_first_sprite=true;
}
