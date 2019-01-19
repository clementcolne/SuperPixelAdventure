#pragma once
#include "constants.h"
#include "picture.h"
#include "atlas.h"
#include "tables.h"

/****************************************************************
keyboardEvent function threat all keyboard press from they player
****************************************************************/

typedef struct Variables Variables;
typedef struct Game Game;

void keyboardEvent(SDL_Event event, Game* game);
void pressE(Game* game, int xchar, int ychar);
void pressZ(Game* game, int xchar, int ychar);
void pressS(Game* game, int xchar, int ychar);
void pressQ(Game* game, int xchar, int ychar);
void pressD(Game* game, int xchar, int ychar);
void talkToCountryGuard(Game* game);
void talkToPannelSpawn(Game* game);
void talkToGirl(Game* game);
void talkToBoy(Game* game);
void talkToInnerkeeper(Game* game);
void talkToVillager(Game* game);
void talkToFishMan(Game* game);
void talkToWoodMan(Game* game);
void talkToGuardians(Game* game);
void resetVariables(Game* game, int dirIndex);
