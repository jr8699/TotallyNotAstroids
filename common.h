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
#define PLAYER_ROTATION 0

#include <stdio.h>
#include <GL/glut.h>
#include "macros.h"

menustate getMenuState();
void setMenuState(menustate);
button* getMainMenuButtons();

keystate getKeyState();
void setKeyState(keystate);

playerObj* getPlayer();
void movePlayer(int,int,int);

void initGame();
void spawnAstroid();
astroidObj* getAstroids();

#endif
