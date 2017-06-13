/**
		JUSTIN REBOK - 2016 - TOTALLY-NOT-ASTROIDS

	PURPOSE OF COM_GRAPHICS.C:
		PROVIDE ALL ESSENTIAL FUNCTIONS FOR DRAWING ON THE SCREEN
*/

#include "com_graphics.h"

color green = {0.0,1.0,0.0,1.0}; //green color
color black = {0.0,0.0,0.0,1.0}; //black color
color white = {1.0,1.0,1.0,1.0}; //white color
color pickStart = {0.33,0.56,0.77,1.0}; //picking colors
color pickOptions = {0.23,0.44,0.11,1.0};
color pickExit = {0.22,0.88,0.57,1.0};

/**
 * Set the color
 **/
void setColor(color* c){glColor4f(c->r,c->g,c->b,c->a);}

/**
 * Draw the pause menu on the screen
 * Will draw to both the back and front buffer
 * Impliments color picking to click buttons
 **/
void drawPauseMenu(){
	
	
}

/**
 * Draw the options menu on the screen 
 * 
 * 
 **/
void drawOptionsMenu(){
	
}

/**
 * Draw the main menu on the screen
 * Will draw to both the back and front buffer
 * Impliments color picking to click buttons
 **/
void drawMainMenu(){
	glDrawBuffer(GL_BACK);
	drawButtonsMain(TRUE); //switch colors for picking
	
	glDrawBuffer(GL_FRONT);
	drawLogo(WIN_SIZE_X/2-35,WIN_SIZE_Y - 25); //place the logo in the upper center
	
	//still drawing to back
	drawButtonsMain(FALSE); //dont change colors
	
}

/**
 * Draw a button for a menu
 **/
void drawButton(button* b, GLboolean switchColors){
	if(!switchColors){
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		setColor(&white);
		glPushMatrix();
		glBegin(GL_LINE_STRIP);
			glVertex2f(b->x,b->y);
			glVertex2f(b->x + 100,b->y);
			glVertex2f(b->x + 100,b->y + 50);
			glVertex2f(b->x,b->y + 50);
			glVertex2f(b->x,b->y);
		glEnd();
		glRasterPos2f(b->x+25, b->y+20);
		glutBitmapString(GLUT_BITMAP_9_BY_15, b->text);
		glPopMatrix();
	}else{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		if(b->type == 0) setColor(&pickStart);
		else if(b->type == 1) setColor(&pickOptions);
		else if(b->type == 2) setColor(&pickExit);
		//printf("%d\n",b->type);
		glPushMatrix();
		glBegin(GL_QUADS);
			glVertex2f(b->x,b->y);
			glVertex2f(b->x + 100,b->y);
			glVertex2f(b->x + 100,b->y + 50);
			glVertex2f(b->x,b->y + 50);
			glVertex2f(b->x,b->y);
		glEnd();
		glPopMatrix();
	}
}

/**
 * Draw the buttons for the main menu
 * The boolean is for determining if the colors should be changed
 * 
 * 
**/
void drawButtonsMain(GLboolean switchColors){
	button* buttons;
	buttons = getMainMenuButtons();
	drawButton(&buttons[0], switchColors);
	drawButton(&buttons[1], switchColors);
	drawButton(&buttons[2], switchColors);
}

/**
 * Draw the "Astroids" logo at the top center
 **/
void drawLogo(GLfloat x, GLfloat y){
	glPushMatrix();
	setColor(&white);
	glRasterPos2f(x, y);
	glutBitmapString(GLUT_BITMAP_9_BY_15, "Astroids");
	glPopMatrix();
	setColor(&black);
}

/**
 * Draw the game scene on the screen
 * will alternate between the back and front buffer to increase flow
 * Handles the drawing of the whole scene when menus are not active
 **/
void drawGame(playerObj* p){
	glClear(GL_FRONT_AND_BACK);
	drawPlayer(p);
	
}

/**
 * Draws the player on the screen
 * 
 * 
 **/
void drawPlayer(playerObj* p){
	setColor(&white);
	glPushMatrix();
	glTranslatef(p->originX,p->originY,0);
	glScalef(8.0,8.0,0.0);
	glRotatef(p->rotation,0,0,1);
	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glBegin(GL_TRIANGLES); //change for scale
	glVertex2f(-2.5,-2.0);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,2.5);
	glEnd();
	glBegin(GL_TRIANGLES); //change for scale
	glVertex2f(0.0,0.0);
	glVertex2f(2.5,-2.0);
	glVertex2f(0.0,2.5);
	glEnd();
	glPopMatrix();
	
	
	glPopMatrix();
	
}
