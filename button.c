#include "button.h"

Button* createButton(){
  Button* button = malloc(sizeof(Button));

  button->xLeft = 0;
  button->xRight = 0;
  button->yUp = 0;
  button->yDown = 0;

  return button;
}

void destroyButton(Button* button){
  free(button);
  button = NULL;
}

void setButtonPosition(Button* button, int xL, int xR, int yU, int yD){
  button->xLeft = xL;
  button->xRight = xR;
  button->yUp = yU;
  button->yDown = yD;
}

int getButtonXLeft(Button* button){
  return button->xLeft;
}

int getButtonXRight(Button* button){
  return button->xRight;
}

int getButtonYUp(Button* button){
  return button->yUp;
}
int getButtonYDown(Button* button){
  return button->yDown;
}
