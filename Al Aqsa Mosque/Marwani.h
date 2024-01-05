#include "Pillar.h"
#include "primitives.h"
#include "DrawWall.h"
#include "texture.h"
#include <cmath>
#include "Point.h"
class Marwani {
public: 
	void drawMarwaniMosque(Point begin,float lenght,float width,float height,float depth,int wallTexrure,int carpet,int marble,int* texturess,int walls,int marwaniWall ,int blackMetal){
		primitives p1;
		//draw outside walls
		//back
		p1.DrawWall(begin,width,height,depth,marwaniWall);
		//front
		p1.DrawWall(Point(begin.x,begin.y,begin.z+lenght),width+depth,height,depth,marwaniWall);
		//left
		p1.DrawWall(begin,depth,height,lenght,marwaniWall);
		//right
		p1.DrawWall(Point(begin.x+width,begin.y,begin.z),depth,height,lenght,marwaniWall);
		//up
		p1.DrawWall(Point(begin.x,begin.y+height,begin.z),width,depth/2,lenght+depth,marwaniWall);
		
		//draw inside quads
		//carpet
		p1.DrawQuad(Point(begin.x+depth,begin.y,begin.z+depth),Point(begin.x+width,begin.y,begin.z+depth),
			Point(begin.x+width,begin.y,begin.z+lenght),Point(begin.x+depth,begin.y,begin.z+lenght),carpet);
		//back
		p1.DrawQuad(Point(begin.x+depth,begin.y,begin.z+depth+0.2),Point(begin.x+width,begin.y,begin.z+depth+0.2),
			Point(begin.x+width,begin.y+height,begin.z+depth+0.2),Point(begin.x+depth,begin.y+height,begin.z+depth+0.2),wallTexrure);
		//front
		p1.DrawQuad(Point(begin.x+depth,begin.y,begin.z-0.1+lenght),Point(begin.x+width,begin.y,begin.z-0.1+lenght),
			Point(begin.x+width,begin.y+height,begin.z-0.1+lenght),Point(begin.x+depth,begin.y+height,begin.z-0.1+lenght),wallTexrure);
		//left
		p1.DrawQuad(Point(begin.x+depth+0.1,begin.y,begin.z+lenght),Point(begin.x+depth+0.1,begin.y,begin.z+depth),
			Point(begin.x+depth+0.1,begin.y+height,begin.z+depth+0.1),Point(begin.x+depth+0.1,begin.y+height,begin.z+lenght),wallTexrure);
		//right
		p1.DrawQuad(Point(begin.x+width-0.1,begin.y,begin.z+lenght),Point(begin.x+width-0.1,begin.y,begin.z+depth),
			Point(begin.x+width-0.1,begin.y+height,begin.z+depth+0.1),Point(begin.x+width-0.1,begin.y+height,begin.z+lenght),wallTexrure);
		//up
		p1.DrawQuad(Point(begin.x+depth,begin.y+height-0.1,begin.z+depth),Point(begin.x+width,begin.y+height-0.1,begin.z+depth),
			Point(begin.x+width,begin.y+height-0.1,begin.z+lenght),Point(begin.x+depth,begin.y+height-0.1,begin.z+lenght),walls);
		
		
		//draw pillars inside mosque and wall above them
	 Pillar mosquePillar(2,height/2.6-(0.02*height/2.6));
	 for(int j = depth+20;j<=width-10-depth;j+=40){
		 for (int i =depth+20 ;i<lenght-depth-10;i+=40){	 
				glPushMatrix();
				glTranslated(begin.x+j,begin.y+height/2.1-(0.02*height/2.1),begin.z+i);
				glRotated(180,1,0,1);
				glRotated(180,1,0,0);
				p1.Arch1(20,22,5,16,texturess);
				glPopMatrix();
			 mosquePillar.cube_cylinder_pillar(Point(begin.x+j-0.5,begin.y, begin.z+i+19),marble,marble);
	 }}
	 for (int i = 5;i<height-10;i+=5){
		 p1.DrawWall(Point(begin.x+30,begin.y+i,begin.z+depth),32,1,8,blackMetal);
	 }
	 for (int i = 5;i<height-10;i+=5){
		 p1.DrawWall(Point(begin.x+70,begin.y+i,begin.z+depth),32,1,8,blackMetal);
	 }
	 float space = 30;
	 for (int i = 0;i<4;i++){
		 if(i==3)
			 space = 100;
		 p1.DrawWall(Point(begin.x+space,begin.y,begin.z+depth),2,30,8,blackMetal);
		 if(i==1)
			 space+=10;
		 if(i==0)
		 space +=30;
		 
	 }
		};
};
