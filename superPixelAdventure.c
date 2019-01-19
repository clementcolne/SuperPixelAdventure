#include "game.h"

int main(){

  Game* game = createGame();
  runGame(game);
  destroyGame(game);

  return 0;

}
