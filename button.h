#pragma once
#include "constants.h"

/*******************************************************
this struct contain the data about buttons used on menu
we also have the set, get and destroy
*******************************************************/

typedef struct Button{
  int xLeft;
  int xRight;
  int yUp;
  int yDown;
} Button;

Button* createButton();
void destroyButton(Button* button);
void setButtonPosition(Button* button, int xL, int xR, int yU, int yD);
int getButtonXLeft(Button* button);
int getButtonXRight(Button* button);
int getButtonYUp(Button* button);
int getButtonYDown(Button* button);
