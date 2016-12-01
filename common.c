/**
		JUSTIN REBOK - 2016 - TOTALLY-NOT-ASTROIDS	
*/
#include "common.h"

menustate menuState = MAINMENU; //start at the main menu when game is opened

menustate getMenuState(){ return menuState; }
void setMenuState(menuState s) { menuState = s; }