#include "keyboardEvent.h"
#include "variables.h"
#include "game.h"

void keyboardEvent(SDL_Event event, Game* game){

	int xchar = getVariable(getGameVariables(game), XCHAR);
	int ychar = getVariable(getGameVariables(game), YCHAR);

  switch(event.type){
	  case SDL_KEYDOWN:
      switch(event.key.keysym.sym){
			  case SDLK_LSHIFT:
					if(getBoolean(getGameVariables(game), BOOL_END_GAME)){
						setVariable(getGameVariables(game), GAMEOVER, TRUE);
					}else{
				  	setVariable(getGameVariables(game), SPRINT, 2);
					}
				  break;

			  case SDLK_e:
					if(getBoolean(getGameVariables(game), BOOL_END_GAME)){
						setVariable(getGameVariables(game), GAMEOVER, TRUE);
					}else{
				  	pressE(game, xchar, ychar);
					}
			    break;

				case SDLK_z:
					if(getBoolean(getGameVariables(game), BOOL_END_GAME)){
						setVariable(getGameVariables(game), GAMEOVER, TRUE);
					}else{
				  	pressZ(game, xchar, ychar);
					}
				  break;

				case SDLK_s:
					// gameover set to true not activated because we press it when we leave the cave
				  pressS(game, xchar, ychar);
				  break;

				case SDLK_d:
					if(getBoolean(getGameVariables(game), BOOL_END_GAME)){
						setVariable(getGameVariables(game), GAMEOVER, TRUE);
					}else{
				  	pressD(game, xchar, ychar);
					}
				  break;

				case SDLK_q:
					if(getBoolean(getGameVariables(game), BOOL_END_GAME)){
						setVariable(getGameVariables(game), GAMEOVER, TRUE);
					}else{
				  	pressQ(game, xchar, ychar);
					}
				  break;

				case SDLK_ESCAPE:
				  setVariable(getGameVariables(game), GAMEOVER, TRUE);
				  break;

				default:
					break;
		  }
			break;
    case SDL_KEYUP:
			switch(event.key.keysym.sym){
				case SDLK_LSHIFT:
				  setVariable(getGameVariables(game), SPRINT, 1);
					break;
			  case SDLK_z:
				  setVariable(getGameVariables(game), DIR, 8);
				 	break;
				case SDLK_s:
				  setVariable(getGameVariables(game), DIR, 8);
				  break;
				case SDLK_d:
				  setVariable(getGameVariables(game), DIR, 8);
				  break;
				case SDLK_q:
				  setVariable(getGameVariables(game), DIR, 8);
				  break;
				default:
					break;
			}
			default:
			  break;
  }
}

