#include "menuMove.h"

void menuMove(SDL_Event event, SDL_Rect* positionChar, int* goalPurpose, int** tab_collide, int* speed, int* movement, int* orientation,
   Button* button_play, Button* button_goal, Button* button_quit, Button** tab_button, int* endMenu, Game* game){
     int authorizedX = 1, authorizedY = 1;

     switch(event.type)
       {
       case SDL_MOUSEBUTTONUP:
       *goalPurpose = 0;
       if (event.button.button == SDL_BUTTON_LEFT){
          if ((positionChar->x != event.button.x) && authorizedX){
            if (tab_collide[positionChar->x + 1][positionChar->y] == 0 ){
              if (abs(event.button.x - (positionChar->x + 1)) < abs(event.button.x - (positionChar->x - 1))){
                *orientation = 2;
                if (*movement < 2){
                  *movement += 1;
                }else{
                  *movement = 0;
                }
                *speed = 1;
                positionChar->x += *speed;

              }
            }
            if (tab_collide[positionChar->x - 1][positionChar->y] == 0 ){
              if (abs(event.button.x - (positionChar->x - 1)) < abs(event.button.x - (positionChar->x + 1))){
                *orientation = 1;
                if (*movement < 2){
                  *movement += 1;
                }else{
                  *movement = 0;
                }
                *speed = 1;
                positionChar->x -= *speed;
              }
            }
            if ((tab_collide[positionChar->x + 1][positionChar->y] != 0 ) || (tab_collide[positionChar->x - 1][positionChar->y] != 0)){
              *speed = 0;
            }
            if (*speed < 1){
              authorizedY = 0;
              *speed = 1;
              if ((event.button.x - positionChar->x) < 0){
                *speed = 1;
                *orientation = 0;
              }
              if ((event.button.x - positionChar->x) > 0){
                *speed = -1;
                *orientation = 3;
              }
              if (*movement < 2){
                *movement += 1;
              }else{
                *movement = 0;
              }
              positionChar->y += *speed;
           }
         }
         authorizedX = 1;


          if ((positionChar->y != event.button.y) && (authorizedY)){
            if (tab_collide[positionChar->x][positionChar->y + 1] == 0 ){
              if (abs(event.button.y - (positionChar->y + 1)) < abs(event.button.y - (positionChar->y - 1))){
                *orientation = 0;
                if (*movement < 2){
                  *movement += 1;
                }else{
                  *movement = 0;
                }
                *speed = 1;
                positionChar->y += *speed;
              }
            }
            if (tab_collide[positionChar->x][positionChar->y - 1] == 0 ){
              if (abs(event.button.y - (positionChar->y - 1)) < abs(event.button.y - (positionChar->y + 1))){
                *orientation = 3;
                if (*movement < 2){
                  *movement += 1;
                }else{
                  *movement = 0;
                }
                *speed = 1;
                positionChar->y -= *speed;
              }
            }
            if (tab_collide[positionChar->x][positionChar->y + 1] != 0 ){
              *speed = 0;
            }
            if (tab_collide[positionChar->x][positionChar->y - 1] != 0 ){
              *speed = 0;
            }
            if (*speed < 1){
              authorizedX = 0;
              *speed = 1;
              if ((event.button.y - positionChar->y) < 0){
                *speed = -1;
                *orientation = 1;
              }
              if ((event.button.y - positionChar->y) > 0){
                *speed = 1;
                *orientation = 2;
              }
              if (*movement < 2){
                *movement += 1;
              }else{
                *movement = 0;
              }
              positionChar->x += *speed;
            }
          }
         authorizedY = 1;

          if (event.button.x > getButtonXLeft(button_play) && event.button.x < getButtonXRight(button_play) &&
              event.button.y > getButtonYUp(button_play) - 32 && event.button.y < getButtonYDown(button_play)){
            if (positionChar->x >= getButtonXLeft(button_play) - 33 && positionChar->x <= getButtonXRight(button_play) + 1 &&
              positionChar->y >= getButtonYUp(button_play) - 33 && positionChar->y <= getButtonYDown(button_play) + 1){
                *endMenu = 0;
                }
            }

         if (event.button.x > getButtonXLeft(button_goal) && event.button.x < getButtonXRight(button_goal) &&
             event.button.y > getButtonYUp(button_goal) - 32 && event.button.y < getButtonYDown(button_goal)){
           if (positionChar->x >= getButtonXLeft(button_goal) - 33 && positionChar->x <= getButtonXRight(button_goal) + 1 &&
             positionChar->y >= getButtonYUp(button_goal) - 33 && positionChar->y <= getButtonYDown(button_goal) + 1){
               *goalPurpose = 1;
               authorizedX = 0;
               authorizedY = 0;
           }
         }
         if (event.button.x > getButtonXLeft(button_quit) && event.button.x < getButtonXRight(button_quit) &&
             event.button.y > getButtonYUp(button_quit) - 32 && event.button.y < getButtonYDown(button_quit)){
           if (positionChar->x >= getButtonXLeft(button_quit) - 33 && positionChar->x <= getButtonXRight(button_quit) + 1 &&
             positionChar->y >= getButtonYUp(button_quit) - 33 && positionChar->y <= getButtonYDown(button_quit) + 1){
               setVariable(getGameVariables(game), GAMEOVER, 1);
               *endMenu = 0;
           }
        }
      }
      break;
    }
}
