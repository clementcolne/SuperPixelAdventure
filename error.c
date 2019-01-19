#include "error.h"
#include "variables.h"

Error* createError() {

  Error* error = malloc(sizeof(Error));

  error->isError = FALSE;
  error->loadGame = "-> Game has launch without error\n-> Game is running\n";
  error->loadAtlas = "";
  error->loadSdl = "";

  return error;
}

void destroyError(Error* error) {
  free(error);
  error = NULL;
}

void setErrorMessage(Error* error, int index, char* message) {
  if(index == LOAD_ATLAS) error->loadAtlas = message;
  if(index == LOAD_SDL) error->loadSdl = message;
}

void setErrorIsError(Error* error, int bool) {
  error->isError = bool;
}

void threatErrors(Error* error, Game* game) {
  if(error->isError) {
    setVariable(getGameVariables(game), GAMEOVER, TRUE);
    printf("-> Game did not load\n");
    printf("-> list of errors\n");
    printf("  %s", error->loadAtlas);
    printf("  %s", error->loadSdl);
  }else{
    printf("%s", error->loadGame);
  }
}
