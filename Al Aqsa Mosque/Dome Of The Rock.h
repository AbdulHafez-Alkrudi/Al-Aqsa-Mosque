#pragma once 
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>	
#include <cmath>
#include "texture.h"
#include "Point.h"
#include "Skybox.h"
#include "primitives.h"
#include "DrawWall.h"
#include "House.h"
#include "Door.h"
#include "around.h"

class DomeOfTheRock
{
	public:
		DomeOfTheRock(void){};
		~DomeOfTheRock(void){};

	

	void DrawBall(float rad, int texture = -1, Point center = Point(0, 0, 0))
	{
		glEnable(GL_TEXTURE_2D);
		glTranslated(center.x,center.y,center.z);
		float lastcenter=rad*sin(3.14/2);
		float lastr=rad*cos(3.14/2);
		for (float vertical=3.14/2.0; vertical>=0; vertical-=0.1)
		{

			float centeri=rad*sin(vertical);
			float ri=rad*cos(vertical);
			int col = 0;
			for (float horizin=0; horizin<=(2*3.14+0.1); horizin+=0.1)
			{
				Point a= Point (  ri*cos(horizin) , centeri , ri*sin(horizin));
				Point b= Point (  ri*cos(horizin+0.1) , centeri , ri*sin(horizin+0.1));
				Point c= Point (  lastr*cos(horizin) , lastcenter , lastr*sin(horizin));
				Point d= Point (  lastr*cos(horizin+0.1) , lastcenter , lastr*sin(horizin+0.1));
				if (texture!=-1)
				{
					glBindTexture(GL_TEXTURE_2D, texture);
					glBegin(GL_QUADS);
					glTexCoord2d(1-((horizin)/(2*3.14))/20, 0.5+(sin(vertical-0.1)/2.0)/20);
					glVertex3f(a.x,a.y,a.z);
					glTexCoord2d(1-((horizin+0.1)/(2*3.14))/20,( 0.5+sin(vertical-0.1)/2.0)/20);
					glVertex3f(b.x,b.y,b.z);
					glTexCoord2d(1-((horizin+0.1)/(2*3.14))/20, (0.5+sin(vertical)/2.0)/20);
					glVertex3f(d.x,d.y,d.z);
					glTexCoord2d((1-(horizin)/(2*3.14))/20, (0.5+sin(vertical)/2.0)/20);
					glVertex3f(c.x,c.y,c.z);
					glEnd();

				
				}
				else
				{
					glColor3ub(255,0,0);
					glBegin(GL_QUADS);
					glVertex3f(a.x,a.y,a.z);
					glVertex3f(b.x,b.y,b.z);
					glVertex3f(d.x,d.y,d.z);
					glVertex3f(c.x,c.y,c.z);
					glEnd();
				}
			}
			lastr=ri;
			lastcenter=centeri;
		}
		glTranslated(-center.x,-center.y,-center.z);
		glDisable(GL_TEXTURE_2D);
	};

	void DrawStrais(int texture)
	{
		glEnable(GL_TEXTURE_2D);
		for (int i = 0; i <= 12; i++) 
		{
			primitives::DrawCupe(Point(0, 0, 0), 60, 3, 25 - i, texture);
			glTranslated(0, 3, 8);
		}
		glDisable(GL_TEXTURE_2D);
	}
	
	void DrawOctagon(float w, float h, int p, int door_texture = 0 , Point base = Point(0, 0, 0) )
	{         
		  glEnable(GL_TEXTURE_2D);
		  glPushMatrix();
		  for (int i = 0; i < 8; i++)
		  {
			  if (i % 2 == 0)
			  {
				  glPushMatrix();
				  glBindTexture(GL_TEXTURE_2D, p);
			  
				  glBegin(GL_QUADS);
					  glTexCoord2d(0, 0);
					  glVertex3d(base.x, base.y, base.z);
				  
					  glTexCoord2d(1, 0);
					  glVertex3d(base.x + w/3, base.y, base.z);
				  
					  glTexCoord2d(1, 1);
					  glVertex3d(base.x + w/3, base.y + h, base.z);
				  
					  glTexCoord2d(0, 1);
					  glVertex3d(base.x, base.y + h, base.z);
				  glEnd();
				  unbind;
				  glTranslated(w/3+0.1 , 0 , 0) ;
				  Door *door = new Door(w/3 , h , 1);
				  door->DrawSingleDoor(false , door_texture);
				  glEnable(GL_TEXTURE_2D);
				  unbind;

				  glTranslated(w/3, 0, 0);

				  //primitives::DrawCoordinates(true);
				  glBindTexture(GL_TEXTURE_2D, p);
			  
				  glBegin(GL_QUADS);
					  glTexCoord2d(0, 0);
					  glVertex3d(base.x, base.y, base.z);
				  
					  glTexCoord2d(1, 0);
					  glVertex3d(base.x + w/3, base.y, base.z);
				  
					  glTexCoord2d(1, 1);
					  glVertex3d(base.x + w/3, base.y + h, base.z);
				  
					  glTexCoord2d(0, 1);
					  glVertex3d(base.x, base.y + h, base.z);
				  glEnd();
				  glPopMatrix();
				  glTranslated(w, 0, 0);
				  glRotated(45, 0, 1, 0);
				  unbind ;
			  }
			  else 
			  {
				  glBindTexture(GL_TEXTURE_2D, p);
			  
				  glBegin(GL_QUADS);
					  glTexCoord2d(0, 0);
					  glVertex3d(base.x, base.y, base.z);
				  
					  glTexCoord2d(1, 0);
					  glVertex3d(base.x + w, base.y, base.z);
				  
					  glTexCoord2d(1, 1);
					  glVertex3d(base.x + w, base.y + h, base.z);
				  
					  glTexCoord2d(0, 1);
					  glVertex3d(base.x, base.y + h, base.z);
				  glEnd();
				  glTranslated(w, 0, 0);
				  glRotated(45, 0, 1, 0);
				 unbind ;
			  }
		  }
		  glPopMatrix();
	}