void pressE(Game* game, int xchar, int ychar) {

	talkToCountryGuard(game);
	talkToPannelSpawn(game);
	talkToGirl(game);
	talkToBoy(game);
	talkToInnerkeeper(game);
	talkToVillager(game);
	talkToFishMan(game);
	talkToWoodMan(game);
	talkToGuardians(game);

	if((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==4) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==4)) {
		setBoolean(getGameVariables(game), BOOL_PANNEL, TRUE);
		setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE, TRUE);
	}
	if((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==6) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==6)) {
		setBoolean(getGameVariables(game), BOOL_PANNEL, TRUE);
		setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_ONE, TRUE);
	}
	if((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==7) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==7)) {
		setBoolean(getGameVariables(game), BOOL_PANNEL, TRUE);
		setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_TWO, TRUE);
	}
	if((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==8) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==8)) {
		setBoolean(getGameVariables(game), BOOL_PANNEL, TRUE);
		setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_THREE, TRUE);
	}
	if((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==9) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==9)) {
		setBoolean(getGameVariables(game), BOOL_PANNEL, TRUE);
		setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_FOUR, TRUE);
	}

	if(((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+15)/32][(ychar-5)/32]==12) || getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-15)/32+1][(ychar-5)/32]==2) &&
	    !getBoolean(getGameVariables(game), BOOL_LEVIER_UN) && !getBoolean(getGameVariables(game), BOOL_LEVIER_DEUX) &&
		  !getBoolean(getGameVariables(game), BOOL_LEVIER_QUATRE) && !getBoolean(getGameVariables(game), BOOL_END_CAVE)) {
		setBoolean(getGameVariables(game), BOOL_LEVIER_TROIS, TRUE);
	}else if(((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+15)/32][(ychar-5)/32]==13) || getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-15)/32+1][(ychar-5)/32]==2) &&
	        !getBoolean(getGameVariables(game), BOOL_LEVIER_UN) && !getBoolean(getGameVariables(game), BOOL_LEVIER_DEUX) &&
		  getBoolean(getGameVariables(game), BOOL_LEVIER_TROIS)) {
		setBoolean(getGameVariables(game), BOOL_LEVIER_QUATRE, TRUE);
	}else if(((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+15)/32][(ychar-5)/32]==11) || getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-15)/32+1][(ychar-5)/32]==2) &&
	        !getBoolean(getGameVariables(game), BOOL_LEVIER_UN) && getBoolean(getGameVariables(game), BOOL_LEVIER_QUATRE)) {
		setBoolean(getGameVariables(game), BOOL_LEVIER_DEUX, TRUE);
	}else if(((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+15)/32][(ychar-5)/32]==10) || getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-15)/32+1][(ychar-5)/32]==2) &&
					getBoolean(getGameVariables(game), BOOL_LEVIER_QUATRE)){
		setBoolean(getGameVariables(game), BOOL_LEVIER_UN, TRUE);
	}else{
		setBoolean(getGameVariables(game), BOOL_LEVIER_UN, FALSE);
		setBoolean(getGameVariables(game), BOOL_LEVIER_DEUX, FALSE);
		setBoolean(getGameVariables(game), BOOL_LEVIER_TROIS, FALSE);
		setBoolean(getGameVariables(game), BOOL_LEVIER_QUATRE, FALSE);
	}
	if(getBoolean(getGameVariables(game), BOOL_LEVIER_UN) && getBoolean(getGameVariables(game), BOOL_LEVIER_DEUX) &&
	   getBoolean(getGameVariables(game), BOOL_LEVIER_TROIS) && getBoolean(getGameVariables(game), BOOL_LEVIER_QUATRE)){
		setBoolean(getGameVariables(game), BOOL_FOG, FALSE);
		setBoolean(getGameVariables(game), BOOL_FOG_ACCESS, FALSE);
		setBoolean(getGameVariables(game), BOOL_END_CAVE, TRUE);
		playMusic(getGameAudio(game), MUSIC_EVENT_CAVE);
	}

	if ((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==15) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==15)){
		setBoolean(getGameVariables(game), BOOL_FISHMAN, TRUE);
	}

	if ((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==17) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==17)){
		setBoolean(getGameVariables(game), BOOL_WOODMAN, TRUE);
	}

	if(((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==14) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==14)) &&
		getBoolean(getGameVariables(game), BOOL_FISHMAN)) {
		setBoolean(getGameVariables(game), BOOL_CHEST, TRUE);
		playMusic(getGameAudio(game), MUSIC_EVENT_QUEST);
	}

	if(getBoolean(getGameVariables(game), BOOL_CHEST)){
		if((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==15) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==15)) {
			setBoolean(getGameVariables(game), BOOL_FISH_QUEST, TRUE);
			setBoolean(getGameVariables(game), BOOL_CHEST, FALSE);
		}
	}

	if(((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==16) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==16) ||
			(getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+10)/32+1][ychar/32]==16) || (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+10)/32+1][ychar/32+1]==16))
			&& getBoolean(getGameVariables(game), BOOL_WOODMAN)) {
		setBoolean(getGameVariables(game), BOOL_STUMP, TRUE);
		playMusic(getGameAudio(game), MUSIC_EVENT_QUEST);
	}

	if(getBoolean(getGameVariables(game), BOOL_STUMP)){
		if((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==17) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==17)) {
			setBoolean(getGameVariables(game), BOOL_AXE_QUEST, TRUE);
			setBoolean(getGameVariables(game), BOOL_STUMP, FALSE);
		}
	}

	if(((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==18) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==18)) &&
	 	getBoolean(getGameVariables(game), BOOL_FISH_QUEST) && getBoolean(getGameVariables(game), BOOL_AXE_QUEST)){
		setBoolean(getGameVariables(game), BOOL_OLDMAN_CAVE, TRUE);
	}

	if(((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-5)/32]==19) || (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-5)/32]==19)) &&
	 	getBoolean(getGameVariables(game), BOOL_AXE_QUEST) && getBoolean(getGameVariables(game), BOOL_FISH_QUEST)){
		setBoolean(getGameVariables(game), BOOL_OLDWOMAN_CAVE, TRUE);
	}
}

