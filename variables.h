#include "constants.h"
#include "booleans.h"

/************************************************************************
this file contain Variables struct (with all variables and booleans used)
and the functions to create, get, set and destroy booleans and variables
************************************************************************/

typedef struct Variables {

  Booleans* booleans;
  int* tabVariables;

} Variables;

Variables* createVariables();
int getBoolean(Variables* variables, int index);
void setBoolean(Variables* variables, int index, int value);
int getVariable(Variables* variables, int index);
void setVariable(Variables* variables, int index, int value);
void destroyVariables(Variables* variables);