	void drawOctagon(float w, float h, int p, Point base = Point(0, 0, 0))
	{         
		  glEnable(GL_TEXTURE_2D);
		  glPushMatrix();
		  for (int i = 0; i < 8; i++)
		  {
			  glTranslated(w, 0, 0);
				  glRotated(45, 0, 1, 0);
				  glBindTexture(GL_TEXTURE_2D, p);
			  
				  glBegin(GL_QUADS);
					  glTexCoord2d(0, 0);
					  glVertex3d(base.x, base.y, base.z);
				  
					  glTexCoord2d(1, 0);
					  glVertex3d(base.x + w, base.y, base.z);
				  
					  glTexCoord2d(1, 1);
					  glVertex3d(base.x + w, base.y + h, base.z);
				  
					  glTexCoord2d(0, 1);
					  glVertex3d(base.x, base.y + h, base.z);
				  glEnd();
		  }
		  glPopMatrix();
	}
	
	void Floor_Roof(int pic) 
	 {                                
		 glEnable(GL_TEXTURE_2D);
		 //ÑÓã ÇáÇÑÖíÉ æ ÇáÓÞÝíÉ
		 const float pi = 3.14159265358979323846;
		 glBindTexture(GL_TEXTURE_2D, pic);
		 glBegin(GL_POLYGON);
			for (int i = 0; i < 8; ++i)
			{
				double angle = 2.0 * pi * i / 8.0;

				double x = 0.58 * cos(angle) * 157;
				double y = 0.58 * sin(angle) * 157;

				double u = 0.5 * cos(angle) + 0.5;
				double v = 0.5 * sin(angle) + 0.5;

				glTexCoord2d(u, v);
				glVertex2d(x, y);
			}

		 glEnd();
		glDisable(GL_TEXTURE_2D);
	 };

	void drawWall(Point bottom_left_back, double width, double height, double depth,int texture)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glPushMatrix();
		glRotated(90,0,0,10);

		primitives::DrawWall(Point(0,0,0),width,height,depth,texture);

		glPushMatrix();
		glTranslated(0,0,depth);
		glRotated(90,10,0,0);
		
		primitives::DrawWall(Point(0,0,0),width,height,depth - 100,texture);

		glPushMatrix();
		glTranslated(0,0,depth - 100);
	    glRotated(90,10,0,0);

		primitives::DrawWall(Point(0,0,0),width,height,depth,texture);
		
		glPushMatrix();
		glTranslated(0,0,depth);
	    glRotated(90,10,0,0);
   
		primitives::DrawWall(Point(0,0,0),width,height,depth - 100,texture);
	   
		glPopMatrix();
	    glPopMatrix();
	    glPopMatrix();
	    glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}

	void drawGround(Point bottom_left_back, double width, double height, double depth, int texture)
	{
		glEnable(GL_TEXTURE_2D);
			glPushMatrix();
			glTranslated(0,0,depth);
			glBindTexture(GL_TEXTURE_2D, texture);
	  
			glBegin(GL_QUADS);

				glTexCoord2d(0,0);
			glVertex3f(bottom_left_back.x, bottom_left_back.y, bottom_left_back.z);

			glTexCoord2d(10,0);
			glVertex3f(bottom_left_back.x+ depth, bottom_left_back.y, bottom_left_back.z);

			glTexCoord2d(10,10);
			glVertex3f(bottom_left_back.x+ depth, bottom_left_back.y , bottom_left_back.z - width);

			glTexCoord2d(0,10);
			glVertex3f(bottom_left_back.x, bottom_left_back.y, bottom_left_back.z - width);
			glEnd();
			glPopMatrix();
			glDisable(GL_TEXTURE_2D);
	}
};