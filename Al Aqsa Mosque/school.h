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
//#include "Pillars.h"

class school
{
	public:
		school(void){};
		~school(void){};


		void drawWall(Point bottom_left_back, double width, double height, double depth,int texture,int door) {
			glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, texture);
				glPushMatrix();
				glRotated(90,0,0,10);
		   primitives::DrawWall(Point(0,0,0),width,height,180,texture);
			glPushMatrix();
			 glTranslated(0,0,180);
			   glRotated(90,10,0,0);
				glPushMatrix();
		   primitives::DrawWall(Point(0,0,0),width,height,175,texture);
				glTranslated(0,0,225);
				   primitives::DrawWall(Point(0,0,0),width,height,175,texture);
		   				glPushMatrix();
						glRotated(-90,0,0,1);
							glRotated(-90,0,1,0);
						glTranslated(-175,-125,10);
						primitives::DrawQuad(Point(125,125,-10),Point(175,125,-10),Point(175,175,-10),Point(125,175,-10), door, 0, 0);
					glPopMatrix();
					glPopMatrix();
			glPushMatrix();
			 glTranslated(0,0,depth);
			   glRotated(90,10,0,0);
		   primitives::DrawWall(Point(0,0,0),width,height,180,texture);
			 glPushMatrix();
			 glTranslated(0,0,depth);
			   glRotated(90,10,0,0);
		   primitives::DrawWall(Point(0,0,0),width,height,depth,texture);
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
			glTranslated(0,0,180);
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

