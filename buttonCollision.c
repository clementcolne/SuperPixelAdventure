#include "button.h"
#include "buttonCollision.h"


int** buttonCollision(int** tab_collision, Button* button1, Button* button2, Button* button3){
  int i, j;

  for (i = 0; i < SCREEN_WIDTH-1; i++){
    for (j = 0; j < SCREEN_HEIGHT-1; j++){
       tab_collision[i][j] = 0;					// no collision
    }
  }

  for (i = getButtonXLeft(button1) - 32; i <= getButtonXRight(button1); i++){
    for (j = getButtonYUp(button1) - 32; j <= getButtonYDown(button1); j++){
       tab_collision[i][j] = 2;					// collision
    }
  }

  for (i = getButtonXLeft(button2) - 32; i <= getButtonXRight(button2); i++){
    for (j = getButtonYUp(button2) - 32; j <= getButtonYDown(button2); j++){
       tab_collision[i][j] = 2;					// collision
    }
  }

  for (i = getButtonXLeft(button3) - 32; i <= getButtonXRight(button3); i++){
    for (j = getButtonYUp(button3) - 32; j <= getButtonYDown(button3); j++){
       tab_collision[i][j] = 2;					// collision
    }
  }

  return tab_collision;
}
