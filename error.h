#pragma once
#include "constants.h"
#include "game.h"

/*****************************************************
This file threat the errors at the load of the game to
avoid segfaults when a picture or a map didn't load
*****************************************************/

typedef struct Error {
  int isError;
  char* loadGame;
  char* loadAtlas;
  char* loadSdl;
  char* loadAudio;
} Error;

typedef struct Variables Variables;

Error* createError();
void destroyError(Error* error);
void setErrorMessage(Error* error, int index, char* message);
void setErrorIsError(Error* error, int bool);
void threatErrors(Error* error, Game* game);
