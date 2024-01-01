#pragma once
#include "Point.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#include "primitives.h"
 
class DrawWall{
	int ground,wall,grass ;

public:
	DrawWall(void){};
	~DrawWall(void){};
	
	
void drawGrass(double x, double y, double z, double width,double depth,int texture)
{
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(x, y, z);

			glTexCoord2d(width, 0);
			glVertex3d(x + width, y, z);

			glTexCoord2d(width, width);
			glVertex3d(x + width, y, z-depth);

			glTexCoord2d(0, width);
			glVertex3d(x, y, z-depth);

		glEnd();
}
	void drawWall(Point bottom_left_back, double width, double height, double depth,int texture) {
		glBindTexture(GL_TEXTURE_2D, texture);
		glPushMatrix();
		glRotated(90,0,0,10);
	  primitives::DrawWall(Point(0,0,0),width,height,depth,texture);
    glPushMatrix();
     glTranslated(0,0,depth);
	   glRotated(90,10,0,0);
   primitives::DrawWall(Point(0,0,0),width,height,depth,texture);
    glPushMatrix();
     glTranslated(0,0,depth);
	   glRotated(90,10,0,0);
   primitives::DrawWall(Point(0,0,0),width,height,depth,texture);
     glPushMatrix();
     glTranslated(0,0,depth);
	   glRotated(90,10,0,0);
   primitives::DrawWall(Point(0,0,0),width,height,depth,texture);
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();
  
}
	void drawGround(Point bottom_left_back, double width, double height, double depth, int texture)
	{
			glPushMatrix();
			glTranslated(0,0,depth);
			glBindTexture(GL_TEXTURE_2D, texture);
	  
			glBegin(GL_QUADS);

				glTexCoord2d(0,0);
				glVertex3f(bottom_left_back.x, bottom_left_back.y, bottom_left_back.z);

				glTexCoord2d(width,0);
				glVertex3f(bottom_left_back.x+height+ depth, bottom_left_back.y, bottom_left_back.z);

				glTexCoord2d(width,width);
				glVertex3f(bottom_left_back.x+height + depth, bottom_left_back.y , bottom_left_back.z - depth-height);

				glTexCoord2d(0,width);
				glVertex3f(bottom_left_back.x, bottom_left_back.y, bottom_left_back.z - depth-height);
		 
			glEnd();
			glPopMatrix();
	}
	
};
