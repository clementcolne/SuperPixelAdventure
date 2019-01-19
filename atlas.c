#include "atlas.h"
#include "createSDL.h"
#include "game.h"

Atlas* createAtlas() {

  Atlas* atlas = malloc(sizeof(Atlas));
  atlas->pictures = malloc(sizeof(Picture*) * SIZE_ATLAS);

  atlas->pictures[HERO] = createPicture("./pictures/characters/hero.bmp", 30, CHAR_HEIGHT);
  atlas->pictures[WATERFALL] = createPicture("./pictures/waterfall/cascades_grandes.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[CHAT_BOX] = createPicture("./pictures/chat/chatBox.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[PANNEL] = createPicture("./pictures/chat/pannel.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[FOG] = createPicture("./pictures/tileset/fog.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[CHEST] = createPicture("./pictures/chest/chest.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[FISH] = createPicture("./pictures/chest/fish.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[PASS_FISH] = createPicture("./pictures/paperPlease/pass.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[AXE] = createPicture("./pictures/axe/axe.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[PASS_WOOD] = createPicture("./pictures/paperPlease/pass.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[CHAT_BOX_INNERKEEPER] = createPicture("./pictures/chat/chatAubergiste.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[CHAT_BOX_WOODMAN] = createPicture("./pictures/chat/chatBucheron.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[CHAT_BOX_COUNTRYGUARD] = createPicture("./pictures/chat/chatCountryGuard.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[CHAT_BOX_KIDF] = createPicture("./pictures/chat/chatKidF.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[CHAT_BOX_KIDM] = createPicture("./pictures/chat/chatKidM.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[CHAT_BOX_FISHMAN] = createPicture("./pictures/chat/chatPecheur.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[CHAT_BOX_VILLAGER] = createPicture("./pictures/chat/chatVillageoise.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[CHAT_BOX_GUARDIANS] = createPicture("./pictures/chat/chatGuardians.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[CHAT_BOX_GUARDIANF] = createPicture("./pictures/chat/chatMami.bmp", CHAR_WIDTH, CHAR_HEIGHT);
  atlas->pictures[CHAT_BOX_GUARDIANM] = createPicture("./pictures/chat/chatPapi.bmp", CHAR_WIDTH, CHAR_HEIGHT);

  atlas->tileset = createTileset();

  setStaminaLength(atlas, 195);
  setLifePointLength(atlas, 195);
  setStaminaDst(atlas, 10, 45);
  setLifePointDst(atlas, 10, 20);

  return atlas;

}

void createBars(Atlas* atlas, SDL_Surface* screen) {
  atlas->stamina = SDL_CreateRGBSurface(SDL_HWSURFACE, getStaminaLength(atlas) + 5, 15, 32, 0, 0 ,0 ,0);
  atlas->life_point = SDL_CreateRGBSurface(SDL_HWSURFACE, getLifePointLength(atlas) + 5, 15, 32, 0, 0 ,0 ,0);
  SDL_FillRect(getStamina(atlas), NULL, SDL_MapRGB(screen->format, 1, 215, 88));
  SDL_FillRect(getLifePoint(atlas), NULL, SDL_MapRGB(screen->format, 200, 7, 7));
}

void updateBars(Game* game) {
  SDL_FreeSurface(getStamina(getGameAtlas(game)));
  SDL_FreeSurface(getLifePoint(getGameAtlas(game)));
  getGameAtlas(game)->stamina = SDL_CreateRGBSurface(SDL_HWSURFACE, getStaminaLength(getGameAtlas(game)) + 5, 15, 32, 0, 0 ,0 ,0);
  getGameAtlas(game)->life_point = SDL_CreateRGBSurface(SDL_HWSURFACE, getLifePointLength(getGameAtlas(game)) + 5, 15, 32, 0, 0 ,0 ,0);
  SDL_FillRect(getStamina(getGameAtlas(game)), NULL, SDL_MapRGB(getScreen(getGameSdl(game))->format, 1, 215, 88));
  SDL_FillRect(getLifePoint(getGameAtlas(game)), NULL, SDL_MapRGB(getScreen(getGameSdl(game))->format, 200, 7, 7));
}

void setStaminaDst(Atlas* atlas, int x, int y) {
  atlas->staminaDst.x = x;
  atlas->staminaDst.y = y;
}

void setLifePointDst(Atlas* atlas, int x, int y) {
  atlas->lifePointDst.x = x;
  atlas->lifePointDst.y = y;
}

SDL_Rect* getStaminaDst(Atlas* atlas) {
  return &atlas->staminaDst;
}

SDL_Rect* getLifePointDst(Atlas* atlas) {
  return &atlas->lifePointDst;
}

SDL_Surface* getStamina(Atlas* atlas) {
  return atlas->stamina;
}

SDL_Surface* getLifePoint(Atlas* atlas) {
  return atlas->life_point;
}

int getStaminaLength(Atlas* atlas) {
  return atlas->staminaLength;
}

void setStaminaLength(Atlas* atlas, int value) {
  atlas->staminaLength = value;
}

int getLifePointLength(Atlas* atlas) {
  return atlas->lifePointLength;
}

void setLifePointLength(Atlas* atlas, int value) {
  atlas->lifePointLength = value;
}

Picture* getPicture(Atlas* atlas, int index) {
  return atlas->pictures[index];
}

void destroyAtlas(Atlas* atlas) {

  for(int i = 0 ; i < SIZE_ATLAS ; i++) {
    destroyPicture(atlas->pictures[i]);
  }
  free(atlas->pictures);
  destroyTileset(atlas->tileset);
  SDL_FreeSurface(atlas->stamina);
  SDL_FreeSurface(atlas->life_point);
  free(atlas);
  atlas = NULL;

}
