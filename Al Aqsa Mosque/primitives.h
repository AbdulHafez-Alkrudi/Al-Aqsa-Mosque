#include <iostream>
#include <cmath>
#include "Point.h"
#include "Cylinder.h"

#define unbind glBindTexture(GL_TEXTURE_2D, 0);
#pragma once
#define txt(s,t) glTexCoord2d(s,t)
#define white glColor3f(1,1,1)
#define db double 
#define cull glEnable(GL_CULL_FACE)
#define nocull glDisable(GL_CULL_FACE)
#define frontf glCullFace(GL_FRONT)
#define backf glCullFace(GL_BACK)
#define pshm glPushMatrix()
#define ppm glPopMatrix()

const db srt = 1.414213562373095;
const db PI = 3.1415926535897932384626433832795028;


class primitives
{
		
public:
	
	 /*primitives();
	 ~primitives();*/



	static void DrawRectangle(float x, float y, float width, float height , int texture) {
		//glColor3b(0 , 0 , 0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D , texture);
		glBegin(GL_QUADS);  // Begin drawing quads
		glTexCoord2d(0,0);
		glVertex2f(x, y);               // Bottom-left vertex
		glTexCoord2d(1 ,0);
		glVertex2f(x + width, y);       // Bottom-right vertex
		glTexCoord2d(1 ,1);
		glVertex2f(x + width, y + height);  // Top-right vertex
		glTexCoord2d(0 ,1);
		glVertex2f(x, y + height);          // Top-left vertex
		glEnd();  // End drawing quads
		glDisable(GL_TEXTURE_2D);
	}
	static void Drawsquare(float x, float y, float size , int texture)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D , texture);
		glBegin(GL_QUADS);  // Begin drawing quads
			glTexCoord2d(0,0);
			glVertex2f(x, y);             // Bottom-left vertex
			glTexCoord2d(size*0.5 ,0);
			glVertex2f(x + size, y);      // Bottom-right vertex
			glTexCoord2d(size*0.5 ,size*0.5);
			glVertex2f(x + size, y + size);  // Top-right vertex
			glTexCoord2d(0 ,size*0.5);
			glVertex2f(x, y + size);          // Top-left vertex
		glEnd();  // End drawing quads
		glDisable(GL_TEXTURE_2D);
	}
	static void DrawCircle(float cx, float cy, float radius, int numSegments)
	{
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(cx, cy);  // Center of the circle

		for (int i = 0; i <= numSegments; ++i) {
			float theta = float(2.0f * 3.14 * float(i)) / float(numSegments);
			float x = radius * cosf(theta);
			float y = radius * sinf(theta);
			glVertex2f(cx + x, cy + y);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	static void DrawLine(float x1, float y1, float x2, float y2)
{
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_LINES);
    glVertex2f(x1, y1);  // Starting point
    glVertex2f(x2, y2);  // Ending point
    glEnd();
	glDisable(GL_TEXTURE_2D);
}


	static void Draw3DHexagon(Point base , float width, float height, int texture = -1 ){
		glEnable(GL_TEXTURE_2D);
		if(texture != -1){
			glBindTexture(GL_TEXTURE_2D , texture);
		}
		glEnable(GL_TEXTURE_2D);
		  glPushMatrix();
		  for (int i = 0; i < 8; i++)
		  {
			  if (i == 0)
			  {
				  glPushMatrix();
				  glBindTexture(GL_TEXTURE_2D, texture);
			  
				  glBegin(GL_QUADS);
					  glTexCoord2d(0, 0);
					  glVertex3d(base.x, base.y, base.z);
				  
					  glTexCoord2d(1, 0);
					  glVertex3d(base.x + 20, base.y, base.z);
				  
					  glTexCoord2d(1, 1);
					  glVertex3d(base.x + 20, base.y + height, base.z);
				  
					  glTexCoord2d(0, 1);
					  glVertex3d(base.x, base.y + height, base.z);
				  glEnd();

				  glTranslated(40, 0, 0);
				  glBindTexture(GL_TEXTURE_2D, texture );
			  
				  glBegin(GL_QUADS);
					  glTexCoord2d(0, 0);
					  glVertex3d(base.x, base.y, base.z);
				  
					  glTexCoord2d(1, 0);
					  glVertex3d(base.x + 20, base.y, base.z);
				  
					  glTexCoord2d(1, 1);
					  glVertex3d(base.x + 20, base.y + height, base.z);
				  
					  glTexCoord2d(0, 1);
					  glVertex3d(base.x, base.y + height , base.z);
				  glEnd();
				  glPopMatrix();
			  }
			  else 
			  {
				  glTranslated(width, 0, 0);
				  glRotated(45, 0, 1, 0);
				  glBindTexture(GL_TEXTURE_2D, texture);
			  
				  glBegin(GL_QUADS);
					  glTexCoord2d(0, 0);
					  glVertex3d(base.x, base.y, base.z);
				  
					  glTexCoord2d(1, 0);
					  glVertex3d(base.x + width, base.y, base.z);
				  
					  glTexCoord2d(1, 1);
					  glVertex3d(base.x + width, base.y + height, base.z);
				  
					  glTexCoord2d(0, 1);
					  glVertex3d(base.x, base.y + height , base.z);
				  glEnd();
			  }
		  }
		  glPopMatrix();
		  glDisable(GL_TEXTURE_2D);

	}

	static void DrawBall( float rad, int texture, Point center)
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
	static void DrawCylinderBody(Point Base_center1, float Base_rad1, float Base_rad2, float height, int texture = -1)
	{
		glEnable(GL_TEXTURE_2D);
								glPushMatrix();

			glTranslated(Base_center1.x,Base_center1.y, Base_center1.z);

			Base_center1=Point(0,0,0);
			Point Base_center2=Point (0,height,0);
			if (texture == -1)
					glColor3f(1,1,1);
			float angle=0, x1=Base_rad1, z1=0, x2=Base_rad2, z2=0;
			for (angle=0; angle <=2*3.14+0.1; angle+=0.1)
			{
				Point a= Point (x1,Base_center1.y,z1);
				Point b= Point (x2,Base_center2.y,z2);
				
				x1=Base_rad1*cos(angle);
				z1=Base_rad1*sin(angle);
				x2=Base_rad2*cos(angle);
				z2=Base_rad2*sin(angle);
				float N=20;
				Point c= Point (x2,Base_center2.y,z2);
				Point d= Point (x1,Base_center1.y,z1);
				glBindTexture(GL_TEXTURE_2D,texture);

				glBegin(GL_QUADS);

					glTexCoord2f((angle/(2*3.14))*N,a.z/height);
					glVertex3f(a.x,a.y,a.z);
			
					glTexCoord2f((angle/(2*3.14))*N,b.z/height);
					glVertex3f(b.x,b.y,b.z);
			
					glTexCoord2f(((angle+0.1)/(2*3.14))*N,c.z/height);
					glVertex3f(c.x,c.y,c.z);
			
					glTexCoord2f(((angle+0.1)/(2*3.14))*N,d.z/height);
					glVertex3f(d.x,d.y,d.z);

				glEnd();
		}

		glTranslated(-Base_center1.x,-Base_center1.y, -Base_center1.z);
		 glPopMatrix();
		 glDisable(GL_TEXTURE_2D);

	};  
	static void DrawRing(Point center, float radin, float radout, int texture)
	{
		glEnable(GL_TEXTURE_2D);
		glPushMatrix( );
			glTranslated(center.x,center.y, center.z);
			if (texture!=-1)
					glColor3f(1,1,1);
			for (float angle = 0; angle<=2*3.14+1; angle+=0.1)
			{
				glBindTexture(GL_TEXTURE_2D,texture);
				glBegin(GL_QUADS);
					glTexCoord2f(radin*(0.5+cos(angle)),radin*(0.5+sin(angle)));
					glVertex3f(radin*cos(angle),radin*sin(angle),0);
					glTexCoord2f(radin*(0.5f+cos(angle+0.1f)),radin*(0.5f+sin(angle+0.1f)));
					glVertex3f(radin*cos(angle+0.1f),radin*sin(angle+0.1f),0.0f);
					glTexCoord2f(radout*(0.5+cos(angle+0.1)),radout*(0.5f+sin(angle+0.1f)));
					glVertex3f(radout*cos(angle+0.1),radout*sin(angle+0.1),0);
					glTexCoord2f(radout*(0.5+cos(angle)),radout*(0.5+sin(angle)));
					glVertex3f(radout*cos(angle),radout*sin(angle),0);
				glEnd();
			}
		glPopMatrix( );
		glDisable(GL_TEXTURE_2D);
	};
	
	static void DrawCupe(Point bottom_left_back, float length, float hight, float depth, int texture = -1)
	{
		glEnable(GL_TEXTURE_2D);
		glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);
			glColor3f(1,1,1);

			if(texture != -1)
				glBindTexture(GL_TEXTURE_2D,texture);

			//back
			glBegin(GL_QUADS);
			glTexCoord2d(0.25, 0.33);
			glVertex3d(0, 0, 0);
			glTexCoord2d(0.5, 0.33);
			glVertex3d(length, 0, 0);
			glTexCoord2d(0.5, 0.67);
			glVertex3d(length, hight, 0);
			glTexCoord2d(0.25, 0.67);
			glVertex3d(0, hight, 0);
			glEnd();


			//front
			glBegin(GL_QUADS);
			glTexCoord2d(1, 0.33);
			glVertex3d(0, 0, depth);
			glTexCoord2d(0.75, 0.33);
			glVertex3d(length, 0, depth);
			glTexCoord2d(0.75, 0.67);
			glVertex3d(length, hight, depth);
			glTexCoord2d(1, 0.67);
			glVertex3d(0, hight, depth);
			glEnd();

			//left
			glBegin(GL_QUADS);
			glTexCoord2d(0, 0.33);
			glVertex3d(0, 0, depth);
			glTexCoord2d(0.25, 0.33);
			glVertex3d(0, 0, 0);
			glTexCoord2d(0.25, 0.67);
			glVertex3d(0, hight, 0);
			glTexCoord2d(0, 0.67);
			glVertex3d(0, hight, depth);
			glEnd();

			//right
			glBegin(GL_QUADS);
			glTexCoord2d(0.75, 0.33);
			glVertex3d(length, 0, depth);
			glTexCoord2d(0.5, 0.33);
			glVertex3d(length, 0, 0);
			glTexCoord2d(0.5, 0.67);
			glVertex3d(length, hight, 0);
			glTexCoord2d(0.75, 0.67);
			glVertex3d(length, hight, depth);
			glEnd();


			//top
			glBegin(GL_QUADS);
			glTexCoord2d(0.25 , 0.67);
			glVertex3d(0, hight, 0);
			glTexCoord2d(0.5, 0.67);
			glVertex3d(length, hight, 0);
			glTexCoord2d(0.5, 1);
			glVertex3d(length, hight, depth);
			glTexCoord2d(0.25, 1);
			glVertex3d(0, hight, depth);
			glEnd();


			//bottom
			glBegin(GL_QUADS);
			glTexCoord2d(0.25, 0.33);
			glVertex3d(0, 0, 0);
			glTexCoord2d(0.5, 0.33);
			glVertex3d(length, 0, 0);
			glTexCoord2d(0.5,0);
			glVertex3d(length, 0, depth);
			glTexCoord2d(0.25, 0);
			glVertex3d(0, 0, depth);
			glEnd();
		
		glTranslated(-bottom_left_back.x,-bottom_left_back.y,-bottom_left_back.z);
		glDisable(GL_TEXTURE_2D);
	};
	
	static void DrawWall(Point bottom_left_back, float length, float hight_cube, float depth, int texture_wall)

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
	double t = 5;
	//draw wall
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D, texture_wall);

	//ABCD
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(a.x,a.y,a.z);
	glTexCoord2d(t, 0);
	glVertex3f(b.x,b.y,b.z);
	glTexCoord2d(t, t);
	glVertex3f(c.x,c.y,c.z);
	glTexCoord2d(0, t);
	glVertex3f(d.x,d.y,d.z);
	glEnd();


	//EFGH
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(e.x,e.y,e.z);
	glTexCoord2d(t, 0);
	glVertex3f(f.x,f.y,f.z);
	glTexCoord2d(t, t);
	glVertex3f(g.x,g.y,g.z);
	glTexCoord2d(0, t);
	glVertex3f(h.x,h.y,h.z);
	glEnd();

	//ABFE
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(a.x,a.y,a.z);
	glTexCoord2d(t, 0);
	glVertex3f(b.x,b.y,b.z);
	glTexCoord2d(t, t);
	glVertex3f(f.x,f.y,f.z);
	glTexCoord2d(0, t);
	glVertex3f(e.x,e.y,e.z);
	glEnd();

	//ADHE
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(a.x,a.y,a.z);
	glTexCoord2d(t, 0);
	glVertex3f(d.x,d.y,d.z);
	glTexCoord2d(t, t);
	glVertex3f(h.x,h.y,h.z);
	glTexCoord2d(0, t);
	glVertex3f(e.x,e.y,e.z);
	glEnd();

	//CBFG
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(c.x,c.y,c.z);
	glTexCoord2d(t, 0);
	glVertex3f(b.x,b.y,b.z);
	glTexCoord2d(t, t);
	glVertex3f(f.x,f.y,f.z);
	glTexCoord2d(0, t);
	glVertex3f(g.x,g.y,g.z);
	glEnd();

	//DCGH
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(d.x,d.y,d.z);
	glTexCoord2d(t, 0);
	glVertex3f(c.x,c.y,c.z);
	glTexCoord2d(t, t);
	glVertex3f(g.x,g.y,g.z);
	glTexCoord2d(0, t);
	glVertex3f(h.x,h.y,h.z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
};

	static void DrawCupe(Point bottom_left_back, float length, float hight, float depth, int texture, 
							bool is_exist_front, bool is_exist_back, bool is_exist_right,
							bool is_exist_left, bool is_exist_bottom, bool is_exist_top)
{
	glEnable(GL_TEXTURE_2D);
	glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);
		glBindTexture(GL_TEXTURE_2D,texture);

		if (is_exist_back){
			//back
			glBegin(GL_QUADS);
			glTexCoord2d(0.25, 0.33);
			glVertex3d(0, 0, 0);
			glTexCoord2d(0.5, 0.33);
			glVertex3d(length, 0, 0);
			glTexCoord2d(0.5, 0.67);
			glVertex3d(length, hight, 0);
			glTexCoord2d(0.25, 0.67);
			glVertex3d(0, hight, 0);
			glEnd();
		}

		if (is_exist_front){
			//front
			glBegin(GL_QUADS);
			glTexCoord2d(1, 0.33);
			glVertex3d(0, 0, depth);
			glTexCoord2d(0.75, 0.33);
			glVertex3d(length, 0, depth);
			glTexCoord2d(0.75, 0.67);
			glVertex3d(length, hight, depth);
			glTexCoord2d(1, 0.67);
			glVertex3d(0, hight, depth);
			glEnd();
		}

		if (is_exist_left){
			//left
			glBegin(GL_QUADS);
			glTexCoord2d(0, 0.33);
			glVertex3d(0, 0, depth);
			glTexCoord2d(0.25, 0.33);
			glVertex3d(0, 0, 0);
			glTexCoord2d(0.25, 0.67);
			glVertex3d(0, hight, 0);
			glTexCoord2d(0, 0.67);
			glVertex3d(0, hight, depth);
			glEnd();
		}

		if (is_exist_right){
			//right
			glBegin(GL_QUADS);
			glTexCoord2d(0.75, 0.33);
			glVertex3d(length, 0, depth);
			glTexCoord2d(0.5, 0.33);
			glVertex3d(length, 0, 0);
			glTexCoord2d(0.5, 0.67);
			glVertex3d(length, hight, 0);
			glTexCoord2d(0.75, 0.67);
			glVertex3d(length, hight, depth);
			glEnd();
		}

		if (is_exist_top){
			//top
			glBegin(GL_QUADS);
			glTexCoord2d(0.25 , 0.67);
			glVertex3d(0, hight, 0);
			glTexCoord2d(0.5, 0.67);
			glVertex3d(length, hight, 0);
			glTexCoord2d(0.5, 1);
			glVertex3d(length, hight, depth);
			glTexCoord2d(0.25, 1);
			glVertex3d(0, hight, depth);
			glEnd();
		}

		if (is_exist_bottom){

			//bottom
			glBegin(GL_QUADS);
			glTexCoord2d(0.25, 0.33);
			glVertex3d(0, 0, 0);
			glTexCoord2d(0.5, 0.33);
			glVertex3d(length, 0, 0);
			glTexCoord2d(0.5,0);
			glVertex3d(length, 0, depth);
			glTexCoord2d(0.25, 0);
			glVertex3d(0, 0, depth);
			glEnd();
		}

	glTranslated(-bottom_left_back.x,-bottom_left_back.y,-bottom_left_back.z);
	glDisable(GL_TEXTURE_2D);
};

