#include "buttons.h"

void Buttons::init()
{
  is_left=true;
  pinMode(LEFT,INPUT);
  pinMode(RIGHT,INPUT);
}

void Buttons::loop(void (*btn_left_pressed)(),void (*btn_right_pressed)())
{
  if(digitalRead(LEFT)==0)
  {
    is_left=true;
    btn_left_pressed();
  }

  if(digitalRead(RIGHT)==0)
  {
    is_left=false;
    btn_right_pressed();
  }
}