void pressZ(Game* game, int xchar, int ychar) {

	resetVariables(game, 3);

	if(getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-15)/32]==3 && getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-15)/32]==3){
		setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) - 4 * getVariable(getGameVariables(game), SPRINT));
	}
	if (getVariable(getGameVariables(game), YSCROLL) > 0){
		if((getPictureY(getGameAtlas(game), HERO) > 448) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-1)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-1)/32]==0)) {
			setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) - 4 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
				setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + (1 * getVariable(getGameVariables(game), SPRINT)));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
		}else if((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-7)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-1)/32]==0)){
			setVariable(getGameVariables(game), YSCROLL, (getVariable(getGameVariables(game), YSCROLL) - 8 * getVariable(getGameVariables(game), SPRINT)));
			setPictureY(getPicture(getGameAtlas(game), WATERFALL), getPictureY(getGameAtlas(game), WATERFALL) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), CHEST), getPictureY(getGameAtlas(game), CHEST) + 8 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
				setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + (1 * getVariable(getGameVariables(game), SPRINT)));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
			if (getVariable(getGameVariables(game), SPRINT) == 2 && getStaminaLength(getGameAtlas(game)) > 1){
				setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * getVariable(getGameVariables(game), SPRINT)));
			}else if (getStaminaLength(getGameAtlas(game)) <= 2){
				setVariable(getGameVariables(game), SPRINT, 1);
			}
		}
	}else if((getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-1)/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-1)/32]==0)){
		setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) - 4 * getVariable(getGameVariables(game), SPRINT));
		if (getVariable(getGameVariables(game), DIR) < 20){
			setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + (1 * getVariable(getGameVariables(game), SPRINT)));
		}else{
			setVariable(getGameVariables(game), DIR, 0);
		}
		if (getVariable(getGameVariables(game), SPRINT) == 2 && getStaminaLength(getGameAtlas(game)) > 1){
			setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * getVariable(getGameVariables(game), SPRINT)));
		}else if (getStaminaLength(getGameAtlas(game)) <= 2){
			setVariable(getGameVariables(game), SPRINT, 1);
		}
	}
}

void pressS(Game* game, int xchar, int ychar) {

	resetVariables(game, 0);

	if(getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar-20)/32+2]==5 && getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar-20)/32+2]==5){
		setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) + 4 * getVariable(getGameVariables(game), SPRINT));
	}
	if (getVariable(getGameVariables(game), YSCROLL) < MAP_PIXELS_Y - SCREEN_HEIGHT){
		if((getPictureY(getGameAtlas(game), HERO) < 448) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+8)/32][(ychar+8)/32+1]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar+8)/32]==0)) {
			setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) + 4 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
				setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + (1 * getVariable(getGameVariables(game), SPRINT)));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
		}else if ((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+8)/32][(ychar+8)/32+1]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar+8)/32+1]==0)){
			setVariable(getGameVariables(game), YSCROLL, getVariable(getGameVariables(game), YSCROLL) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), WATERFALL), getPictureY(getGameAtlas(game), WATERFALL) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureY(getPicture(getGameAtlas(game), CHEST), getPictureY(getGameAtlas(game), CHEST) - 8 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
			setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + (1 * getVariable(getGameVariables(game), SPRINT)));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
			if (getVariable(getGameVariables(game), SPRINT) == 2 && getStaminaLength(getGameAtlas(game)) > 1){
				setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * getVariable(getGameVariables(game), SPRINT)));
			}else if (getStaminaLength(getGameAtlas(game)) <= 2){
				setVariable(getGameVariables(game), SPRINT, 1);
			}
		}
	}else if((getVariable(getGameVariables(game), YSCROLL) < MAP_PIXELS_Y) && (getPictureY(getGameAtlas(game), HERO) < SCREEN_HEIGHT - CHAR_HEIGHT)){
		if(xchar/32 < 133){
			if((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+8)/32][(ychar+8)/32+1]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32+1][(ychar+8)/32+1]==0)){
				setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) + 4 * getVariable(getGameVariables(game), SPRINT));
				if (getVariable(getGameVariables(game), DIR) < 20){
					setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + (1 * getVariable(getGameVariables(game), SPRINT)));
				}else{
					setVariable(getGameVariables(game), DIR, 0);
				}
			}
		}else{
			if((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+8)/32][(ychar+8)/32+1]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[xchar/32][(ychar+8)/32+1]==0)){
				setPictureY(getPicture(getGameAtlas(game), HERO), getPictureY(getGameAtlas(game), HERO) + 4 * getVariable(getGameVariables(game), SPRINT));
				if (getVariable(getGameVariables(game), DIR) < 20){
					setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + (1 * getVariable(getGameVariables(game), SPRINT)));
				}else{
					setVariable(getGameVariables(game), DIR, 0);
				}
			}
		}
	}
}

