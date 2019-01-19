#pragma once
#include "constants.h"
#include "mapBuilder.h"

/***********************************************************************************
this file contain struct with the map (map_builder) and the booleans for the
collisions (map_boolean) the functions to create, update, get and destroy the tables
***********************************************************************************/

typedef struct Tables {

  Uint16** map_builder;
  Uint16** map_boolean;

} Tables;

Tables* createTables();
void updateTables(Tables* tables, int index_map);
Uint16** getTable(Tables* tables, int index);
void destroyTables();
