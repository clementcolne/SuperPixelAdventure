#include "display.h"
#include "createSDL.h"
#include "variables.h"
#include "game.h"

void display(Game* game) {
  displayMap(game);
  displayWaterfall(game);
  displayChest(game);
  displayFish(game);
  displayPass(game);
  displayAxe(game);
  displayFog(game);
  displayHero(game);
  displayPannel(game);
  displayBars(game);
  updateScreen(game);
}

void displayMap(Game* game) {

  SDL_Rect Rect_dest;
  SDL_Rect Rect_source;
  int xscroll = getVariable(getGameVariables(game), XSCROLL);
  int yscroll = getVariable(getGameVariables(game), YSCROLL);
  Rect_source.w = WIDTH_TILE;
  Rect_source.h = HEIGHT_TILE;

  // printing tiles, the file depend on the number of the tile
  // we only print the blocks inside of the scroll window
  for(int i = 0 ; i < MAP_BLOCKS_WIDTH ; i++){
    for(int j = 0 ; j < MAP_BLOCKS_HEIGHT ; j++){
      if((i*WIDTH_TILE > xscroll - WIDTH_TILE) && (i*WIDTH_TILE < xscroll + SCREEN_WIDTH + WIDTH_TILE)
        && (j*WIDTH_TILE > yscroll - WIDTH_TILE) && (j*WIDTH_TILE < yscroll + SCREEN_HEIGHT + WIDTH_TILE)){
        if(getTable(getGameTables(game), MAP_BUILDER)[i][j]<171){
          Rect_dest.x = i*WIDTH_TILE - xscroll;
          Rect_dest.y = j*HEIGHT_TILE - yscroll;
          Rect_source.x = (getTable(getGameTables(game), MAP_BUILDER)[i][j])*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(getTileset(getGameAtlas(game), TILESET1), &Rect_source, getScreen(getGameSdl(game)), &Rect_dest);
        }else if((getTable(getGameTables(game), MAP_BUILDER)[i][j]<341) && (getTable(getGameTables(game), MAP_BUILDER)[i][j]>170)){
          Rect_dest.x = i*WIDTH_TILE - xscroll;
          Rect_dest.y = j*HEIGHT_TILE - yscroll;
          Rect_source.x = (getTable(getGameTables(game), MAP_BUILDER)[i][j]%171)*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(getTileset(getGameAtlas(game), TILESET2), &Rect_source, getScreen(getGameSdl(game)), &Rect_dest);
        }else{
          Rect_dest.x = i*WIDTH_TILE - xscroll;
          Rect_dest.y = j*HEIGHT_TILE - yscroll;
          Rect_source.x = (getTable(getGameTables(game), MAP_BUILDER)[i][j]%171)*WIDTH_TILE;
          Rect_source.y = 0;
          SDL_BlitSurface(getTileset(getGameAtlas(game), TILESET3), &Rect_source, getScreen(getGameSdl(game)), &Rect_dest);
        }
      }
    }
  }
}

