#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"
#include "tables.h"

/****************************************************************************
each function used is a specifical print function, one to print the map,
one to print the character and PNJs, one to print the pannels & chats chatBox
***************************************************************************/

typedef struct Variables Variables;
typedef struct SDL SDL;
typedef struct Game Game;

void display(Game* game);
void displayMap(Game* game);
void displayPannel(Game* game);
void displayTextPannel(Game* game);
void displayHero(Game* game);
void displayWaterfall(Game* game);
void displayChest(Game* game);
void displayFish(Game* game);
void displayPass(Game* game);
void displayAxe(Game* game);
void displayFog(Game* game);
void displayBars(Game* game);
void updateScreen(Game* game);
