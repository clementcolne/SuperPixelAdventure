#include "tileset.h"
#include "atlas.h"

TileSet* createTileset() {

  TileSet* tileset = malloc(sizeof(TileSet));

  tileset->tileset1 = SDL_LoadBMP("./pictures/tileset/tileset1.bmp");
  tileset->tileset2 = SDL_LoadBMP("./pictures/tileset/tileset2.bmp");
  tileset->tileset3 = SDL_LoadBMP("./pictures/tileset/tileset3.bmp");

  return tileset;

}

SDL_Surface* getTileset(Atlas* atlas, int index) {

  SDL_Surface* tileset;

  if(index==1) tileset = atlas->tileset->tileset1;
  if(index==2) tileset = atlas->tileset->tileset2;
  if(index==3) tileset = atlas->tileset->tileset3;

  return tileset;
}

void destroyTileset(TileSet* tileset) {

  SDL_FreeSurface(tileset->tileset1);
  SDL_FreeSurface(tileset->tileset2);
  SDL_FreeSurface(tileset->tileset3);

  free(tileset);
  tileset = NULL;

}
