/**
		JUSTIN REBOK - 2016 - TOTALLY-NOT-ASTROIDS	
*/

#ifndef MACROS_H
#define MACROS_H

//for controlling the flow of the game between menus
typedef enum {MAINMENU, PAUSEMENU, GAME} menustate;
typedef enum {FORWARD, BACKWARDS, LEFT, RIGHT, NOKEY} keystate;

//the player struct, holds all info of the player
//currently bound by a box for collisions, will change
typedef struct{
	GLint originX; //center coordinates
	GLint originY;
	GLint boundsWidth; //bounds for collisions
	GLint boundsHeight;
	GLint lives;	//current amount of lives of the player
}playerObj;

//boolean values
#define TRUE 1
#define FALSE 0

//keys for controls
#define ESC_KEY 27


#endif
