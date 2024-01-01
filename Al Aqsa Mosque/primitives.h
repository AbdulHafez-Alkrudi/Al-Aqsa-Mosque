#include <iostream>
#include <cmath>
#include "Point.h"
#pragma once
class primitives
{
		
public:
	
	 /*primitives();
	 ~primitives();*/



	static void DrawRectangle(float x, float y, float width, float height , int texture) {
		//glColor3b(0 , 0 , 0);
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
	}
	static void Drawsquare(float x, float y, float size , int texture)
	{
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
		}
	static void DrawCircle(float cx, float cy, float radius, int numSegments)
	{
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(cx, cy);  // Center of the circle

		for (int i = 0; i <= numSegments; ++i) {
			float theta = float(2.0f * 3.14 * float(i)) / float(numSegments);
			float x = radius * cosf(theta);
			float y = radius * sinf(theta);
			glVertex2f(cx + x, cy + y);
		}
		glEnd();
	}
	static void DrawLine(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
    glVertex2f(x1, y1);  // Starting point
    glVertex2f(x2, y2);  // Ending point
    glEnd();
}


	static void Draw3DHexagon(Point base , float width, float height, int texture = -1 ){
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

	}

	static void DrawBall( float rad, int texture, Point center)
	{
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

	};
	static void DrawCylinderBody(Point Base_center1, float Base_rad1, float Base_rad2, float height, int texture = -1)
	{
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
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
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


	};  
	static void DrawRing(Point center, float radin, float radout, int texture)
	{
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
	};
	
	static void DrawCupe(Point bottom_left_back, float length, float hight, float depth, int texture = -1)
	{
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
	};
	
	static void DrawWall(Point bottom_left_back, float length, float hight_cube, float depth, int texture_wall)
{
	Point a= bottom_left_back;
	Point b= Point (a.x+length,a.y,a.z);
	Point c= Point (a.x+length,a.y,a.z+depth);
	Point d= Point (a.x,a.y,a.z+depth);
	Point e= Point (a.x,a.y+hight_cube,a.z);
	Point f= Point (a.x+length,a.y+hight_cube,a.z);
	Point g= Point (a.x+length,a.y+hight_cube,a.z+depth);
	Point h= Point (a.x,a.y+hight_cube,a.z+depth);
	double t = 3;
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
};

	static void DrawCupe(Point bottom_left_back, float length, float hight, float depth, int texture, 
							bool is_exist_front, bool is_exist_back, bool is_exist_right,
							bool is_exist_left, bool is_exist_bottom, bool is_exist_top)
{
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
};
	
void DrawQuad(Point bottom_left, Point bottom_right, Point up_right, Point up_left, int texture, double repeat = 0, double reverse = 0)
{
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    double t = 10;
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
}



};