void pressD(Game* game, int xchar, int ychar) {

	resetVariables(game, 2);

	if (getVariable(getGameVariables(game), XSCROLL) < MAP_PIXELS_X - SCREEN_WIDTH){
		if((getPictureX(getGameAtlas(game), HERO) < 720) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32+1][ychar/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32+1][ychar/32+1]==0)) {
			setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) + 4 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
				setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + (1 * getVariable(getGameVariables(game), SPRINT)));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
		}else if ((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32+1][ychar/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32+1][ychar/32+1]==0)){
			setVariable(getGameVariables(game), XSCROLL, getVariable(getGameVariables(game), XSCROLL) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), WATERFALL), getPictureX(getGameAtlas(game), WATERFALL) - 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), CHEST), getPictureX(getGameAtlas(game), CHEST) - 8 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
				setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + (1 * getVariable(getGameVariables(game), SPRINT)));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
			if (getVariable(getGameVariables(game), SPRINT) == 2 && getStaminaLength(getGameAtlas(game)) > 1){
				setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * getVariable(getGameVariables(game), SPRINT)));
			}else if (getStaminaLength(getGameAtlas(game)) <= 2){
				setVariable(getGameVariables(game), SPRINT, 1);
			}
		}
	}else if((getVariable(getGameVariables(game), XSCROLL) < MAP_PIXELS_X) && (getPictureX(getGameAtlas(game), HERO) < SCREEN_WIDTH - CHAR_WIDTH)){
		if((xchar)/32 < 133){
			if((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32+1][ychar/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32+1][ychar/32+1]==0)){
				setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) + 4 * getVariable(getGameVariables(game), SPRINT));
				if (getVariable(getGameVariables(game), DIR) < 20){
					setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + (1 * getVariable(getGameVariables(game), SPRINT)));
				}else{
					setVariable(getGameVariables(game), DIR, 0);
				}
			}
		}else{
			if((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32][ychar/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar+7)/32][ychar/32+1]==0) && (xchar < 4281)){
				setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) + 4 * getVariable(getGameVariables(game), SPRINT));
				if (getVariable(getGameVariables(game), DIR) < 20){
					setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + (1 * getVariable(getGameVariables(game), SPRINT)));
				}else{
				setVariable(getGameVariables(game), DIR, 0);
				}
			}
		}
	}
}

