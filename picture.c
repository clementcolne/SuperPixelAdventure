#include "picture.h"
#include "atlas.h"

Picture* createPicture(char* name, int width, int height) {

  Picture* picture = malloc(sizeof(Picture));

  picture->surface = SDL_LoadBMP(name);

  picture->src.x = 0;
  picture->src.y = 0;
  picture->src.w = width;
  picture->src.h = height;

  picture->dst.x = 0;
  picture->dst.y = 0;
  picture->dst.w = 0;
  picture->dst.h = 0;

  picture->neg.x = 0;
  picture->neg.y = 0;
  picture->neg.w = 0;
  picture->neg.h = 0;

  picture->isPrinted = 1;
  picture->isNeg = 0;

  return picture;

}

void destroyPicture(Picture* picture) {

  SDL_FreeSurface(picture->surface);
  free(picture);
  picture = NULL;

}

void setDstPosition(Atlas* atlas, int index, int x, int y) {

  atlas->pictures[index]->dst.x = x;
  atlas->pictures[index]->dst.y = y;

}

void setSrcPosition(Atlas* atlas, int index, int x, int y) {

  atlas->pictures[index]->src.x = x;
  atlas->pictures[index]->src.y = y;

}

int getPictureX(Atlas* atlas, int index){
  return atlas->pictures[index]->dst.x;
}

int getPictureY(Atlas* atlas, int index){
  return atlas->pictures[index]->dst.y;
}

void setPictureX(Picture* picture, int x){
  picture->dst.x = x;
}

void setPictureY(Picture* picture, int y){
  picture->dst.y = y;
}

void setPictureNegX(Picture* picture, int x, int isNeg){
  picture->neg.x = x;
  picture->isNeg = isNeg;
}

void setPictureNegY(Picture* picture, int y, int isNeg){
  picture->neg.y = y;
  picture->isNeg = isNeg;
}

int getIsPrinted(Atlas* atlas, int index) {
  return atlas->pictures[index]->isPrinted;
}

int getIsNeg(Atlas* atlas, int index) {
  return atlas->pictures[index]->isNeg;
}
