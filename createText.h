#include "constants.h"

/********************************************************************************
this struct contain all texts used on the game, the fonts and the positions of it
********************************************************************************/

typedef struct Text {

  SDL_Surface** tab_text;
  TTF_Font* font;
  SDL_Rect textDst;

} Text;

Text* createText();
SDL_Surface* getText(Text* text, int index);
SDL_Rect* getTextDst(Text* text);
void setTextDst(Text* text, int x, int y);
void destroyText(Text* text);