void pressQ(Game* game, int xchar, int ychar) {

	resetVariables(game, 1);

	if (getVariable(getGameVariables(game), XSCROLL) > 0){
		if((getPictureX(getGameAtlas(game), HERO) > 720) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-7)/32][ychar/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-7)/32][ychar/32+1]==0)) {
			setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) - 4 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
				setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + (1 * getVariable(getGameVariables(game), SPRINT)));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
		}else if ((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-7)/32][ychar/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-7)/32][ychar/32+1]==0)){
			setVariable(getGameVariables(game), XSCROLL, (getVariable(getGameVariables(game), XSCROLL) - 8 * getVariable(getGameVariables(game), SPRINT)));
			setPictureX(getPicture(getGameAtlas(game), WATERFALL), getPictureX(getGameAtlas(game), WATERFALL) + 8 * getVariable(getGameVariables(game), SPRINT));
			setPictureX(getPicture(getGameAtlas(game), CHEST), getPictureX(getGameAtlas(game), CHEST) + 8 * getVariable(getGameVariables(game), SPRINT));
			if (getVariable(getGameVariables(game), DIR) < 20){
				setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + (1 * getVariable(getGameVariables(game), SPRINT)));
			}else{
				setVariable(getGameVariables(game), DIR, 0);
			}
			if (getVariable(getGameVariables(game), SPRINT) == 2 && getStaminaLength(getGameAtlas(game)) > 1){
				setStaminaLength(getGameAtlas(game), getStaminaLength(getGameAtlas(game)) - (1 * getVariable(getGameVariables(game), SPRINT)));
			}else if (getStaminaLength(getGameAtlas(game)) <= 2){
				setVariable(getGameVariables(game), SPRINT, 1);
			}
		}
	}else if ((getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-7)/32][ychar/32]==0) && (getTable(getGameTables(game), MAP_BOOLEAN)[(xchar-7)/32][ychar/32+1]==0)){
		setPictureX(getPicture(getGameAtlas(game), HERO), getPictureX(getGameAtlas(game), HERO) - 4 * getVariable(getGameVariables(game), SPRINT));
		if (getVariable(getGameVariables(game), DIR) < 20){
			setVariable(getGameVariables(game), DIR, getVariable(getGameVariables(game), DIR) + (1 * getVariable(getGameVariables(game), SPRINT)));
		}else{
			setVariable(getGameVariables(game), DIR, 0);
		}
	}
}

void talkToCountryGuard(Game* game) {
  int xchar = getVariable(getGameVariables(game), XCHAR);
  int ychar = getVariable(getGameVariables(game), YCHAR);
  if(getTable(getGameTables(game), MAP_BUILDER)[xchar/32][(ychar+10)/32+1]==369 || getTable(getGameTables(game), MAP_BUILDER)[(xchar+15)/32][(ychar+10)/32+1]==369){
    setBoolean(getGameVariables(game), BOOL_COUNTRYGUARD, TRUE);
    setBoolean(getGameVariables(game), BOOL_CHAT_BOX_COUNTRYGUARD, TRUE);
		playMusic(getGameAudio(game), MUSIC_EVENT_PNJ);
  }else{
    setBoolean(getGameVariables(game), BOOL_COUNTRYGUARD, FALSE);
  }
}

void talkToPannelSpawn(Game* game) {
  int xchar = getVariable(getGameVariables(game), XCHAR);
  int ychar = getVariable(getGameVariables(game), YCHAR);
  if(getTable(getGameTables(game), MAP_BUILDER)[xchar/32][(ychar-1)/32]==77 || getTable(getGameTables(game), MAP_BUILDER)[(xchar+15)/32][(ychar-1)/32]==77){
    setBoolean(getGameVariables(game), BOOL_PANNEL_SPAWN, TRUE);
    setBoolean(getGameVariables(game), BOOL_PANNEL, TRUE);
    setBoolean(getGameVariables(game), BOOL_END_SPAWN, TRUE);
  }else{
    setBoolean(getGameVariables(game), BOOL_PANNEL_SPAWN, FALSE);
  }
}

void talkToGirl(Game* game) {
  int xchar = getVariable(getGameVariables(game), XCHAR);
  int ychar = getVariable(getGameVariables(game), YCHAR);
  if(getTable(getGameTables(game), MAP_BUILDER)[(xchar+10)/32+1][ychar/32]==376 || getTable(getGameTables(game), MAP_BUILDER)[(xchar+10)/32+1][(ychar+15)/32]==376){
    setBoolean(getGameVariables(game), BOOL_GIRL, TRUE);
    setBoolean(getGameVariables(game), BOOL_CHAT_BOX_KIDF, TRUE);
		playMusic(getGameAudio(game), MUSIC_EVENT_PNJ);
  }else{
    setBoolean(getGameVariables(game), BOOL_GIRL, FALSE);
  }
}

void talkToBoy(Game* game) {
  int xchar = getVariable(getGameVariables(game), XCHAR);
  int ychar = getVariable(getGameVariables(game), YCHAR);
  if(getTable(getGameTables(game), MAP_BUILDER)[(xchar+10)/32][ychar/32+2]==384){
    setBoolean(getGameVariables(game), BOOL_BOY, TRUE);
    setBoolean(getGameVariables(game), BOOL_CHAT_BOX_KIDM, TRUE);
		playMusic(getGameAudio(game), MUSIC_EVENT_PNJ);
  }else{
    setBoolean(getGameVariables(game), BOOL_BOY, FALSE);
  }
}