void displayPannel(Game* game) {
  if(getBoolean(getGameVariables(game), BOOL_PANNEL)) SDL_BlitSurface(getPicture(getGameAtlas(game), PANNEL)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), PANNEL)->dst);
  if(getBoolean(getGameVariables(game), BOOL_CHAT_BOX)){
    SDL_BlitSurface(getPicture(getGameAtlas(game), CHAT_BOX)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), CHAT_BOX)->dst);
  }
  if(getBoolean(getGameVariables(game), BOOL_CHAT_BOX_INNERKEEPER)){
    SDL_BlitSurface(getPicture(getGameAtlas(game), CHAT_BOX_INNERKEEPER)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), CHAT_BOX)->dst);
  }
  if(getBoolean(getGameVariables(game), BOOL_CHAT_BOX_WOODMAN)){
    SDL_BlitSurface(getPicture(getGameAtlas(game), CHAT_BOX_WOODMAN)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), CHAT_BOX)->dst);
  }
  if(getBoolean(getGameVariables(game), BOOL_CHAT_BOX_COUNTRYGUARD)){
    SDL_BlitSurface(getPicture(getGameAtlas(game), CHAT_BOX_COUNTRYGUARD)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), CHAT_BOX)->dst);
  }
  if(getBoolean(getGameVariables(game), BOOL_CHAT_BOX_KIDF)){
    SDL_BlitSurface(getPicture(getGameAtlas(game), CHAT_BOX_KIDF)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), CHAT_BOX)->dst);
  }
  if(getBoolean(getGameVariables(game), BOOL_CHAT_BOX_KIDM)){
    SDL_BlitSurface(getPicture(getGameAtlas(game), CHAT_BOX_KIDM)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), CHAT_BOX)->dst);
  }
  if(getBoolean(getGameVariables(game), BOOL_CHAT_BOX_FISHMAN)){
    SDL_BlitSurface(getPicture(getGameAtlas(game), CHAT_BOX_FISHMAN)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), CHAT_BOX)->dst);
  }
  if(getBoolean(getGameVariables(game), BOOL_CHAT_BOX_VILLAGER)){
    SDL_BlitSurface(getPicture(getGameAtlas(game), CHAT_BOX_VILLAGER)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), CHAT_BOX)->dst);
  }
  if(getBoolean(getGameVariables(game), BOOL_CHAT_BOX_GUARDIANS)){
    SDL_BlitSurface(getPicture(getGameAtlas(game), CHAT_BOX_GUARDIANS)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), CHAT_BOX)->dst);
  }
  if(getBoolean(getGameVariables(game), BOOL_END_GAME)) SDL_BlitSurface(getPicture(getGameAtlas(game), PANNEL)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), PANNEL)->dst);
  displayTextPannel(game);
}

