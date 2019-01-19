#include "createSDL.h"

SDL* createSDL(Atlas* atlas, Error* error) {

  char* title = "SuperPixelAdventure";
  SDL* sdl = malloc(sizeof(SDL));
  sdl->screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

  SDL_SetColorKey(getPicture(atlas, HERO)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, HERO)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, PANNEL)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, PANNEL)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, CHAT_BOX)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHAT_BOX)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, FOG)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, FOG)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, CHEST)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHEST)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, FISH)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, FISH)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, PASS_FISH)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, PASS_FISH)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, AXE)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, AXE)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, PASS_WOOD)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, PASS_WOOD)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, CHAT_BOX_INNERKEEPER)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHAT_BOX_INNERKEEPER)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, CHAT_BOX_WOODMAN)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHAT_BOX_WOODMAN)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, CHAT_BOX_COUNTRYGUARD)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHAT_BOX_COUNTRYGUARD)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, CHAT_BOX_KIDF)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHAT_BOX_KIDF)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, CHAT_BOX_KIDM)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHAT_BOX_KIDM)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, CHAT_BOX_FISHMAN)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHAT_BOX_FISHMAN)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, CHAT_BOX_VILLAGER)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHAT_BOX_VILLAGER)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, CHAT_BOX_GUARDIANS)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHAT_BOX_GUARDIANS)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, CHAT_BOX_GUARDIANF)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHAT_BOX_GUARDIANF)->surface->format, 255, 255, 255));
  SDL_SetColorKey(getPicture(atlas, CHAT_BOX_GUARDIANM)->surface, SDL_SRCCOLORKEY, SDL_MapRGB(getPicture(atlas, CHAT_BOX_GUARDIANM)->surface->format, 255, 255, 255));

  SDL_WM_SetCaption(title, NULL);

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    setErrorIsError(error, TRUE);
    setErrorMessage(error, LOAD_SDL, "-> SDL_Init(video) (createSdl.c)\n");
  }
  if (SDL_Init(SDL_INIT_AUDIO) != 0) {
    setErrorIsError(error, TRUE);
    setErrorMessage(error, LOAD_SDL, "-> SDL_Init(audio) (createSdl.c)\n");
  }
  if (Mix_Init(MIX_INIT_MP3) != 0) {
    //setErrorIsError(error, TRUE);
    setErrorMessage(error, LOAD_SDL, "-> SDL_Init(audio) (createSdl.c)\n");
  }
  if (TTF_Init() == -1) {
    setErrorIsError(error, TRUE);
    setErrorMessage(error, LOAD_SDL, "-> TTF_Init (createSdl.c)\n");
  }
  SDL_EnableKeyRepeat(10, 10);

  return sdl;
  free(title);

}

void destroySDL(SDL* sdl) {
  SDL_FreeSurface(sdl->screen);
  SDL_Quit();
  free(sdl);
}

SDL_Surface* getScreen(SDL* sdl) {
  return sdl->screen;
}
