#pragma once
#include <cmath>
#include "texture.h"
#include "Point.h"

#define unbind glBindTexture(GL_TEXTURE_2D, 0);
class House 
{

public:
	Point bottom_left_back;
	float length, depth, hight_haram, hight_cube;
	int texture_door, texture_wall, texture_window, texture_roof,house_wall,house_window,wall;
	House(void){};
	~House(void){};

	//roof+door
	House(Point bottom_left_back,float length, float depth,
	float hight_haram, float hight_cube,
		int texture_door,int texture_wall,
		int texture_window,int texture_roof)
	{
		this->bottom_left_back=bottom_left_back;
		this->length=length;
		this->depth=depth;
		this->hight_haram=hight_haram;
		this->hight_cube=hight_cube;
		this->texture_door=texture_door;
		this->texture_wall=texture_wall;
		this->texture_window=texture_window;
		this->texture_roof=texture_roof;
	};
	//no roof
	House(Point bottom_left_back,float length, float depth,
	float hight_haram, float hight_cube,
		int texture_door,int texture_wall,
		int texture_window)
	{
		this->bottom_left_back=bottom_left_back;
		this->length=length;
		this->depth=depth;
		this->hight_haram=hight_haram;
		this->hight_cube=hight_cube;
		this->texture_door=texture_door;
		this->texture_wall=texture_wall;
		this->texture_window=texture_window;
	};

	
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


		float safe_space = 1.0f  ;
		//draw wall
		glColor3f(1,1,1);
		//cull;
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
	//	frontf ;
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
	//	backf;
		glEnd();



		//draw door
		glBindTexture(GL_TEXTURE_2D, texture_door);
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(d.x+ safe_space,d.y+ safe_space,d.z+ safe_space);
		// if the door in the middle and the door length is the house length/4, and the hight is house 0.7*hight
		glTranslated(length/2-length/8+ safe_space,0+ safe_space,0+ safe_space);
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
		glTranslated(d.x+ safe_space,d.y+ safe_space,d.z+ safe_space);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/20+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
		glTranslated(13*length/20+ safe_space,0+ safe_space,0+ safe_space);
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

		safe_space *= -1 ;
		//back
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(a.x+ safe_space,a.y+ safe_space,a.z+ safe_space);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/4-length/8+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
		glTranslated(length/2+ safe_space,0+ safe_space,0+ safe_space);
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

		safe_space *= -1 ;
		//left
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(a.x+ safe_space,a.y+ safe_space,a.z+ safe_space);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
		glTranslated(depth/2+ safe_space,0+ safe_space,0+ safe_space);
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
		glTranslated(b.x+ safe_space,b.y+ safe_space,b.z+ safe_space);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
		glTranslated(depth/2+ safe_space,0+ safe_space,0+ safe_space);
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
		//nocull;

		
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

		float safe_space = 1 ; 

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
		glTranslated(d.x + safe_space,d.y + safe_space,d.z+ safe_space);
		// if the door in the middle and the door length is the house length/4, and the hight is house 0.7*hight
		glTranslated(length/2-length/8+ safe_space,0+ safe_space,0+ safe_space);
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
		glTranslated(a.x+ safe_space,a.y+ safe_space,a.z+ safe_space);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/4-length/8+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
		glTranslated(a.x+ safe_space,a.y+ safe_space,a.z+ safe_space);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
		glTranslated(b.x+ safe_space,b.y+ safe_space,b.z+ safe_space);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
	void DrawHousewithDomeNOdoor(Point bottom_left_back,float length, float depth,
	float hight_haram, float hight_cube,
	int texture_wall,
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

		float safe_space = -1.0f ;
		
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




		//Draw windows
		glBindTexture(GL_TEXTURE_2D, texture_window);
		//front
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(d.x+ safe_space,d.y+ safe_space,d.z+ safe_space);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/20+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
		glTranslated(13*length/20+ safe_space,0+ safe_space,0+ safe_space);
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
		glTranslated(a.x+ safe_space,a.y+ safe_space,a.z+ safe_space);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/4-length/8+ safe_space,hight_cube/4+ safe_space,0 + safe_space);
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
		glTranslated(length/2+ safe_space,0+ safe_space,0+ safe_space);
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
		glTranslated(a.x+ safe_space,a.y+ safe_space,a.z+ safe_space);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8+ safe_space,hight_cube/4+ safe_space,0 + safe_space );
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
		glTranslated(depth/2+ safe_space,0 + safe_space,0 + safe_space );
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
		glTranslated(b.x + safe_space ,b.y + safe_space ,b.z + safe_space );
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8 + safe_space ,hight_cube/4 + safe_space ,0 + safe_space );
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
		glTranslated(depth/2 + safe_space ,0 + safe_space ,0 + safe_space );
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
		primitives::DrawBall(16,texture_roof,Point(depth/2,depth,depth/2));
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

		float safe_space = 1.0f ;

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
		glTranslated(d.x+ safe_space,d.y+ safe_space,d.z+ safe_space);
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
		glTranslated(d.x+ safe_space,d.y+ safe_space,d.z+ safe_space);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/20+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
		glTranslated(13*length/20+ safe_space,0+ safe_space,0+ safe_space);
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
		glTranslated(a.x+ safe_space,a.y+ safe_space,a.z+ safe_space);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/4-length/8+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
		glTranslated(length/2+ safe_space,0+ safe_space,0+ safe_space);
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
		glTranslated(depth/4-depth/8+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
		glTranslated(depth/2+ safe_space,0+ safe_space,0+ safe_space);
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
		glTranslated(b.x+ safe_space,b.y+ safe_space,b.z+ safe_space);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
		glTranslated(depth/2+ safe_space,0+ safe_space,0+ safe_space);
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
		primitives::DrawBall(16,texture_roof,Point(depth/2,depth-3,depth/2));
		
		glDisable(GL_TEXTURE_2D);
	};
	void DrawHousewithDomeonewindow(Point bottom_left_back,float length, float depth,
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
		float safe_space = 1.0f ;
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
		glTranslated(d.x+ safe_space,d.y+ safe_space,d.z+ safe_space);
		// if the door in the middle and the door length is the house length/4, and the hight is house 0.7*hight
		glTranslated(length/2-length/8+ safe_space,0+ safe_space,0+ safe_space);
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
		glTranslated(a.x+ safe_space,a.y+ safe_space,a.z+ safe_space);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/4-length/8+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
		glTranslated(length/2+ safe_space,0+ safe_space,0+ safe_space);
		
		glPopMatrix();


		//left
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(a.x+ safe_space,a.y+ safe_space,a.z+ safe_space);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
		glTranslated(depth/2+ safe_space,0+ safe_space,0+ safe_space);
		
		glPopMatrix();


		//right
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(b.x+ safe_space,b.y+ safe_space,b.z+ safe_space);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8+ safe_space,hight_cube/4+ safe_space,0+ safe_space);
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
		glTranslated(depth/2+ safe_space,0+ safe_space,0+ safe_space);
		
		glPopMatrix();

		// Draw roof
		glBindTexture(GL_TEXTURE_2D, texture_roof);
		primitives::DrawBall(16,texture_roof,Point(depth/2,depth-6,depth/2));

		glDisable(GL_TEXTURE_2D);
	};
};