void displayTextPannel(Game* game) {
  // print of text at the start of the game
  if(getBoolean(getGameVariables(game), BOOL_SPAWN)){
    setTextDst(getGameText(game), 370, 350);
    SDL_BlitSurface(getText(getGameText(game), TEXT_SPAWN_1), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 330, 410);
    SDL_BlitSurface(getText(getGameText(game), TEXT_SPAWN_2), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 580, 460);
    SDL_BlitSurface(getText(getGameText(game), TEXT_SPAWN_3), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  // print of the text with the countryguard at the start of the game
  if(getBoolean(getGameVariables(game), BOOL_COUNTRYGUARD)) {
    setTextDst(getGameText(game), 370, 420);
    SDL_BlitSurface(getText(getGameText(game), TEXT_COUNTRYGUARD_1), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 400, 480);
    SDL_BlitSurface(getText(getGameText(game), TEXT_COUNTRYGUARD_2), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  // print of the text on the pannel in the spawn
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_SPAWN)) {
    setTextDst(getGameText(game), 465, 350);
    SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_SPAWN_1), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 305, 400);
    SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_SPAWN_2), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 950, 450);
    SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_SPAWN_3), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  // print of the text when we talk to the girl
  if(getBoolean(getGameVariables(game), BOOL_GIRL)) {
    setTextDst(getGameText(game), 450, 450);
    SDL_BlitSurface(getText(getGameText(game), TEXT_GIRL), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  // print of the text when we talk to the boy
  if(getBoolean(getGameVariables(game), BOOL_BOY)) {
    setTextDst(getGameText(game), 330, 450);
    SDL_BlitSurface(getText(getGameText(game), TEXT_BOY), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  // print of the text when we talk to the innerkeeper
  if(getBoolean(getGameVariables(game), BOOL_INNERKEEPER)) {
    setTextDst(getGameText(game), 370, 410);
    SDL_BlitSurface(getText(getGameText(game), TEXT_INNERKEEPER_1), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 365, 480);
    SDL_BlitSurface(getText(getGameText(game), TEXT_INNERKEEPER_2), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  // print of the text when we talk to the villager
  if(getBoolean(getGameVariables(game), BOOL_VILLAGER)) {
    setTextDst(getGameText(game), 700, 470);
    SDL_BlitSurface(getText(getGameText(game), TEXT_VILLAGER), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  // print of the text when we talk to the fish man
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_FISH_MAN) && !getBoolean(getGameVariables(game), BOOL_FISH_QUEST)) {
    setTextDst(getGameText(game), 350, 400);
    SDL_BlitSurface(getText(getGameText(game), TEXT_FISHMAN_1), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 440, 450);
    SDL_BlitSurface(getText(getGameText(game), TEXT_FISHMAN_2), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 400, 490);
    SDL_BlitSurface(getText(getGameText(game), TEXT_FISHMAN_3), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  // print of the text when we talk to the fish man
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_WOOD_MAN) && !getBoolean(getGameVariables(game), BOOL_AXE_QUEST)) {
    setTextDst(getGameText(game), 470, 400);
    SDL_BlitSurface(getText(getGameText(game), TEXT_WOODMAN_1), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 400, 445);
    SDL_BlitSurface(getText(getGameText(game), TEXT_WOODMAN_2), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 430, 490);
    SDL_BlitSurface(getText(getGameText(game), TEXT_WOODMAN_3), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  // print of the text when we talk to the fish man
  if(getBoolean(getGameVariables(game), BOOL_GUARDIANS)) {
    setTextDst(getGameText(game), 300, 420);
    SDL_BlitSurface(getText(getGameText(game), TEXT_OLD_MAN), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 300, 470);
    SDL_BlitSurface(getText(getGameText(game), TEXT_OLD_WOMAN), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  // print of the text when the game is finished
  if(getBoolean(getGameVariables(game), BOOL_END_GAME)){
    setTextDst(getGameText(game), 380, 350);
    SDL_BlitSurface(getText(getGameText(game), TEXT_END_GAME_1), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 380, 400);
    SDL_BlitSurface(getText(getGameText(game), TEXT_END_GAME_2), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 380, 450);
    SDL_BlitSurface(getText(getGameText(game), TEXT_END_GAME_3), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }

  if(getBoolean(getGameVariables(game), BOOL_PANNEL_FISH_MAN) && getBoolean(getGameVariables(game), BOOL_FISH_QUEST)) {
    setTextDst(getGameText(game), 430, 400);
    SDL_BlitSurface(getText(getGameText(game), TEXT_FISHMAN_AFTER_1), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 400, 445);
    SDL_BlitSurface(getText(getGameText(game), TEXT_FISHMAN_AFTER_2), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 430, 490);
    SDL_BlitSurface(getText(getGameText(game), TEXT_FISHMAN_AFTER_3), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }

  if(getBoolean(getGameVariables(game), BOOL_PANNEL_WOOD_MAN) && getBoolean(getGameVariables(game), BOOL_AXE_QUEST)) {
    setTextDst(getGameText(game), 430, 400);
    SDL_BlitSurface(getText(getGameText(game), TEXT_WOODMAN_AFTER_1), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 440, 445);
    SDL_BlitSurface(getText(getGameText(game), TEXT_WOODMAN_AFTER_2), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }

  if(getBoolean(getGameVariables(game), BOOL_GUARDIANS_MAP)) {
    setTextDst(getGameText(game), 300, 420);
    SDL_BlitSurface(getText(getGameText(game), TEXT_OLD_MAN_TURN), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 300, 470);
    SDL_BlitSurface(getText(getGameText(game), TEXT_OLD_WOMAN_TURN), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }

  if(getBoolean(getGameVariables(game), BOOL_GUARDIAN_MAN)) {
    setTextDst(getGameText(game), 300, 445);
    SDL_BlitSurface(getText(getGameText(game), TEXT_OLD_WOMAN_TURN), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }

  if(getBoolean(getGameVariables(game), BOOL_GUARDIAN_WOMAN)) {
    setTextDst(getGameText(game), 300, 445);
    SDL_BlitSurface(getText(getGameText(game), TEXT_OLD_MAN_TURN), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }

  if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_ONE)){
    setTextDst(getGameText(game), 450, 380);
    SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_ONE), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_ONE)){
    setTextDst(getGameText(game), 450, 420);
    SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_ONE_2), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_TWO)){
    setTextDst(getGameText(game), 550, 400);
    SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_TWO), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_THREE)){
    setTextDst(getGameText(game), 400, 400);
    SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_THREE), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_FOUR)){
    setTextDst(getGameText(game), 400, 400);
    SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_FOUR), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
  if(getBoolean(getGameVariables(game), BOOL_PANNEL_CAVE)) {
    setTextDst(getGameText(game), 350, 350);
    SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_1), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 400, 400);
    SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_2), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
    setTextDst(getGameText(game), 350, 450);
    SDL_BlitSurface(getText(getGameText(game), TEXT_PANNEL_CAVE_3), NULL, getScreen(getGameSdl(game)), getTextDst(getGameText(game)));
  }
}

void displayHero(Game* game) {
  SDL_BlitSurface(getPicture(getGameAtlas(game), HERO)->surface, &getPicture(getGameAtlas(game), HERO)->src, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), HERO)->dst);
}

