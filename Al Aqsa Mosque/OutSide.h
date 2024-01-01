#pragma once 
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>	
#include <fstream>
#include <cmath>


#include "Point.h"
#include "primitives.h"
#include "DrawWall.h"
#include "Door.h"
#include "texture.h"
#include "Camera.h"
#include "Pillar.h"

class OutSide
{
	public:
		OutSide(void){};
		~OutSide(void){};


	void drawGround(Point bottom_left_back, double width, double height, double depth, int texture)
	{
			glPushMatrix();
			glTranslated(0,0,depth);
			glBindTexture(GL_TEXTURE_2D, texture);
	  
			glBegin(GL_QUADS);

				glTexCoord2d(0,0);
			glVertex3f(bottom_left_back.x, bottom_left_back.y, bottom_left_back.z);

			glTexCoord2d(5,0);
			glVertex3f(bottom_left_back.x+ depth, bottom_left_back.y, bottom_left_back.z);

			glTexCoord2d(5,5);
			glVertex3f(bottom_left_back.x+ depth, bottom_left_back.y , bottom_left_back.z - width);

			glTexCoord2d(0,5);
			glVertex3f(bottom_left_back.x, bottom_left_back.y, bottom_left_back.z - width);
			glEnd();
			glPopMatrix();
	}

	void drawWall(Point bottom_left_back, double width, double height, double depth,int texture, int texture_door, bool *keys) 
	{
			glBindTexture(GL_TEXTURE_2D, texture);
			glPushMatrix();
			glRotated(90,0,0,10);
			// Left
			glPushMatrix();
			primitives::DrawWall(Point(0,0,0),width,height,depth,texture);
			glPopMatrix();

			glPushMatrix();
			glTranslated(0,0,depth);
			glRotated(90,10,0,0);
	   
			// Front 
			glPushMatrix();
			primitives::DrawWall(Point(0,0,0),width, height, 500, texture);
			glTranslated(0, 0, 500);
			glTranslated(0, 0, 50);
			primitives::DrawWall(Point(0,0,0),width, height, 250, texture);
			glPopMatrix();
		
			glPushMatrix();
			glTranslated(0,0,depth);
			glRotated(90,10,0,0);
	   
			// Right
			glPushMatrix();
			primitives::DrawWall(Point(0,0,0),width, height, 100, texture);
			glTranslated(0, 0, 100);

			glTranslated(0, 0, 50);
			primitives::DrawWall(Point(0,0,0),width, height, 200, texture);
			glTranslated(0, 0, 250);
			primitives::DrawWall(Point(0,0,0),width, height, 250, texture);
			glTranslated(0, 0, 300);
			primitives::DrawWall(Point(0,0,0),width, height, 100, texture);
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(0,0,depth);
			glRotated(90,10,0,0);
	  
			// Back
			primitives::DrawWall(Point(0,0,0),width, height, 400, texture);
			glPushMatrix();
			glTranslated(0, 0, 450);
			primitives::DrawWall(Point(0,0,0),width, height, 150, texture);
			glTranslated(0, 0, 200);
			primitives::DrawWall(Point(0,0,0),width, height, 150, texture);
			glPopMatrix();

			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
	}
};