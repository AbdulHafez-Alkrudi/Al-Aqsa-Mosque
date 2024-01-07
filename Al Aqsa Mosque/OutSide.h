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
#define unbind glBindTexture(GL_TEXTURE_2D, 0);
class OutSide
{
	public:
		OutSide(void){};
		~OutSide(void){};


	void drawGround(Point bottom_left_back, double width, double height, double depth, int texture)
	{
		glEnable(GL_TEXTURE_2D);
			glPushMatrix();
			glTranslated(0,0,depth);
			glBindTexture(GL_TEXTURE_2D, texture);
	  
			glBegin(GL_QUADS);

				glTexCoord2d(0,0);
			glVertex3f(bottom_left_back.x, bottom_left_back.y, bottom_left_back.z);

			glTexCoord2d(20,0);
			glVertex3f(bottom_left_back.x+ depth, bottom_left_back.y, bottom_left_back.z);

			glTexCoord2d(20,20);
			glVertex3f(bottom_left_back.x+ depth, bottom_left_back.y , bottom_left_back.z - width);

			glTexCoord2d(0,20);
			glVertex3f(bottom_left_back.x, bottom_left_back.y, bottom_left_back.z - width);
			glEnd();
			glPopMatrix();
			glDisable(GL_TEXTURE_2D);
	}

	void drawWall(Point bottom_left_back, double width, double height, double depth,int texture, int texture_door, bool *keys, int d, int s) 
	{
		Door* door;
		glEnable(GL_TEXTURE_2D);
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
			primitives::DrawWall(Point(0,0,0),width, height, 1200, texture);
			glTranslated(0, 0, 1200);
			
			glPushMatrix();
			glRotated(-90,10,0,0);
			glRotated(-90,0,0,10);
			door = new Door(50, 70, 5);
			door->DrawDoubledDoor(d, s);
			glPopMatrix();


			glTranslated(0, 0, 100+0.1);
			primitives::DrawWall(Point(0,0,0),width, height, 200, texture);
			glPopMatrix();
		
			glPushMatrix();
			glTranslated(0,0,depth);
			glRotated(90,10,0,0);
	   
			// Right
			glPushMatrix();
			primitives::DrawWall(Point(0,0,0),width, height, 50, texture);

			glTranslated(0, 0, 50);

			glPushMatrix();
			glRotated(-90,10,0,0);
			glRotated(-90,0,0,10);
			door = new Door(35-0.1, 70, 5);
			door->DrawDoubledDoor(d, s);
			glPopMatrix();

			glTranslated(0, 0, 70);
			primitives::DrawWall(Point(0,0,0),width, height, 410, texture);
			glTranslated(0, 0, 410);

			glPushMatrix();
			glRotated(-90,10,0,0);
			glRotated(-90,0,0,10);
			door = new Door(35, 70, 5);
			door->DrawDoubledDoor(d, s);
			glPopMatrix();

			glTranslated(0, 0, 70);
			primitives::DrawWall(Point(0,0,0),width, height, 630, texture);
			glTranslated(0, 0, 630);


			glPushMatrix();
			glRotated(-90,10,0,0);
			glRotated(-90,0,0,10);
			door = new Door(35, 70, 5);
			door->DrawDoubledDoor(d, s);
			glPopMatrix();

			glTranslated(0, 0, 70);
			primitives::DrawWall(Point(0,0,0),width, height, 200, texture);
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(0,0,depth);
			glRotated(90,10,0,0);
	  
			// Back
			primitives::DrawWall(Point(0,0,0),width, height, 760, texture);
			glPushMatrix();
			glTranslated(0, 0, 760);

			/*glPushMatrix();
			glRotated(-90,10,0,0);
			glRotated(-90,0,0,10);
			door = new Door(35, 70, 5);
			door->DrawDoubledDoor(d, s);
			glPopMatrix();*/

			glTranslated(0, 0, 70);
			primitives::DrawWall(Point(0,0,0),width, height, 250, texture);
			glTranslated(0, 0, 250);

			glPushMatrix();
			glRotated(-90,10,0,0);
			glRotated(-90,0,0,10);
			door = new Door(35, 70, 5);
			door->DrawDoubledDoor(d, s);
			glPopMatrix();


			glTranslated(0, 0, 70);
			primitives::DrawWall(Point(0,0,0),width, height, 350, texture);
			glPopMatrix();

			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
			glDisable(GL_TEXTURE_2D);
	}
};