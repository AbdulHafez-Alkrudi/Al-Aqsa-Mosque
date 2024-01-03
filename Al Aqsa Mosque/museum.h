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
class museum
{
		
public:
	/* museum();
	 ~museum();*/


	 void drawWall(Point bottom_left_back, double width, double height, double depth,int texture,int door) {
		glBindTexture(GL_TEXTURE_2D, texture);
		glPushMatrix();
		glRotated(90,0,0,10);
   primitives::DrawWall(Point(0,0,0),width,height,depth,texture);
    glPushMatrix();
     glTranslated(0,0,depth);
	   glRotated(90,10,0,0);
	    glPushMatrix();
   primitives::DrawWall(Point(0,0,0),width,height,100,texture);
        glTranslated(0,0,150);
		   primitives::DrawWall(Point(0,0,0),width,height,100,texture);
		   	    glPushMatrix();
				glRotated(-90,0,0,1);
					glRotated(-90,0,1,0);
				glTranslated(-90,-40,40);
		   glBindTexture(GL_TEXTURE_2D,door);
			glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex3d(40,40,-40);

			glTexCoord2f(1,0);
			glVertex3d(90,40,-40);

			glTexCoord2f(1,1);
			glVertex3d(90,90,-40);

			glTexCoord2f(0,1);
			glVertex3d(40,90,-40);
			glEnd();
		    glPopMatrix();
		    glPopMatrix();
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

};