static void Draw3dQuad(Point bottom_left_back , float width_lower_base , float length_lower_base , float width_upper_base , float length_upper_base , float height , int texture = -1){
	
	glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);
		bottom_left_back = Point(0 , 0 , 0) ;
		float shift_width  = (width_upper_base  - width_lower_base )/2.0f ; 
		float shift_length = (length_upper_base - length_lower_base)/2.0f ;

		if(texture != -1)
				glBindTexture(GL_TEXTURE_2D,texture);
			//back
			glBegin(GL_QUADS);
				glVertex3d(0, 0, 0);
				glTexCoord2d(0.5, 0.33);
				glVertex3d(width_lower_base, 0, 0);
				glTexCoord2d(0.5, 0.67);
				glVertex3d(width_upper_base - shift_width, height, -shift_length);
				glTexCoord2d(0.25, 0.67);
				glVertex3d(-shift_width , height, -shift_length);
			glEnd();


			//front
			glBegin(GL_QUADS);
				glTexCoord2d(1, 0.33);
				glVertex3d(0, 0, length_lower_base);
				glTexCoord2d(0.75, 0.33);
				glVertex3d(width_lower_base, 0, length_lower_base);
				glTexCoord2d(0.75, 0.67);
				glVertex3d(width_upper_base - shift_width, height, length_upper_base - shift_length);
				glTexCoord2d(1, 0.67);
				glVertex3d(-shift_width, height, length_upper_base - shift_length);
			glEnd();

			//left
			glBegin(GL_QUADS);
				glTexCoord2d(0, 0.33);
				glVertex3d(0, 0, length_lower_base);
				glTexCoord2d(0.25, 0.33);
				glVertex3d(0, 0, 0);
				glTexCoord2d(0.25, 0.67);
				glVertex3d(-shift_width, height, -shift_length);
				glTexCoord2d(0, 0.67);
				glVertex3d(-shift_width, height, length_upper_base - shift_length);
			glEnd();

			//right
			glBegin(GL_QUADS);
				glTexCoord2d(0.75, 0.33);	
				glVertex3d(width_lower_base, 0, length_lower_base);
				glTexCoord2d(0.5, 0.33);
				glVertex3d(width_lower_base, 0, 0);
				glTexCoord2d(0.5, 0.67);
				glVertex3d(width_upper_base - shift_width, height, -shift_length);
				glTexCoord2d(0.75, 0.67);
				glVertex3d(width_upper_base - shift_width, height, length_upper_base - shift_length);
			glEnd();


			//top
			glBegin(GL_QUADS);
				glTexCoord2d(0.25 , 0.67);
				glVertex3d(-shift_width , height, -shift_length);
				glTexCoord2d(0.5, 0.67);
				glVertex3d(width_upper_base - shift_width, height, -shift_length);
				glTexCoord2d(0.5, 1);
				glVertex3d(width_upper_base - shift_width, height, length_upper_base - shift_length);
				glTexCoord2d(0.25, 1);
				glVertex3d(-shift_width, height, length_upper_base - shift_length);
			glEnd();


			//bottom
			glBegin(GL_QUADS);
				glTexCoord2d(0.25, 0.33);
				glVertex3d(0, 0, 0);
				glTexCoord2d(0.5, 0.33);
				glVertex3d(width_lower_base, 0, 0);
				glTexCoord2d(0.5,0);
				glVertex3d(width_lower_base, 0, length_lower_base);
				glTexCoord2d(0.25, 0);
				glVertex3d(0, 0, length_lower_base);
			glEnd();

	

		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}

