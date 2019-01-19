#include "tables.h"

Tables* createTables() {

  Tables* tables = malloc(sizeof(Tables));

  tables->map_builder = mapBuilder(MAP_NO_WATER_SPAWN_OLD);
  tables->map_boolean = mapBoolean(tables->map_builder);

  return tables;

}

void updateTables(Tables* tables, int index_map) {

  destroyTab(tables->map_builder);
  destroyTab(tables->map_boolean);

  tables->map_builder = mapBuilder(index_map);
  tables->map_boolean = mapBoolean(tables->map_builder);

}

Uint16** getTable(Tables* tables, int index) {

  Uint16** table;

  if(!index) table = tables->map_builder;
  if(index) table = tables->map_boolean;

  return table;
}

void destroyTables(Tables* tables) {

  destroyTab(tables->map_builder);
  destroyTab(tables->map_boolean);
  free(tables);
  tables = NULL;

}
