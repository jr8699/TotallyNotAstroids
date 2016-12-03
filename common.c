/**
		JUSTIN REBOK - 2016 - TOTALLY-NOT-ASTROIDS	
		
	PURPOSE OF COMMON.C
		PROVIDE ALL ESSENTIAL FUNCTIONS THAT ARE NOT RELATED TO DRAWING A SCENE
			I.E. SCORE TRACKING, LIVES, COLLISION CALCULATIONS. 
*/
#include "common.h"

menustate menuState = MAINMENU; //start at the main menu when game is opened

playerObj player = { 						//the player, no initialize function needed
					PLAYER_START_ORIGIN_X,
					PLAYER_START_ORIGIN_Y,
					PLAYER_BOUNDS_WIDTH,
					PLAYER_BOUNDS_HEIGHT,
					PLAYER_LIVES
					};

keystate currentKeyPressed = NOKEY; //The most recent key pressed by the user

menustate getMenuState(){ return menuState; } 			//getters and setters for the menu state
void setMenuState(menustate s) { menuState = s; }

keystate getKeyState() { return currentKeyPressed; }	//getters and setters for the key state
void setKeyState(keystate k) { currentKeyPressed = k; }

playerObj getPlayer() { return player; }
