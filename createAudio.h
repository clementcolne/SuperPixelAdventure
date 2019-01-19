#include "constants.h"

/***************************************************
this struct contains all the sounds used on the game
we also have the playMusic function to play any
music previously loaded, and destroy function
***************************************************/

typedef struct Audio {

  Mix_Chunk* music_theme;
  Mix_Chunk* music_event_quest;
  Mix_Chunk* music_event_pnj;
  Mix_Chunk* music_event_cave;

} Audio;

Audio* createAudio();
void playMusic(Audio* audio, int channel);
void destroyAudio(Audio* audio);