void talkToInnerkeeper(Game* game) {
  int xchar = getVariable(getGameVariables(game), XCHAR);
  int ychar = getVariable(getGameVariables(game), YCHAR);
  if(getTable(getGameTables(game), MAP_BUILDER)[xchar/32][(ychar-10)/32]==394 || getTable(getGameTables(game), MAP_BUILDER)[xchar/32+1][(ychar-10)/32]==394){
    setBoolean(getGameVariables(game), BOOL_INNERKEEPER, TRUE);
    setBoolean(getGameVariables(game), BOOL_CHAT_BOX_INNERKEEPER, TRUE);
		playMusic(getGameAudio(game), MUSIC_EVENT_PNJ);
  }else{
    setBoolean(getGameVariables(game), BOOL_INNERKEEPER, FALSE);
  }
}

void talkToVillager(Game* game) {
  int xchar = getVariable(getGameVariables(game), XCHAR);
  int ychar = getVariable(getGameVariables(game), YCHAR);
  if(getTable(getGameTables(game), MAP_BUILDER)[(xchar+10)/32][ychar/32+2]==367){
    setBoolean(getGameVariables(game), BOOL_VILLAGER, TRUE);
    setBoolean(getGameVariables(game), BOOL_CHAT_BOX_VILLAGER, TRUE);
		playMusic(getGameAudio(game), MUSIC_EVENT_PNJ);
  }else{
    setBoolean(getGameVariables(game), BOOL_VILLAGER, FALSE);
  }
}

void talkToFishMan(Game* game) {
  int xchar = getVariable(getGameVariables(game), XCHAR);
  int ychar = getVariable(getGameVariables(game), YCHAR);
  if(getTable(getGameTables(game), MAP_BUILDER)[xchar/32][(ychar-10)/32]==401 || getTable(getGameTables(game), MAP_BUILDER)[xchar/32+1][(ychar-10)/32]==401){
    setBoolean(getGameVariables(game), BOOL_PANNEL_FISH_MAN, TRUE);
    setBoolean(getGameVariables(game), BOOL_CHAT_BOX_FISHMAN, TRUE);
		playMusic(getGameAudio(game), MUSIC_EVENT_PNJ);
  }else{
    setBoolean(getGameVariables(game), BOOL_PANNEL_FISH_MAN, FALSE);
  }
}

void talkToWoodMan(Game* game) {
  int xchar = getVariable(getGameVariables(game), XCHAR);
  int ychar = getVariable(getGameVariables(game), YCHAR);
  if(getTable(getGameTables(game), MAP_BUILDER)[xchar/32][(ychar-10)/32]==403 || getTable(getGameTables(game), MAP_BUILDER)[xchar/32+1][(ychar-10)/32]==403){
    setBoolean(getGameVariables(game), BOOL_PANNEL_WOOD_MAN, TRUE);
    setBoolean(getGameVariables(game), BOOL_CHAT_BOX_WOODMAN, TRUE);
		playMusic(getGameAudio(game), MUSIC_EVENT_PNJ);
  }else{
    setBoolean(getGameVariables(game), BOOL_PANNEL_WOOD_MAN, FALSE);
  }
}

