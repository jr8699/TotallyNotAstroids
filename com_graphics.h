/**
		JUSTIN REBOK - 2016 - TOTALLY-NOT-ASTROIDS	
*/

#ifndef COM_GRAPHICS_ASTROIDS_H
#define COM_GRAPHICS_ASTROIDS_H

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "macros.h"
#include "common.h"

//color struct
typedef struct{
	GLfloat r; //red
	GLfloat g; //green
	GLfloat b; //blue
	GLfloat a; //alpha
}color;

//FUNCTIONS
void drawPauseMenu(); //Menu functions
void drawMainMenu();
void drawOptionsMenu();
void drawGame(playerObj*);

//mainmenu features
void drawLogo(GLfloat, GLfloat);
void drawButtonsMain(GLboolean);
void drawButton(button*, GLboolean);

void drawPlayer(playerObj*); //Object Functions

void setColor(color*); //encapsulate the glColor*() function
#endif
