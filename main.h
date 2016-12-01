/**
		JUSTIN REBOK - 2016 - TOTALLY-NOT-ASTROIDS	
*/

#ifndef MAIN_ASTROIDS_H
#define MAIN_ASTROIDS_H

#include <stdio.h>
#include <GL/glut.h>
#include "macros.h"
#include "common.h"
#include "com_graphics.h"

//FUNCTIONS
void idleFunc(void);
void initFunc(void);
void reshapeFunc(GLint,GLint);
void onKeyboardPressFunc(unsigned char, GLint, GLint);
void displayFunc(void);

#endif