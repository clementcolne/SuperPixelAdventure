#include "mapBuilder.h"

Uint16** mapBuilder(int number){

    FILE* file;
    int tmp, i, j;

    // memory allocation
    Uint16 **map_builder = malloc(MAP_BLOCKS_WIDTH*sizeof(Uint16*));
    for(j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
      map_builder[j] = malloc(MAP_BLOCKS_HEIGHT*sizeof(Uint16));
    }

    // we only load the necessary file
    if(number==1) {
      file = fopen("./maps/map_water.txt", "r");
    }else if(number==2) {
      file = fopen("./maps/map_no_water_spawn_old.txt", "r");
    }else if(number==3) {
      file = fopen("./maps/map_no_water_no_spawn_old.txt", "r");
    }else if(number==4) {
      file = fopen("./maps/map_no_water_no_spawn_no_old.txt", "r");
    }else if(number==5){
      file = fopen("./maps/map_cave.txt", "r");
    }

    if(!file) {
      printf("Error : map didn't load\n");
      return 0;
    }

    for(i = 0 ; i < MAP_BLOCKS_HEIGHT; i++){
      for(j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
        fscanf(file, "%d", &tmp);
        map_builder[j][i] = tmp;
      }
    }

    fclose(file);
    return map_builder;

}

Uint16** mapBoolean(Uint16** map_builder) {

    // memory allocation
    Uint16** map_boolean = malloc(MAP_BLOCKS_WIDTH*sizeof(Uint16*));
    for(int j = 0 ; j < MAP_BLOCKS_WIDTH; j++) {
      map_boolean[j] = malloc(MAP_BLOCKS_HEIGHT*sizeof(Uint16));
    }

    // only define full blocs
    for(int i = 0 ; i < MAP_BLOCKS_HEIGHT; i++){
      for(int j = 0 ; j < MAP_BLOCKS_WIDTH; j++){
        if(map_builder[j][i]==77){
          map_boolean[j][i] = 2;
        }else if(map_builder[j][i]==399 || map_builder[j][i]==400) {
          map_boolean[j][i] = 3;
	      }else if(map_builder[j][i]==78) {
          map_boolean[j][i] = 4;
        }else if(map_builder[j][i]==53){
          map_boolean[j][i] = 5;
        }else if(map_builder[j][i]==347){
          map_boolean[j][i] = 6;
        }else if(map_builder[j][i]==346){
          map_boolean[j][i] = 7;
        }else if(map_builder[j][i]==345){
          map_boolean[j][i] = 8;
        }else if(map_builder[j][i]==344){
          map_boolean[j][i] = 9;
        }else if(map_builder[j][i]==287){
          map_boolean[j][i] = 10;
        }else if(map_builder[j][i]==284){
          map_boolean[j][i] = 11;
        }else if(map_builder[j][i]==265){
          map_boolean[j][i] = 12;
        }else if(map_builder[j][i]==262){
          map_boolean[j][i] = 13;
        }else if(map_builder[j][i]==116){
          map_boolean[j][i] = 14;
        }else if(map_builder[j][i]==401){
          map_boolean[j][i] = 15;
        }else if(map_builder[j][i]==136){
          map_boolean[j][i] = 16;
        }else if(map_builder[j][i]==403){
          map_boolean[j][i] = 17;
        }else if(map_builder[j][i]==386){
          map_boolean[j][i] = 18;
        }else if(map_builder[j][i]==390){
          map_boolean[j][i] = 19;
        }else{
          map_boolean[j][i] = isEmpty(map_builder[j][i]);
        }
      }
    }

    return map_boolean;

}

void destroyTab(Uint16** tab) {

  for(int j = 0 ; j < MAP_BLOCKS_WIDTH ; j++){
     free(tab[j]);
  }
  free(tab);

}