void displayWaterfall(Game* game) {
  if (getBoolean(getGameVariables(game), BOOL_END_CAVE) && getBoolean(getGameVariables(game), BOOL_WATERFALL)){
    SDL_BlitSurface(getPicture(getGameAtlas(game), WATERFALL)->surface, &getPicture(getGameAtlas(game), WATERFALL)->src, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), WATERFALL)->neg);
  }
}

void displayChest(Game* game){
  if(getBoolean(getGameVariables(game), BOOL_WATERFALL)) SDL_BlitSurface(getPicture(getGameAtlas(game), CHEST)->surface, &getPicture(getGameAtlas(game), CHEST)->src, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), CHEST)->neg);
}

void displayFog(Game* game) {
  if(getBoolean(getGameVariables(game), BOOL_FOG) && getBoolean(getGameVariables(game), BOOL_FOG_ACCESS))  SDL_BlitSurface(getPicture(getGameAtlas(game), FOG)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), FOG)->dst);
}

void displayFish(Game* game){
  if (getBoolean(getGameVariables(game), BOOL_CHEST) && !getBoolean(getGameVariables(game), BOOL_FISH_QUEST)) SDL_BlitSurface(getPicture(getGameAtlas(game), FISH)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), FISH)->dst);
}

void displayPass(Game* game){
  if (getBoolean(getGameVariables(game), BOOL_FISH_QUEST)) SDL_BlitSurface(getPicture(getGameAtlas(game), PASS_FISH)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), PASS_FISH)->dst);
  if (getBoolean(getGameVariables(game), BOOL_AXE_QUEST)) SDL_BlitSurface(getPicture(getGameAtlas(game), PASS_WOOD)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), PASS_WOOD)->dst);
}

void displayAxe(Game* game){
  if (getBoolean(getGameVariables(game), BOOL_STUMP) && !getBoolean(getGameVariables(game), BOOL_AXE_QUEST)) SDL_BlitSurface(getPicture(getGameAtlas(game), AXE)->surface, NULL, getScreen(getGameSdl(game)), &getPicture(getGameAtlas(game), AXE)->dst);
}

void displayBars(Game* game) {
  updateBars(game);
  SDL_BlitSurface(getStamina(getGameAtlas(game)), NULL, getScreen(getGameSdl(game)), getStaminaDst(getGameAtlas(game)));
  SDL_BlitSurface(getLifePoint(getGameAtlas(game)), NULL, getScreen(getGameSdl(game)), getLifePointDst(getGameAtlas(game)));
}

void updateScreen(Game* game) {
  SDL_UpdateRect(getScreen(getGameSdl(game)), 0, 0, 0, 0);
  SDL_Flip(getScreen(getGameSdl(game)));
}