	void DrawHousewithoutDome(Point bottom_left_back,float length, float depth,
	float hight_haram, float hight_cube,
		int texture_door,int texture_wall,
		int texture_window)
	{
		glEnable(GL_TEXTURE_2D);

		Point a= bottom_left_back;
		Point b= Point (a.x+length,a.y,a.z);
		Point c= Point (a.x+length,a.y,a.z+depth);
		Point d= Point (a.x,a.y,a.z+depth);
		Point e= Point (a.x,a.y+hight_cube,a.z);
		Point f= Point (a.x+length,a.y+hight_cube,a.z);
		Point g= Point (a.x+length,a.y+hight_cube,a.z+depth);
		Point h= Point (a.x,a.y+hight_cube,a.z+depth);



		//draw wall
		glColor3f(1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture_wall);

		//ABCD
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(a.x,a.y,a.z);
		glTexCoord2d(1, 0);
		glVertex3f(b.x,b.y,b.z);
		glTexCoord2d(1, 1);
		glVertex3f(c.x,c.y,c.z);
		glTexCoord2d(0, 1);
		glVertex3f(d.x,d.y,d.z);
		glEnd();


		//EFGH
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(e.x,e.y,e.z);
		glTexCoord2d(1, 0);
		glVertex3f(f.x,f.y,f.z);
		glTexCoord2d(1, 1);
		glVertex3f(g.x,g.y,g.z);
		glTexCoord2d(0, 1);
		glVertex3f(h.x,h.y,h.z);
		glEnd();

		//ABFE
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(a.x,a.y,a.z);
		glTexCoord2d(1, 0);
		glVertex3f(b.x,b.y,b.z);
		glTexCoord2d(1, 1);
		glVertex3f(f.x,f.y,f.z);
		glTexCoord2d(0, 1);
		glVertex3f(e.x,e.y,e.z);
		glEnd();

		//ADHE
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(a.x,a.y,a.z);
		glTexCoord2d(1, 0);
		glVertex3f(d.x,d.y,d.z);
		glTexCoord2d(1, 1);
		glVertex3f(h.x,h.y,h.z);
		glTexCoord2d(0, 1);
		glVertex3f(e.x,e.y,e.z);
		glEnd();

		//CBFG
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(c.x,c.y,c.z);
		glTexCoord2d(1, 0);
		glVertex3f(b.x,b.y,b.z);
		glTexCoord2d(1, 1);
		glVertex3f(f.x,f.y,f.z);
		glTexCoord2d(0, 1);
		glVertex3f(g.x,g.y,g.z);
		glEnd();

		//DCGH
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(d.x,d.y,d.z);
		glTexCoord2d(1, 0);
		glVertex3f(c.x,c.y,c.z);
		glTexCoord2d(1, 1);
		glVertex3f(g.x,g.y,g.z);
		glTexCoord2d(0, 1);
		glVertex3f(h.x,h.y,h.z);
		glEnd();



		//draw door
		glBindTexture(GL_TEXTURE_2D, texture_door);
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(d.x,d.y,d.z);
		// if the door in the middle and the door length is the house length/4, and the hight is house 0.7*hight
		glTranslated(length/2-length/8,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube*0.7,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube*0.7,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();


		//Draw windows
		glBindTexture(GL_TEXTURE_2D, texture_window);
		//front
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(d.x,d.y,d.z);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/20,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glTranslated(13*length/20,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();

		//back
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(a.x,a.y,a.z);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/4-length/8,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glTranslated(length/2,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();


		//left
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(a.x,a.y,a.z);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glTranslated(depth/2,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();


		//right
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(b.x,b.y,b.z);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glTranslated(depth/2,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();


		glDisable(GL_TEXTURE_2D);

	};
		void DrawHousewithDome(Point bottom_left_back,float length, float depth,
	float hight_haram, float hight_cube,
		int texture_door,int texture_wall,
		int texture_window,int texture_roof)
	{
		glEnable(GL_TEXTURE_2D);
		Point a= bottom_left_back;
		Point b= Point (a.x+length,a.y,a.z);
		Point c= Point (a.x+length,a.y,a.z+depth);
		Point d= Point (a.x,a.y,a.z+depth);
		Point e= Point (a.x,a.y+hight_cube,a.z);
		Point f= Point (a.x+length,a.y+hight_cube,a.z);
		Point g= Point (a.x+length,a.y+hight_cube,a.z+depth);
		Point h= Point (a.x,a.y+hight_cube,a.z+depth);



		//draw wall
		glColor3f(1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture_wall);

		//ABCD
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(a.x,a.y,a.z);
		glTexCoord2d(1, 0);
		glVertex3f(b.x,b.y,b.z);
		glTexCoord2d(1, 1);
		glVertex3f(c.x,c.y,c.z);
		glTexCoord2d(0, 1);
		glVertex3f(d.x,d.y,d.z);
		glEnd();


		//EFGH
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(e.x,e.y,e.z);
		glTexCoord2d(1, 0);
		glVertex3f(f.x,f.y,f.z);
		glTexCoord2d(1, 1);
		glVertex3f(g.x,g.y,g.z);
		glTexCoord2d(0, 1);
		glVertex3f(h.x,h.y,h.z);
		glEnd();

		//ABFE
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(a.x,a.y,a.z);
		glTexCoord2d(1, 0);
		glVertex3f(b.x,b.y,b.z);
		glTexCoord2d(1, 1);
		glVertex3f(f.x,f.y,f.z);
		glTexCoord2d(0, 1);
		glVertex3f(e.x,e.y,e.z);
		glEnd();

		//ADHE
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(a.x,a.y,a.z);
		glTexCoord2d(1, 0);
		glVertex3f(d.x,d.y,d.z);
		glTexCoord2d(1, 1);
		glVertex3f(h.x,h.y,h.z);
		glTexCoord2d(0, 1);
		glVertex3f(e.x,e.y,e.z);
		glEnd();

		//CBFG
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(c.x,c.y,c.z);
		glTexCoord2d(1, 0);
		glVertex3f(b.x,b.y,b.z);
		glTexCoord2d(1, 1);
		glVertex3f(f.x,f.y,f.z);
		glTexCoord2d(0, 1);
		glVertex3f(g.x,g.y,g.z);
		glEnd();

		//DCGH
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(d.x,d.y,d.z);
		glTexCoord2d(1, 0);
		glVertex3f(c.x,c.y,c.z);
		glTexCoord2d(1, 1);
		glVertex3f(g.x,g.y,g.z);
		glTexCoord2d(0, 1);
		glVertex3f(h.x,h.y,h.z);
		glEnd();



		//draw door
		glBindTexture(GL_TEXTURE_2D, texture_door);
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(d.x,d.y,d.z);
		// if the door in the middle and the door length is the house length/4, and the hight is house 0.7*hight
		glTranslated(length/2-length/8,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube*0.7,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube*0.7,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();


		//Draw windows
		glBindTexture(GL_TEXTURE_2D, texture_window);
		//front
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(d.x,d.y,d.z);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/20,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glTranslated(13*length/20,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();

		//back
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(a.x,a.y,a.z);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/4-length/8,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glTranslated(length/2,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();


		//left
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(a.x,a.y,a.z);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glTranslated(depth/2,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();


		//right
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(b.x,b.y,b.z);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glTranslated(depth/2,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();


		// Draw roof
		glBindTexture(GL_TEXTURE_2D, texture_roof);
		primitives::DrawBall(50,texture_roof,Point(depth/2,length-30,depth/2));
		glDisable(GL_TEXTURE_2D);

	};
	void DrawHousewithoutDomeoneWindow(Point bottom_left_back,float length, float depth,
	float hight_haram, float hight_cube,
		int texture_door,int texture_wall,
		int texture_window)
	{
		glEnable(GL_TEXTURE_2D);
		Point a= bottom_left_back;
		Point b= Point (a.x+length,a.y,a.z);
		Point c= Point (a.x+length,a.y,a.z+depth);
		Point d= Point (a.x,a.y,a.z+depth);
		Point e= Point (a.x,a.y+hight_cube,a.z);
		Point f= Point (a.x+length,a.y+hight_cube,a.z);
		Point g= Point (a.x+length,a.y+hight_cube,a.z+depth);
		Point h= Point (a.x,a.y+hight_cube,a.z+depth);



		//draw wall
		glColor3f(1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture_wall);

		//ABCD
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(a.x,a.y,a.z);
		glTexCoord2d(1, 0);
		glVertex3f(b.x,b.y,b.z);
		glTexCoord2d(1, 1);
		glVertex3f(c.x,c.y,c.z);
		glTexCoord2d(0, 1);
		glVertex3f(d.x,d.y,d.z);
		glEnd();


		//EFGH
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(e.x,e.y,e.z);
		glTexCoord2d(1, 0);
		glVertex3f(f.x,f.y,f.z);
		glTexCoord2d(1, 1);
		glVertex3f(g.x,g.y,g.z);
		glTexCoord2d(0, 1);
		glVertex3f(h.x,h.y,h.z);
		glEnd();

		//ABFE
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(a.x,a.y,a.z);
		glTexCoord2d(1, 0);
		glVertex3f(b.x,b.y,b.z);
		glTexCoord2d(1, 1);
		glVertex3f(f.x,f.y,f.z);
		glTexCoord2d(0, 1);
		glVertex3f(e.x,e.y,e.z);
		glEnd();

		//ADHE
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(a.x,a.y,a.z);
		glTexCoord2d(1, 0);
		glVertex3f(d.x,d.y,d.z);
		glTexCoord2d(1, 1);
		glVertex3f(h.x,h.y,h.z);
		glTexCoord2d(0, 1);
		glVertex3f(e.x,e.y,e.z);
		glEnd();

		//CBFG
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(c.x,c.y,c.z);
		glTexCoord2d(1, 0);
		glVertex3f(b.x,b.y,b.z);
		glTexCoord2d(1, 1);
		glVertex3f(f.x,f.y,f.z);
		glTexCoord2d(0, 1);
		glVertex3f(g.x,g.y,g.z);
		glEnd();

		//DCGH
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(d.x,d.y,d.z);
		glTexCoord2d(1, 0);
		glVertex3f(c.x,c.y,c.z);
		glTexCoord2d(1, 1);
		glVertex3f(g.x,g.y,g.z);
		glTexCoord2d(0, 1);
		glVertex3f(h.x,h.y,h.z);
		glEnd();



		//draw door
		glBindTexture(GL_TEXTURE_2D, texture_door);
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(d.x,d.y,d.z);
		// if the door in the middle and the door length is the house length/4, and the hight is house 0.7*hight
		glTranslated(length/2-length/8,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube*0.7,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube*0.7,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();


		//Draw windows
		glBindTexture(GL_TEXTURE_2D, texture_window);

		//back
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(a.x,a.y,a.z);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/4-length/8,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/2,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/2,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glTranslated(length/2,0,0);
		glPopMatrix();


		//left
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(a.x,a.y,a.z);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/2,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/2,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glTranslated(depth/2,0,0);
		
		glPopMatrix();


		//right
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(b.x,b.y,b.z);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/2,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/2,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glPopMatrix();


		
		glDisable(GL_TEXTURE_2D);
	};
};