static void DrawCoordinates(bool only_positive = false , bool with_z = false ){
	glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		for(float i = -100 ; i <= 100 ; i+=0.1){
			glBegin(GL_POINTS);
				glVertex3d( (only_positive ? fabs(i) : i) , 0 , 0);
				glVertex3d(0 , (only_positive ? fabs(i) : i)  , 0);
			glEnd();

			if(with_z){
				glBegin(GL_POINTS);
					glVertex3d(0 , 0 , (only_positive ? fabs(i) : i) ) ;
				glEnd();
			}
		}
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}



void DrawQuad5(Point bottom_left, Point bottom_right, Point up_right, Point up_left, int texture, double repeat = 0, double reverse = 0)
{
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    double t = 1;
    if (repeat == 1)
        t = 1;
    if (reverse == 1)
    {
        // Reverse the order of vertices when reverse is 1
        glTexCoord2f(0, 0);
        glVertex3f(up_left.x, up_left.y, up_left.z);

        glTexCoord2f(t, 0);
        glVertex3f(up_right.x, up_right.y, up_right.z);

        glTexCoord2f(t, t);
        glVertex3f(bottom_right.x, bottom_right.y, bottom_right.z);

        glTexCoord2f(0, t);
        glVertex3f(bottom_left.x, bottom_left.y, bottom_left.z);
    }
    else
    {
        // Default order of vertices
        glTexCoord2f(0, 0);
        glVertex3f(bottom_left.x, bottom_left.y, bottom_left.z);

        glTexCoord2f(t, 0);
        glVertex3f(bottom_right.x, bottom_right.y, bottom_right.z);

        glTexCoord2f(t, t);
        glVertex3f(up_right.x, up_right.y, up_right.z);

        glTexCoord2f(0, t);
        glVertex3f(up_left.x, up_left.y, up_left.z);
    }

    glEnd();
	glDisable(GL_TEXTURE_2D);
}

