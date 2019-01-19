#include "variables.h"

Variables* createVariables() {

  Variables* variables = malloc(sizeof(Variables));
  variables->tabVariables = malloc(sizeof(Variables*) * SIZE_TAB_VARIABLES);

  variables->booleans = createBooleans();

  variables->tabVariables[XCHAR] = 0;
  variables->tabVariables[YCHAR] = 0;
  variables->tabVariables[XSCROLL] = MAP_PIXELS_X - SCREEN_WIDTH;
  variables->tabVariables[YSCROLL] = MAP_PIXELS_Y - SCREEN_HEIGHT;
  variables->tabVariables[SPRINT] = 1;
  variables->tabVariables[GAMEOVER] = 0;
  variables->tabVariables[WIDTH] = 0;
  variables->tabVariables[DIR] = 0;
  variables->tabVariables[PREC_XSCROLL] = 0;
  variables->tabVariables[PREC_YSCROLL] = 0;
  variables->tabVariables[PREC_POSCHAR_X] = 0;
  variables->tabVariables[PREC_POSCHAR_Y] = 0;
  variables->tabVariables[PREC_POSWATERFALL_X] = 0;
  variables->tabVariables[PREC_POSWATERFALL_Y] = 0;
  variables->tabVariables[CPT] = 0;
  variables->tabVariables[ANIMATION] = 0;
  variables->tabVariables[CPT_CHEST] = 0;

  return variables;

}

int getBoolean(Variables* variables, int index) {
  return variables->booleans->tabBooleans[index];
}

void setBoolean(Variables* variables, int index, int value) {
  variables->booleans->tabBooleans[index] = value;
}

int getVariable(Variables* variables, int index) {
  return variables->tabVariables[index];
}

void setVariable(Variables* variables, int index, int value) {
  variables->tabVariables[index] = value;
}

void destroyVariables(Variables* variables) {
  free(variables->tabVariables);
  destroyBooleans(variables->booleans);
  free(variables);
  variables = NULL;
}
