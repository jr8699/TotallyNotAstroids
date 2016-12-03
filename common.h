/**
		JUSTIN REBOK - 2016 - TOTALLY-NOT-ASTROIDS	
*/

#ifndef COMMON_H
#define COMMON_H

#define PLAYER_LIVES 3
#define PLAYER_START_ORIGIN_X 50
#define PLAYER_START_ORIGIN_Y 50
#define PLAYER_BOUNDS_WIDTH 10 //arbitrary values for the bounds, will probably change
#define PLAYER_BOUNDS_HEIGHT 10

#include <stdio.h>
#include <GL/glut.h>
#include "macros.h"

menustate getMenuState();
void setMenuState(menustate);

keystate getKeyState();
void setKeyState(keystate);

playerObj getPlayer();

#endif