static void DrawQuad(Point bottom_left, Point bottom_right, Point up_right, Point up_left, int texture, double repeat = 0, double reverse = 0)

{
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    double t = repeat;
   
    if (reverse == 1)
    {
        // Reverse the order of vertices when reverse is 1
        glTexCoord2f(0, 0);
        glVertex3f(up_left.x, up_left.y, up_left.z);

        glTexCoord2f(t, 0);
        glVertex3f(up_right.x, up_right.y, up_right.z);

        glTexCoord2f(t, t);
        glVertex3f(bottom_right.x, bottom_right.y, bottom_right.z);

        glTexCoord2f(0, t);
        glVertex3f(bottom_left.x, bottom_left.y, bottom_left.z);
    }
    else
    {
        // Default order of vertices
        glTexCoord2f(0, 0);
        glVertex3f(bottom_left.x, bottom_left.y, bottom_left.z);

        glTexCoord2f(t, 0);
        glVertex3f(bottom_right.x, bottom_right.y, bottom_right.z);

        glTexCoord2f(t, t);
        glVertex3f(up_right.x, up_right.y, up_right.z);

        glTexCoord2f(0, t);
        glVertex3f(up_left.x, up_left.y, up_left.z);
    }

    glEnd();
	glDisable(GL_TEXTURE_2D);
}

