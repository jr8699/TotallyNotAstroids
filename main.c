/**
		JUSTIN REBOK - 2016 - TOTALLY-NOT-ASTROIDS

	PURPOSE OF MAIN.C:
		INITALIZE OPENGL/GLUT VALUES AND ENTER THE GLUTMAINLOOP
		ALL ESSENTIAL GLUT FUNCTIONS (I.E. DISPLAY) ARE HERE.
		CONTROL FLOW BETWEEN MENUS AND THE GAME
*/
#include "main.h"


/**
	Initialize opengl values
*/
void initFunc(){

}

/**
	Where all needed animation occures
*/
void idleFunc(void){

}

/**
	Whenever the window is resized by the user
*/
void reshapeFunc(GLint w, GLint h){

}

/**
	Whenever the user pressed a key on the keyboard
	The game will be fully controlled with the keyboard

	CURRENT CONTROL LAYOUT:

		Escape - Pause the game and pull up the pause menu
		W - Move forward
		S - Move backwards
		A - Rotate left
		D - Rotate right

*/
void onKeyboardPressFunc(unsigned char key, GLint x, GLint y){
	switch(key){
		case ESC_KEY:
			if(getMenuState() != MAINMENU || getMenuState() != PAUSEMENU)
				setMenuState(PAUSEMENU);
			break;
			
		case 'w': //move forward
				setKeyState(FORWARD);
			break;
			
		case 's': //move backward
				setKeyState(BACKWARDS);
			break;
			
		case 'a': //move (rotate) left
				setKeyState(LEFT);
			break;
			
		case 'd': //move (rotate) right
				setKeyState(RIGHT);
			break;
	}
}

/**
	Where all the drawing will occur for the game
*/
void displayFunc(void){
	menustate state = getMenuState();
	switch(state){ //the current state of the program
		case GAME: //when we are playing the game
			drawGame(getPlayer());
		break;
		
		case PAUSEMENU: //when the pause menu is visible
			drawPauseMenu();
		break;
		
		case MAINMENU: //when the main menu is visible
			drawMainMenu();
		break;	
	}
}

/**
	Main Function
*/
int main (int argc, char* argv[]){
	glutInit(&argc, argv);
 	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
  	glutInitWindowSize(500, 500);
  	glutInitWindowPosition (0, 0);
  	glutCreateWindow (argv[0]);
  	glutIdleFunc(idleFunc);
  	initFunc();
	
  	glutDisplayFunc(displayFunc);
  	glutReshapeFunc(reshapeFunc); 
  	glutKeyboardFunc(onKeyboardPressFunc);
  	glutMainLoop();
  	return 0;
}
