#pragma once
#include "constants.h"

/********************************************************
this file contain TileSet struct (with all tilesets used)
and the functions to create, get and eestroy the tilesets
********************************************************/

typedef struct Atlas Atlas;

typedef struct TileSet {

  SDL_Surface* tileset1;
  SDL_Surface* tileset2;
  SDL_Surface* tileset3;

} TileSet;

TileSet* createTileset();
SDL_Surface* getTileset(Atlas* atlas, int index);
void destroyTileset(TileSet* tileset);