static void drawRing(db innerR, db outerR,db height, int sectorCnt, int texture1, int texture2, bool isHalf) {

	glEnable(GL_TEXTURE_2D);
	pshm;
	db x1, x2, x3, x4, y1, y2, y3, y4, angle; int div = 1;
	if (isHalf) div =2;
	for (float i = 0; i <sectorCnt/div ; i++) {
		angle = 2 * (i / sectorCnt) * PI;
		x1 = innerR * cos(angle);
		y1 = innerR * sin(angle);
		x2 = outerR * cos(angle);
		y2 = outerR * sin(angle);
		angle = 2 * (++i / sectorCnt) * PI;
		x3 = innerR * cos(angle);
		y3 = innerR * sin(angle);
		x4 = outerR * cos(angle);
		y4 = outerR * sin(angle);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glBegin(GL_QUADS);
		txt(0, 0);
		glVertex3d(x1, y1,height/ 2.0);
		txt(0, 1);
		glVertex3d(x2, y2, height/ 2.0);
		txt(1, 1);
		glVertex3d(x4, y4, height/ 2.0);
		txt(1, 0);
		glVertex3d(x3, y3, height/ 2.0);
		glEnd();

		angle = 2 * (++i / sectorCnt) * PI;
		x1 = innerR * cos(angle);
		y1 = innerR * sin(angle);
		x2 = outerR * cos(angle);
		y2 = outerR * sin(angle);

		glBindTexture(GL_TEXTURE_2D, texture2);
		glBegin(GL_QUADS);
		txt(0, 0);
		glVertex3d(x3, y3, height/ 2);
		txt(0, 1);
		glVertex3d(x4, y4, height/ 2);
		txt(1, 1);
		glVertex3d(x2, y2, height/ 2);
		txt(1, 0);
		glVertex3d(x1, y1, height/ 2);
		glEnd();
		i--;
	}
	ppm;
	unbind;
	glDisable(GL_TEXTURE_2D);
}


