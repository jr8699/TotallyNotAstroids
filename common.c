/**
		JUSTIN REBOK - 2016 - TOTALLY-NOT-ASTROIDS	
		
	PURPOSE OF COMMON.C
		PROVIDE ALL ESSENTIAL FUNCTIONS THAT ARE NOT RELATED TO DRAWING A SCENE
			I.E. SCORE TRACKING, LIVES, COLLISION CALCULATIONS. 
*/
#include "common.h"

menustate menuState = MAINMENU; //start at the main menu when game is opened
astroidObj* astroidsInPlay; //all the astroids currently floating around
button mainmenuButtons[3]; //buttons of the mainmenu

playerObj player = { 						//the player, no initialize function needed
					PLAYER_START_ORIGIN_X,
					PLAYER_START_ORIGIN_Y,
					PLAYER_ROTATION,
					PLAYER_BOUNDS_WIDTH,
					PLAYER_BOUNDS_HEIGHT,
					PLAYER_LIVES
					};

keystate currentKeyPressed = NOKEY; //The most recent key pressed by the user

menustate getMenuState(){ return menuState; } 			//getters and setters for the menu state
void setMenuState(menustate s) { menuState = s; }

keystate getKeyState() { return currentKeyPressed; }	//getters and setters for the key state
void setKeyState(keystate k) { currentKeyPressed = k; }

playerObj* getPlayer() { return &player; }

astroidObj* getAstroids() { return astroidsInPlay; }

button* getMainMenuButtons(){ return mainmenuButtons; }

/**
 * Initialize the starting values of the game
 * 
 */
void initGame(){
	//player already initialized
	
	//initialize the main menu buttons
	mainmenuButtons[0].x = 200; //start button
	mainmenuButtons[0].y = 300;
	mainmenuButtons[0].ID = -3895468;
	mainmenuButtons[0].type = 0;
	snprintf(mainmenuButtons[0].text,25,"Start");
	mainmenuButtons[1].x = 200;
	mainmenuButtons[1].y = 225;
	mainmenuButtons[1].ID = -14913477;
	mainmenuButtons[1].type = 1;
	snprintf(mainmenuButtons[1].text,25,"Options");
	mainmenuButtons[2].x = 200;
	mainmenuButtons[2].y = 150;
	mainmenuButtons[2].ID = -7217096;
	mainmenuButtons[2].type = 2;
	snprintf(mainmenuButtons[2].text,25,"Exit");
}

/**
 * Move the player by x or y amount of space
 * 
 **/
void movePlayer(int xMod, int yMod, int rotate){
	playerObj* p = getPlayer();
	p->originX = p->originX + yMod;
	p->originY = p->originY + xMod;
	p->rotation = p->rotation + rotate;
}

/**
 * Spawn an astroid at an appropriate time
 * 
*/
void spawnAstroid(){
	
}
