#pragma once
#include "game.h"
#include "variables.h"
#include "constants.h"
#include "button.h"

void menuMove(SDL_Event event, SDL_Rect* positionChar, int* goalPurpose, int** tab_collide, int* speed, int* movement, int* orientation,
   Button* button_play, Button* button_goal, Button* button_quit, Button** tab_button, int* endMenu, Game* game);