static void drawPipe(db innerR, db outerR, db height, int sectorCnt,int textures[4], bool isHalf, bool isArch = false) {

#pragma region front ring
	
	glEnable(GL_TEXTURE_2D);
	pshm;
	glNormal3f(0, 0, -1);
	cull;
	frontf;
	drawRing(innerR, outerR, -height, sectorCnt, textures[0], textures[1], isHalf);
	backf;
	nocull;
	ppm;
#pragma endregion

		if (!isArch) {
#pragma region outer cylinder
		pshm;
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[2]);
		Cylinder outerC = Cylinder(outerR, outerR, height, sectorCnt);
		outerC.setIsHalf(isHalf);
		cull;
		outerC.drawSide();
		nocull;
		ppm;
#pragma endregion
		}

#pragma region inner cylinder
	pshm;
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	Cylinder innerC = Cylinder(innerR, innerR, height, sectorCnt);
	innerC.setIsHalf(isHalf);
	innerC.reverseNormals();
	cull;
	innerC.drawSide();
	nocull;
	//glDisable(GL_TEXTURE_2D);
	ppm;
#pragma endregion

#pragma region back ring 
	pshm;
	glNormal3f(0, 0, 1);
	cull;
	drawRing(innerR, outerR, height, sectorCnt, textures[0], textures[1], isHalf);
	nocull;
	ppm;
