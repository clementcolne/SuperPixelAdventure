#include "menu.h"

void mainMenu(Game* game){

  SDL_Surface *playCase = NULL, *ruleCase = NULL, *quitCase = NULL, *screenMenu, *menuChar, *scroll;
  SDL_Surface *quitButton = NULL, *playButton = NULL, *goalButton = NULL;
  SDL_Event event;
  SDL_Rect playCasePos, ruleCasePos, quitCasePos, quitButtonPos, playButtonPos, goalButtonPos, positionChar, mainCharGo, scrollPos;
  int endMenu = 1, speed, orientation = 2, movement = 1, goalPurpose = 0;
  TTF_Font *font = NULL;
  SDL_Color couleurNoire = {0, 0, 0};
  SDL_Surface *texte1, *texte2, *texte3, *texte4, *texte5;
  SDL_Rect posTexte1, posTexte2, posTexte3, posTexte4, posTexte5;

  //boutons button_play, button_quit, button_goal, tab_button[3];
  Button* tab_button[3];

  int **tab_collide = malloc(SCREEN_WIDTH*sizeof(int*));
  for(int j = 0 ; j < SCREEN_WIDTH; j++){
    tab_collide[j] = malloc(SCREEN_HEIGHT*sizeof(int));
  }

  screenMenu = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
  SDL_FillRect(screenMenu, NULL, SDL_MapRGB(screenMenu->format, 70, 180, 55));

  Button* button_play = createButton();
  Button* button_goal = createButton();
  Button* button_quit = createButton();

  setButtonPosition(button_play, 600, 800, 200, 250);
  setButtonPosition(button_goal, 600, 800, 400, 450);
  setButtonPosition(button_quit, 600, 800, 600, 650);

  tab_button[0] = button_play;
  tab_button[1] = button_goal;
  tab_button[2] = button_quit;

  playCasePos.x = 600;
  playCasePos.y = 200;

  ruleCasePos.x = 600;
  ruleCasePos.y = 400;

  quitCasePos.x = 600;
  quitCasePos.y = 600;

  positionChar.x = 0;
  positionChar.y = 0;

  quitButtonPos.x = 600;
  quitButtonPos.y = 600;

  playButtonPos.x = 600;
  playButtonPos.y = 200;

  goalButtonPos.x = 600;
  goalButtonPos.y = 400;

  scrollPos.x = 400;
  scrollPos.y = 200;

  font = TTF_OpenFont("./font/font.ttf", 20);
  posTexte1.x = 550;
  posTexte1.y = 260;

  posTexte2.x = 450;
  posTexte2.y = 300;

  posTexte3.x = 450;
  posTexte3.y = 350;

  posTexte4.x = 450;
  posTexte4.y = 400;

  posTexte5.x = 450;
  posTexte5.y = 450;

  playCase = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0 ,0 ,0);
  SDL_FillRect(playCase, NULL, SDL_MapRGB(screenMenu->format, 160, 220, 40));

  ruleCase = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0 ,0 ,0);
  SDL_FillRect(ruleCase, NULL, SDL_MapRGB(screenMenu->format, 160, 220, 40));

  quitCase = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0 ,0 ,0);
  SDL_FillRect(quitCase, NULL, SDL_MapRGB(screenMenu->format, 160, 220, 40));

  menuChar = SDL_LoadBMP("./pictures/characters/hero.bmp");
  SDL_SetColorKey(menuChar, SDL_SRCCOLORKEY, SDL_MapRGB(menuChar->format, 255, 255, 255));

  quitButton = SDL_LoadBMP("./pictures/menu/boutonQuitter.bmp");
  SDL_SetColorKey(quitButton, SDL_SRCCOLORKEY, SDL_MapRGB(quitButton->format, 255, 255, 255));

  playButton = SDL_LoadBMP("./pictures/menu/boutonJouer.bmp");
  SDL_SetColorKey(playButton, SDL_SRCCOLORKEY, SDL_MapRGB(playButton->format, 255, 255, 255));

  goalButton = SDL_LoadBMP("./pictures/menu/boutonBut.bmp");
  SDL_SetColorKey(goalButton, SDL_SRCCOLORKEY, SDL_MapRGB(goalButton->format, 255, 255, 255));

  scroll = SDL_LoadBMP("./pictures/menu/parch1.bmp");
  SDL_SetColorKey(scroll, SDL_SRCCOLORKEY, SDL_MapRGB(scroll->format, 0, 0, 0));

  texte1 = TTF_RenderText_Solid(font, "bienvenue dans 'SuperPixelAdventure'.", couleurNoire);
  texte2 = TTF_RenderText_Solid(font, "Vous incarnerez Lien, le hero et detective sans peur. Vous devrez", couleurNoire);
  texte3 = TTF_RenderText_Solid(font, "aider les habitants de Joliland a comprendre pourquoi l'eau ne", couleurNoire);
  texte4 = TTF_RenderText_Solid(font, "coule plus dans leur jolie ville, et resoudre ce probleme", couleurNoire);
  texte5 = TTF_RenderText_Solid(font, "par vous meme.", couleurNoire);

  tab_collide = buttonCollision(tab_collide, button_play, button_goal, button_quit);

  while(endMenu){
    SDL_PollEvent(&event);

    menuMove(event, &positionChar, &goalPurpose, tab_collide, &speed, &movement, &orientation,
    button_play, button_goal, button_quit, tab_button, &endMenu, game);

    // envoyer mainCharGo, positionChar, goalPurpose, tab_collide, speed, movement, orientation, les boutons

    mainCharGo.x = CHAR_WIDTH * movement;
    mainCharGo.y = CHAR_HEIGHT * orientation;
    mainCharGo.h = CHAR_WIDTH;
    mainCharGo.w = 30;

    SDL_BlitSurface(menuChar, &mainCharGo, screenMenu, &positionChar);
    SDL_BlitSurface(playCase, NULL, screenMenu, &playCasePos);
    SDL_BlitSurface(ruleCase, NULL, screenMenu, &ruleCasePos);
    SDL_BlitSurface(quitCase, NULL, screenMenu, &quitCasePos);
    SDL_BlitSurface(quitButton, NULL, screenMenu, &quitButtonPos);
    SDL_BlitSurface(playButton, NULL, screenMenu, &playButtonPos);
    SDL_BlitSurface(goalButton, NULL, screenMenu, &goalButtonPos);
    if (goalPurpose){
      SDL_BlitSurface(scroll, NULL, screenMenu, &scrollPos);
      SDL_BlitSurface(texte1, NULL, screenMenu, &posTexte1);
      SDL_BlitSurface(texte2, NULL, screenMenu, &posTexte2);
      SDL_BlitSurface(texte3, NULL, screenMenu, &posTexte3);
      SDL_BlitSurface(texte4, NULL, screenMenu, &posTexte4);
      SDL_BlitSurface(texte5, NULL, screenMenu, &posTexte5);
    }
    SDL_UpdateRect(screenMenu, 0, 0, 0, 0);
    SDL_Flip(screenMenu);
    SDL_FillRect(screenMenu, NULL, SDL_MapRGB(screenMenu->format, 70, 180, 55));

  }

  TTF_CloseFont(font);
  destroyButton(button_play);
  destroyButton(button_goal);
  destroyButton(button_quit);
  SDL_FreeSurface(menuChar);
  SDL_FreeSurface(playCase);
  SDL_FreeSurface(ruleCase);
  SDL_FreeSurface(quitCase);
  SDL_FreeSurface(quitButton);
  SDL_FreeSurface(playButton);
  SDL_FreeSurface(goalButton);
  SDL_FreeSurface(scroll);
  SDL_FreeSurface(texte1);
  SDL_FreeSurface(texte2);
  SDL_FreeSurface(texte3);
  SDL_FreeSurface(texte4);
  SDL_FreeSurface(texte5);
  for(int j = 0 ; j < SCREEN_WIDTH ; j++){
     free(tab_collide[j]);
  }
  free(tab_collide);
  SDL_FreeSurface(screenMenu);
}
