#ifndef __CLASS_BUTTONS__
#define __CLASS_BUTTONS__

#include <TFT_eSPI.h>

#define LEFT 0
#define RIGHT 35

class Buttons
{
  public:
    bool is_left;
    void init();
    void loop(void (*btn_left_pressed)(),void (*btn_right_pressed)());
};

#endif