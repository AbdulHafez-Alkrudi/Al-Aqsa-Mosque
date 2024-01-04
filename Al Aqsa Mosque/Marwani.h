#include "Pillar.h"
#include "primitives.h"
#include "DrawWall.h"
#include "texture.h"
#include <cmath>
#include "Point.h"
class Marwani {
public: 
	void drawMarwaniMosque(Point begin,float lenght,float width,float height,float depth,int wallTexrure,int carpet,int marble){
		primitives p1;
		//draw outside walls
		//back
		p1.DrawWall(begin,width,height,depth,wallTexrure);
		//front
		p1.DrawWall(Point(begin.x,begin.y,begin.z+lenght),width+depth,height,depth,wallTexrure);
		//left
		p1.DrawWall(begin,depth,height,lenght,wallTexrure);
		//right
		p1.DrawWall(Point(begin.x+width,begin.y,begin.z),depth,height,lenght,wallTexrure);
		//up
		p1.DrawWall(Point(begin.x,begin.y+height,begin.z),width,depth/2,lenght+depth,wallTexrure);
		
		//draw inside quads
		//carpet
		p1.DrawQuad(Point(begin.x+depth,begin.y,begin.z+depth),Point(begin.x+width,begin.y,begin.z+depth),
			Point(begin.x+width,begin.y,begin.z+lenght),Point(begin.x+depth,begin.y,begin.z+lenght),carpet);
		//back
		p1.DrawQuad(Point(begin.x+depth,begin.y,begin.z+depth+0.1),Point(begin.x+width,begin.y,begin.z+depth+0.1),
			Point(begin.x+width,begin.y+height,begin.z+depth+0.1),Point(begin.x+depth,begin.y+height,begin.z+depth+0.1),carpet);
		//front
		p1.DrawQuad(Point(begin.x+depth,begin.y,begin.z-0.1+lenght),Point(begin.x+width,begin.y,begin.z-0.1+lenght),
			Point(begin.x+width,begin.y+height,begin.z-0.1+lenght),Point(begin.x+depth,begin.y+height,begin.z-0.1+lenght),carpet);
		//left
		p1.DrawQuad(Point(begin.x+depth+0.1,begin.y,begin.z+lenght),Point(begin.x+depth+0.1,begin.y,begin.z+depth),
			Point(begin.x+depth+0.1,begin.y+height,begin.z+depth+0.1),Point(begin.x+depth+0.1,begin.y+height,begin.z+lenght),carpet);
		//right
		p1.DrawQuad(Point(begin.x+width-0.1,begin.y,begin.z+lenght),Point(begin.x+width-0.1,begin.y,begin.z+depth),
			Point(begin.x+width-0.1,begin.y+height,begin.z+depth+0.1),Point(begin.x+width-0.1,begin.y+height,begin.z+lenght),carpet);
		//up
		p1.DrawQuad(Point(begin.x+depth,begin.y+height-0.1,begin.z+depth),Point(begin.x+width,begin.y+height-0.1,begin.z+depth),
			Point(begin.x+width,begin.y+height-0.1,begin.z+lenght),Point(begin.x+depth,begin.y+height-0.1,begin.z+lenght),carpet);
		
		
		//draw pillars inside mosque and wall above them
	 Pillar mosquePillar(2,height/1.6-(0.02*height/1.6));
	 for(int j = depth+10;j<=width-10-depth;j+=30){
		 //p1.DrawWall(Point(210+j-0.5,16+height/1.5-(0.02*height/1.5),200+depth),3,13-depth,lenght-depth,qibaliMosque);
		 //p1.DrawWall(Point(210+j-0.5,16+height/1.5-(0.02*height/1.5)-1,200+depth),3,1,lenght-depth,mosaic);
		 for (int i =depth+20 ;i<lenght-depth-10;i+=40){	 
			 mosquePillar.cube_cylinder_pillar(Point(begin.x+j,begin.y, begin.z+i),marble,marble);
	 }
	 }

		};



};