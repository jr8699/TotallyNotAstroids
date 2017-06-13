/**
		JUSTIN REBOK - 2016 - TOTALLY-NOT-ASTROIDS	
*/

#ifndef MACROS_H
#define MACROS_H

//for controlling the flow of the game between menus
typedef enum {MAINMENU, PAUSEMENU, GAME, OPTIONS} menustate;
typedef enum {FORWARD, BACKWARDS, LEFT, RIGHT, RLEFT, RRIGHT, NOKEY} keystate;

typedef enum {JAGGED} astroidtype; //types of astroids

//the player struct, holds all info of the player
//currently bound by a box for collisions, will change
typedef struct{
	GLint originX; //center coordinates
	GLint originY;
	GLint rotation;
	GLint boundsWidth; //bounds for collisions
	GLint boundsHeight;
	GLint lives;	//current amount of lives of the player
}playerObj;

#define PLAYER_SPEED 5 //Rate of movement of the player

//an astroid in the game
typedef struct astroidObj astroidObj;
struct astroidObj{ //filled with the sub-astroids
	astroidObj* a; //future pieces of the astroid when parent is destroyed
	astroidObj* b;
	astroidObj* c;
	astroidObj* d;
	GLint lives; //current stage of the overall astroid
	GLint originX; //position
	GLint originY;
	astroidtype type;
};

//button struct
typedef struct{
	GLint type; //for identifying the button to switch colors
	GLfloat x; //location
	GLfloat y;
	GLchar text[25]; //button text
	GLint ID; //for picking	
}button;

//boolean values
#define TRUE 1
#define FALSE 0

//keys for controls
#define ESC_KEY 27

//window dimensions
#define WIN_SIZE_X 500
#define WIN_SIZE_Y 500

//Ticks per update
#define TICK_MODIFIER 4

#endif
