#include "constants.h"

/****************************************************
this struct contain all the booleans used on the game
****************************************************/

typedef struct Booleans {

  int* tabBooleans;

} Booleans;

Booleans* createBooleans();
void destroyBooleans(Booleans* booleans);