void talkToGuardians(Game* game) {
  int xchar = getVariable(getGameVariables(game), XCHAR);
  int ychar = getVariable(getGameVariables(game), YCHAR);
  if(getTable(getGameTables(game), MAP_BUILDER)[xchar/32][(ychar-10)/32]==386 || getTable(getGameTables(game), MAP_BUILDER)[xchar/32+1][(ychar-10)/32]==386 ||
      getTable(getGameTables(game), MAP_BUILDER)[xchar/32][(ychar-10)/32]==390 || getTable(getGameTables(game), MAP_BUILDER)[xchar/32+1][(ychar-10)/32]==390){
    if(getBoolean(getGameVariables(game), BOOL_AXE_QUEST) && getBoolean(getGameVariables(game), BOOL_FISH_QUEST)){
      setBoolean(getGameVariables(game), BOOL_GUARDIANS_MAP, TRUE);
      setBoolean(getGameVariables(game), BOOL_CHAT_BOX_GUARDIANS, TRUE);
			playMusic(getGameAudio(game), MUSIC_EVENT_PNJ);
    }else{
      setBoolean(getGameVariables(game), BOOL_GUARDIANS, TRUE);
      setBoolean(getGameVariables(game), BOOL_CHAT_BOX_GUARDIANS, TRUE);
			playMusic(getGameAudio(game), MUSIC_EVENT_PNJ);
    }
  }else{
    setBoolean(getGameVariables(game), BOOL_GUARDIANS, FALSE);
  }

  if(getTable(getGameTables(game), MAP_BUILDER)[(xchar+10)/32+1][ychar/32]==391 || getTable(getGameTables(game), MAP_BUILDER)[(xchar+10)/32+1][(ychar-15)/32]==391){
    setBoolean(getGameVariables(game), BOOL_GUARDIAN_WOMAN, TRUE);
    setBoolean(getGameVariables(game), BOOL_CHAT_BOX_GUARDIANF, TRUE);
		playMusic(getGameAudio(game), MUSIC_EVENT_PNJ);
  }else{
    setBoolean(getGameVariables(game), BOOL_GUARDIAN_WOMAN, FALSE);
  }
  if(getTable(getGameTables(game), MAP_BUILDER)[(xchar)/32-1][(ychar)/32]==392 || getTable(getGameTables(game), MAP_BUILDER)[(xchar)/32-1][(ychar-15)/32]==392){
    setBoolean(getGameVariables(game), BOOL_GUARDIAN_MAN, TRUE);
    setBoolean(getGameVariables(game), BOOL_CHAT_BOX_GUARDIANM, TRUE);
		playMusic(getGameAudio(game), MUSIC_EVENT_PNJ);
  }else{
    setBoolean(getGameVariables(game), BOOL_GUARDIAN_MAN, FALSE);
  }
}

void resetVariables(Game* game, int dirIndex) {

	setBoolean(getGameVariables(game), BOOL_SPAWN, FALSE);
	setBoolean(getGameVariables(game), BOOL_COUNTRYGUARD, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL_SPAWN, FALSE);
	setBoolean(getGameVariables(game), BOOL_GIRL, FALSE);
	setBoolean(getGameVariables(game), BOOL_BOY, FALSE);
	setBoolean(getGameVariables(game), BOOL_INNERKEEPER, FALSE);
	setBoolean(getGameVariables(game), BOOL_VILLAGER, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL_FISH_MAN, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL_WOOD_MAN, FALSE);
	setBoolean(getGameVariables(game), BOOL_GUARDIANS, FALSE);
	setBoolean(getGameVariables(game), BOOL_GUARDIAN_WOMAN, FALSE);
	setBoolean(getGameVariables(game), BOOL_GUARDIAN_MAN, FALSE);
	setBoolean(getGameVariables(game), BOOL_GUARDIANS_MAP, FALSE);
	setVariable(getGameVariables(game), WIDTH, dirIndex);
	setBoolean(getGameVariables(game), BOOL_PANNEL_START, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL, FALSE);
	setBoolean(getGameVariables(game), BOOL_CHAT_BOX, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_ONE, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_TWO, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_THREE, FALSE);
	setBoolean(getGameVariables(game), BOOL_PANNEL_CAVE_FOUR, FALSE);
	setBoolean(getGameVariables(game), BOOL_CHAT_BOX_INNERKEEPER, FALSE);
	setBoolean(getGameVariables(game), BOOL_CHAT_BOX_WOODMAN, FALSE);
	setBoolean(getGameVariables(game), BOOL_CHAT_BOX_COUNTRYGUARD, FALSE);
	setBoolean(getGameVariables(game), BOOL_CHAT_BOX_KIDF, FALSE);
	setBoolean(getGameVariables(game), BOOL_CHAT_BOX_KIDM, FALSE);
	setBoolean(getGameVariables(game), BOOL_CHAT_BOX_FISHMAN, FALSE);
	setBoolean(getGameVariables(game), BOOL_CHAT_BOX_VILLAGER, FALSE);
	setBoolean(getGameVariables(game), BOOL_CHAT_BOX_GUARDIANS, FALSE);
	setBoolean(getGameVariables(game), BOOL_CHAT_BOX_GUARDIANF, FALSE);
	setBoolean(getGameVariables(game), BOOL_CHAT_BOX_GUARDIANM, FALSE);

}