#pragma endregion
	if (isHalf) {
		glNormal3f(0, -1, 0);
		cull;
		glBegin(GL_QUADS);
		glVertex3d(outerR,0,height/2.0);
		glVertex3d(innerR, 0, height / 2.0);
		glVertex3d(innerR, 0, -height / 2.0);
		glVertex3d(outerR, 0, -height / 2.0);
		glEnd();
		frontf;
		glBegin(GL_QUADS);
		glVertex3d(-outerR, 0, height / 2.0);
		glVertex3d(-innerR, 0, height / 2.0);
		glVertex3d(-innerR, 0, -height / 2.0);
		glVertex3d(-outerR, 0, -height / 2.0);
		glEnd();
		backf;
		nocull;
	}
	unbind;
	glDisable(GL_TEXTURE_2D);
}
static void Arch(db sectorCount , db radius, db thickness = 0) {

	glEnable(GL_TEXTURE_2D);
	db length = 0;
	pshm;
	glTranslatef(0, 0, -length / 2);
	glBegin(GL_TRIANGLE_STRIP);

	for (int i = 0; i <= sectorCount; ++i) {
		GLfloat angle = (static_cast<float>(i) / sectorCount) * PI;
		GLfloat x = radius * cos(angle);
		GLfloat y = radius * sin(angle);

		if (angle <= PI / 2) {
			glTexCoord2d(1, 1);
			glVertex3d(radius, radius + thickness, length);
			glTexCoord2d(x / radius, y / radius);
			glVertex3f(x, y, length);
		}
		else {
			glTexCoord2d(1, 1);
			glVertex3d(-radius, radius + thickness, length);
			glTexCoord2d(fabs(x) / radius, fabs(y) / radius);
			glVertex3f(x, y, length);
		}

	}
	glEnd();
	ppm;
	unbind ;
	glDisable(GL_TEXTURE_2D);
}



static void Arch1(db innerR, db outerR, db height, int sectorCnt, int textures[]) {
	glEnable(GL_TEXTURE_2D);
	white;
	pshm;
	glNormal3f(0, 0, 1);
	glTranslated(0, 0, height/2.0 - 0.01);
	cull;
	frontf;
	glBindTexture(GL_TEXTURE_2D , textures[4]);
	Arch(sectorCnt/2.0, outerR);
	backf;
	nocull;
	ppm;

	pshm;
	glNormal3f(0, 0, -1);
	glTranslated(0, 0, -height/2.0 + 0.01);
	cull;
	glBindTexture(GL_TEXTURE_2D , textures[5]);
	Arch(sectorCnt/2.0, outerR);
	nocull;
	ppm;
	unbind;
	//glColor3f(0, 0.123, 0.21);
	drawPipe(innerR, outerR, height, sectorCnt, textures, true, true);
	glDisable(GL_TEXTURE_2D);
}


};