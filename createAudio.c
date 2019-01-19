#include "createAudio.h"

Audio* createAudio(){

  Audio* audio = malloc(sizeof(Audio));

  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1){
    printf("Error SDL_Mixer (createAudio.c) : %s\n", Mix_GetError());
  }
  Mix_AllocateChannels(4);

  audio->music_theme = Mix_LoadWAV("./music/music_theme.wav");
  audio->music_event_quest = Mix_LoadWAV("./music/music_event_quest.wav");
  audio->music_event_pnj = Mix_LoadWAV("./music/music_event_pnj.wav");
  audio->music_event_cave = Mix_LoadWAV("./music/music_event_cave.wav");

  // channel for event's sound
  Mix_Volume(MUSIC_THEME, VOLUME_THEME);
  Mix_Volume(MUSIC_EVENT_QUEST, VOLUME_EVENT);
  Mix_Volume(MUSIC_EVENT_PNJ, VOLUME_EVENT);
  Mix_Volume(MUSIC_EVENT_CAVE, VOLUME_EVENT);

  playMusic(audio, MUSIC_THEME);

  return audio;
}

void playMusic(Audio* audio, int channel) {
  if(channel == 0) {
    Mix_PlayChannel(MUSIC_THEME, audio->music_theme, -1);
  }else if(channel == 1) {
    Mix_PlayChannel(MUSIC_EVENT_QUEST, audio->music_event_quest, 0);
  }else if(channel == 2) {
    Mix_PlayChannel(MUSIC_EVENT_PNJ, audio->music_event_pnj, 0);
  }else{
    Mix_PlayChannel(MUSIC_EVENT_CAVE, audio->music_event_cave, 0);
  }
}

void destroyAudio(Audio* audio) {

  Mix_FreeChunk(audio->music_theme);
  Mix_FreeChunk(audio->music_event_quest);
  Mix_FreeChunk(audio->music_event_pnj);
  Mix_FreeChunk(audio->music_event_cave);
  audio->music_theme = NULL;
  audio->music_event_quest = NULL;
  audio->music_event_pnj = NULL;
  audio->music_event_cave = NULL;
  Mix_CloseAudio();
  SDL_AudioQuit();
  Mix_Quit();
  free(audio);
  audio = NULL;

}
