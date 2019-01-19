#include "constants.h"
#include "atlas.h"
#include "error.h"

/******************************************
this struct contain the SDL variable screen
******************************************/

typedef struct SDL{

  SDL_Surface* screen;

} SDL;

SDL* createSDL(Atlas* atlas, Error* error);
void destroySDL(SDL* sdl);
SDL_Surface* getScreen(SDL* sdl);
