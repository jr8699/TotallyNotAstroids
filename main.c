/**
		JUSTIN REBOK - 2016 - TOTALLY-NOT-ASTROIDS

	PURPOSE OF MAIN.C:
		INITALIZE OPENGL/GLUT VALUES AND ENTER THE GLUTMAINLOOP
		ALL ESSENTIAL GLUT FUNCTIONS (I.E. DISPLAY) ARE HERE.
		CONTROL FLOW BETWEEN MENUS AND THE GAME
*/
#include "main.h"

int ticks = 0; //ticks for the game

/**
	Initialize opengl values
*/
void initFunc(){
	initGame();
	glMatrixMode(GL_PROJECTION);
	glShadeModel(GL_FLAT); //flat shading
	glClearColor(0.0,0.0,0.0,1.0); //black background
	gluOrtho2D(0.0, WIN_SIZE_X, 0.0, WIN_SIZE_Y); //ortho projection
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/**
	Where all needed animation occures
*/
void idleFunc(void){
	if(getMenuState() != PAUSEMENU){
		if(ticks%TICK_MODIFIER == 0){ //move game every 5 ticks
			switch(getKeyState()){
				case FORWARD:
					movePlayer(PLAYER_SPEED,0,0);
					setKeyState(NOKEY);
					break;
				case BACKWARDS:
					movePlayer(-PLAYER_SPEED,0,0);
					break;
				case LEFT:
					movePlayer(0,-PLAYER_SPEED,0);
					break;
				case RIGHT:
					movePlayer(0,PLAYER_SPEED,0);
					break;
				case RRIGHT:
					printf("Rotate, %d\n",getPlayer()->rotation);
					movePlayer(0,0,-PLAYER_SPEED);
					break;
				case RLEFT:
					movePlayer(0,0,PLAYER_SPEED);
					break;
			}
			setKeyState(NOKEY); //invalidate the last action
			ticks = 0; // reset to prevent overflow
		}
		ticks++;
		
		if(ticks > 10000) //reset to prevent overflow
			ticks = 0;
		glutPostRedisplay();
	}
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
		A - Move right
		D - Move left
		E - Rotate right
		Q - Rotate left

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
			
		case 'a': //move left
				setKeyState(LEFT);
			break;
			
		case 'd': //move right
				setKeyState(RIGHT);
			break;
		
		case 'e': //rotate right
				setKeyState(RRIGHT);
			break;
			
		case 'q': //rotate left
				setKeyState(RLEFT);
			break;
	}
}

/**
	Where all the drawing will occur for the game
*/
void displayFunc(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	menustate state = getMenuState();
	switch(state){ //the current state of the program
		case GAME: //when we are playing the game
			glutMouseFunc(NULL); //turn off mouse input
			drawGame(getPlayer());
			glFlush();
			//glutSwapBuffers();
		break;
		
		case PAUSEMENU: //when the pause menu is visible
			glutMouseFunc(mouseFunc); //turn on mouse input
			drawPauseMenu();
			glFlush(); //for picking
		break;
		
		case MAINMENU: //when the main menu is visible
			glutMouseFunc(mouseFunc); //turn on mouse input
			drawMainMenu();
			glFlush(); //for picking
			//glutSwapBuffers();
		break;
		
		case OPTIONS: //when the options menu is visible
			glutMouseFunc(mouseFunc); //turn on mouse input if not already on
			drawOptionsMenu();
			glFlush();
		break;
	}
}

/**
 * Handles mouse input for the menus
 * 
*/
void mouseFunc(GLint key, GLint state, GLint x, GLint y){
	if(key == GLUT_LEFT_BUTTON && state == GLUT_DOWN){ //attempt to click a menu button
		if(getMenuState() == MAINMENU){ //main menu
			GLint viewport[4];
			GLuint data[3];
			
			glGetIntegerv(GL_VIEWPORT, viewport);
			glReadBuffer(GL_BACK);
			glReadPixels(x, viewport[3]-y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, data);
			//printf("DEBUG: -> read color %d\n", data[0]);
			button* buttons = getMainMenuButtons();
			if(data[0] == buttons[0].ID){ //start the game
				printf("Start the Game!\n");
				setMenuState(GAME);
			}else if (data[0] == buttons[1].ID){ //open options menu
				printf("Options\n");
				setMenuState(OPTIONS);
			}else if (data[0] == buttons[2].ID){ //exit the game
				printf("Exit\n");
				exit(0);
			}
		}else if(getMenuState() == PAUSEMENU){ //pause menu
			
		}else if(getMenuState() == OPTIONS){ //options menu
			
		}
	}
}

/**
	Main Function
*/
int main (int argc, char* argv[]){
	glutInit(&argc, argv);
 	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
  	glutInitWindowSize(WIN_SIZE_X, WIN_SIZE_Y);
  	glutInitWindowPosition (0, 0);
  	glutCreateWindow (argv[0]);
  	glutIdleFunc(idleFunc);
  	initFunc();
	
  	glutDisplayFunc(displayFunc);
  	glutReshapeFunc(reshapeFunc); 
  	glutMouseFunc(mouseFunc);
  	glutKeyboardFunc(onKeyboardPressFunc);
  	glutMainLoop();
  	return 0;
}
