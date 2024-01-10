
#include "Pillar.h"
#include "primitives.h"
#include "DrawWall.h"
#include "texture.h"
#include <cmath>
#include "Point.h"
#define unbind glBindTexture(GL_TEXTURE_2D, 0);
class qibaliMosquee {
	public:

	void drawQibaliMosque(float lenghtOfWall,float depthOfWall,float heightOfWall,int mosquewindow,int qibaliMosque,
		int mosqueRoof2,int mosqueWindow2,int mosqueRoof,int mosaic,int marble,int house_wall,int arch,int carpet,int door,int mainDoor){
			glEnable(GL_TEXTURE_2D);
	primitives p;
	p.DrawWall(Point(180,12,200),lenghtOfWall,heightOfWall,depthOfWall,qibaliMosque);
	 for (int i = 10; i < lenghtOfWall; i += 20) {
    p.DrawQuad(Point(180 + i, heightOfWall - 0.6, 200 -0.2),
               Point(180 + (i + 25), heightOfWall - 0.6, 200 -0.2),
               Point(180 + (i + 25), 12 + heightOfWall-0.2 , 200 -0.2 ),
               Point(180 + i, 12 + heightOfWall-0.2 , 200 -0.2),
               mosquewindow, 1);
	
	}
	 //front
	 p.DrawWall(Point(180,12,200+lenghtOfWall),lenghtOfWall/2-10,heightOfWall,depthOfWall,house_wall);
	 p.DrawWall(Point(180+lenghtOfWall/2+15,12,200+lenghtOfWall),lenghtOfWall/2-15,heightOfWall,depthOfWall,house_wall);

	 //draw quad to add door textures
	 p.DrawQuad(Point(180+depthOfWall*2,12,200+lenghtOfWall+0.1+depthOfWall),Point(180+lenghtOfWall/4.5,12,200+lenghtOfWall+0.1+depthOfWall),
		 Point(180+lenghtOfWall/4.5,12+heightOfWall,200+lenghtOfWall+0.1+depthOfWall),Point(180+depthOfWall*2,12+heightOfWall,200+lenghtOfWall+0.1+depthOfWall),door,1,0);
	 p.DrawQuad(Point(180+lenghtOfWall/4.5+10,12,200+lenghtOfWall+0.1+depthOfWall),Point(180+lenghtOfWall/2.3,12,200+lenghtOfWall+0.1+depthOfWall),
		 Point(180+lenghtOfWall/2.3,12+heightOfWall,200+lenghtOfWall+0.1+depthOfWall),Point(180+lenghtOfWall/4.5+10,12+heightOfWall,200+lenghtOfWall+0.1+depthOfWall),door,1,0);
	 p.DrawQuad(Point(180+lenghtOfWall/2+15+depthOfWall,12,200+lenghtOfWall+0.1+depthOfWall),Point(180+lenghtOfWall/4.5+lenghtOfWall/2+depthOfWall,12,200+lenghtOfWall+0.1+depthOfWall),
		 Point(180+lenghtOfWall/4.5+lenghtOfWall/2+depthOfWall,12+heightOfWall,200+lenghtOfWall+0.1+depthOfWall),Point(180+depthOfWall+lenghtOfWall/2+15,12+heightOfWall,200+lenghtOfWall+0.1+depthOfWall),door,1,0);
	 p.DrawQuad(Point(180+depthOfWall+lenghtOfWall/4.5+lenghtOfWall/2+depthOfWall+10,12,200+lenghtOfWall+0.1+depthOfWall),Point(180+lenghtOfWall-depthOfWall,12,200+lenghtOfWall+0.1+depthOfWall),
		 Point(180+lenghtOfWall-depthOfWall,12+heightOfWall,200+lenghtOfWall+0.1+depthOfWall),Point(180+depthOfWall+lenghtOfWall/4.5+lenghtOfWall/2+depthOfWall+10,12+heightOfWall,200+lenghtOfWall+0.1+depthOfWall),door,1,0);
	 
	 //draw main door
	 p.DrawQuad(Point(180+lenghtOfWall/2.3,12,200+lenghtOfWall+0.1+depthOfWall),Point(180+lenghtOfWall/2.3-5,12,200+lenghtOfWall+0.1+depthOfWall+12.5),
		 Point(180+lenghtOfWall/2.3-5,12+heightOfWall,200+lenghtOfWall+0.1+12.5+depthOfWall),Point(180+lenghtOfWall/2.3,12+heightOfWall,200+lenghtOfWall+0.1+depthOfWall),mainDoor,1,0);
	 p.DrawQuad(Point(180+lenghtOfWall/2+15,12,200+lenghtOfWall+0.1+depthOfWall),Point(180+lenghtOfWall/2+15+5,12,200+lenghtOfWall+0.1+12.5+depthOfWall),
		 Point(180+lenghtOfWall/2+15+5,12+heightOfWall,200+lenghtOfWall+0.1+12.5+depthOfWall),Point(180+lenghtOfWall/2+15,12+heightOfWall,200+lenghtOfWall+0.1+depthOfWall),mainDoor,1,0);
	 
	 //left
    p.DrawWall(Point(180,12,200),depthOfWall,heightOfWall,lenghtOfWall,qibaliMosque);
	 for (int i = 10; i < lenghtOfWall; i += 20) {
    p.DrawQuad(Point(180-0.1 , heightOfWall - 0.6, 200 +0.2+i),
               Point(180-0.1 , heightOfWall - 0.6, 200 +0.2+ (i + 25)),
               Point(180 -0.1, 12 + heightOfWall-0.2 , 200 +0.2+ (i + 25) ),
               Point(180 -0.1, 12 + heightOfWall-0.2 , 200 +0.2+i ),
               mosquewindow, 1);
}
	//right
	p.DrawWall(Point(180+lenghtOfWall,12,200),depthOfWall,heightOfWall,lenghtOfWall,qibaliMosque);
	
	 for (int i = 10; i < lenghtOfWall; i += 20) {
		 p.DrawQuad(Point(180+lenghtOfWall+depthOfWall +0.1, heightOfWall - 0.6, 200 +0.2+i),
			 Point(180+lenghtOfWall+depthOfWall+0.1 , heightOfWall - 0.6, 200 +0.2+ (i + 25)),
			 Point(180+lenghtOfWall+depthOfWall +0.1, 12 + heightOfWall-0.2 , 200 +0.2+ (i + 25) ),
			 Point(180 +lenghtOfWall+depthOfWall+0.1, 12 + heightOfWall-0.2 , 200 +0.2+i ),
               mosquewindow, 1);
}
	//roof
	p.DrawWall(Point(180,12+heightOfWall,200),lenghtOfWall+depthOfWall,depthOfWall/3,lenghtOfWall+depthOfWall,mosqueRoof2);
	p.DrawQuad(Point(180,12,200),Point(180+lenghtOfWall,12,200),Point(180+lenghtOfWall,12,200+lenghtOfWall),Point(180,12,200+lenghtOfWall),carpet,0,1);
	/*ro->DrawBall(14,ball,Point (230,12+heightOfWall+5,200+lenghtOfWall+10));
	 ro->DrawOctagon(5, 10, -1, Point (-10, 10, 10)); */
	 //draw walls on the roof
	 p.DrawWall(Point(180+lenghtOfWall/3,12+heightOfWall+depthOfWall/3,200+25),lenghtOfWall/2,8,2,qibaliMosque);
	 p.DrawWall(Point(180+lenghtOfWall/3,12+heightOfWall+depthOfWall/3,200-25+lenghtOfWall),lenghtOfWall/2,8,2,qibaliMosque);
	 p.DrawWall(Point(180+lenghtOfWall/3,12+heightOfWall+depthOfWall/3,200+lenghtOfWall/2-50+2),2,8,lenghtOfWall-50,qibaliMosque);
	 p.DrawWall(Point(180+lenghtOfWall/3+lenghtOfWall/2,12+heightOfWall+depthOfWall/3,200+lenghtOfWall/2-50+2),2,8,lenghtOfWall-50,qibaliMosque);
	 p.DrawQuad(
		 Point(180+lenghtOfWall/3,12+heightOfWall+depthOfWall/3+8,200+25),
		 Point(180+lenghtOfWall/3+lenghtOfWall/4,12+heightOfWall+depthOfWall/3+8+5,200+25),
		 
		 Point(180+lenghtOfWall/3+lenghtOfWall/4,12+heightOfWall+depthOfWall/3+8+5,200+lenghtOfWall-25)
,		 
		 Point(180+lenghtOfWall/3,12+heightOfWall+depthOfWall/3+8,200+lenghtOfWall-25)
		 ,mosqueRoof2
		 );

	 p.DrawQuad(
		 Point(180+lenghtOfWall/3+lenghtOfWall/4,12+heightOfWall+depthOfWall/3+8+5,200+25),
		 Point(180+lenghtOfWall/3+lenghtOfWall/2+2,12+heightOfWall+depthOfWall/3+8,200+25),
		 
		 Point(180+lenghtOfWall/3+lenghtOfWall/2+2,12+heightOfWall+depthOfWall/3+8,200+lenghtOfWall-25)
,		 
		 Point(180+lenghtOfWall/3+lenghtOfWall/4,12+heightOfWall+depthOfWall/3+8+5,200+lenghtOfWall-25)
		 ,mosqueRoof2
		 );
	 //draw quads inside the mosque to add different textures
	 //back
	 p.DrawQuad(Point(180,12,200+depthOfWall+0.1),Point(180+lenghtOfWall,12,200+depthOfWall+0.1),
		 Point(180+lenghtOfWall,12+heightOfWall,200+depthOfWall+0.1),Point(180,12+heightOfWall,200+depthOfWall+0.1),house_wall);
	//draw windows
	 for (int i = 10; i < lenghtOfWall; i += 15) {
		 if(i == 85 || i == 100 )
			 continue;
    p.DrawQuad(Point(180 + i, heightOfWall - 0.6, 200 + depthOfWall +0.2),
               Point(180 + (i + 5), heightOfWall - 0.6, 200 + depthOfWall +0.2),
               Point(180 + (i + 5), 12 + heightOfWall-0.2 , 200 + depthOfWall+0.2 ),
               Point(180 + i, 12 + heightOfWall-0.2 , 200 + depthOfWall +0.2),
               mosqueWindow2, 1);
}
	 //front
	 p.DrawQuad(Point(180,12,200-0.1+lenghtOfWall),Point(180+lenghtOfWall/2-10,12,200-0.1+lenghtOfWall),
		 Point(180+lenghtOfWall/2-10,12+heightOfWall,200-0.1+lenghtOfWall),Point(180,12+heightOfWall,200-0.1+lenghtOfWall),house_wall);

	  p.DrawQuad(Point(180+lenghtOfWall/2+15,12,200-0.1+lenghtOfWall),Point(180+lenghtOfWall,12,200-0.1+lenghtOfWall),
		 Point(180+lenghtOfWall,12+heightOfWall,200-0.1+lenghtOfWall),Point(180+lenghtOfWall/2+15,12+heightOfWall,200-0.1+lenghtOfWall),house_wall);
	 
	 p.DrawQuad(Point(180+depthOfWall+0.1,12,200+lenghtOfWall),Point(180+depthOfWall+0.1,12,200-0.1+depthOfWall),
		 Point(180+depthOfWall+0.1,12+heightOfWall,200-0.1+depthOfWall),Point(180+depthOfWall+0.1,12+heightOfWall,200-0.1+lenghtOfWall),house_wall);

	 p.DrawQuad(Point(180+lenghtOfWall-depthOfWall+0.1,12,200+lenghtOfWall),Point(180+lenghtOfWall-depthOfWall+0.1,12,200-0.1+depthOfWall),
		 Point(180+lenghtOfWall-depthOfWall+0.1,12+heightOfWall,200-0.1+depthOfWall),Point(180+lenghtOfWall-depthOfWall+0.1,12+heightOfWall,200-0.1+lenghtOfWall),house_wall);
	 for (int i = 10; i < lenghtOfWall; i += 15) {
		 p.DrawQuad(Point(180+depthOfWall+0.2 , heightOfWall - 0.6, 200 +0.2+i),
               Point(180 +depthOfWall+0.2, heightOfWall - 0.6, 200 +0.2+ (i + 5)),
               Point(180 +depthOfWall+0.2, 12 + heightOfWall-0.2 , 200 +0.2+ (i + 5) ),
               Point(180 +depthOfWall+0.2, 12 + heightOfWall-0.2 , 200 +0.2+i ),
			   mosqueWindow2, 1);
}
	 
	 
	 
	 p.DrawQuad(Point(180,12+heightOfWall-0.1,200),Point(180+lenghtOfWall,12+heightOfWall-0.1,200),Point(180+lenghtOfWall,12+heightOfWall-0.1,200+lenghtOfWall),Point(180,12+heightOfWall-0.1,200+lenghtOfWall),mosqueRoof);
	  for (int i = 10; i < lenghtOfWall; i += 15) {
		  p.DrawQuad(Point(180-depthOfWall+lenghtOfWall , heightOfWall - 0.6, 200 +0.2+i),
               Point(180-depthOfWall +lenghtOfWall, heightOfWall - 0.6, 200 +0.2+ (i + 5)),
			   Point(180 -depthOfWall+lenghtOfWall, 12 + heightOfWall-0.2 , 200 +0.2+ (i + 5) ),
               Point(180-depthOfWall+lenghtOfWall, 12 + heightOfWall-0.2 , 200 +0.2+i ),
			   mosqueWindow2, 1);
}
	 //draw arch
	 p.DrawQuad(Point(180+lenghtOfWall/2-10,12,200+0.2+depthOfWall),Point(180+lenghtOfWall/2+10,12,200+0.2+depthOfWall),
		 Point(180+lenghtOfWall/2+10,12+20,200+0.2+depthOfWall),Point(180+lenghtOfWall/2-10,12+20,200+0.2+depthOfWall),arch,1);
	 
	 
	 float lenghtOfFront = 30;
	// draw the front
	 p.DrawWall(Point(180,12+heightOfWall,200+lenghtOfWall),lenghtOfWall+depthOfWall,5,lenghtOfFront,mosqueRoof2);
	 p.DrawWall(Point(180,12,200+lenghtOfWall),depthOfWall*2,heightOfWall,lenghtOfFront,qibaliMosque);
	 p.DrawWall(Point(180+lenghtOfWall-depthOfWall,12,200+lenghtOfWall),depthOfWall*2,heightOfWall,lenghtOfFront,qibaliMosque);
	 //pillars of Entrance
	 double lenghtOfFrontPillar = 28.5;
	 Pillar frontPillar(6,heightOfWall-(heightOfWall*0.22));
	 for(int i =0;i<=120;i+=20){
		 if(i == 60)
			 continue;
		 frontPillar.cube_cylinder_pillar(Point(180+i+15, 12, 200+lenghtOfWall+lenghtOfFront-depthOfWall),marble,marble);
	 }
	// ------------------------------------------------------------------------------------
	 //draw pillars inside mosque and wall above them
	 Pillar mosquePillar(4,heightOfWall/1.8-(0.02*heightOfWall/1.6));
	 for(int j = 0;j<=90;j+=30){
		 p.DrawWall(Point(210+j-0.5,16+heightOfWall/1.5-(0.02*heightOfWall/1.5),200+depthOfWall),3,13-depthOfWall,lenghtOfWall-depthOfWall,qibaliMosque);
		 p.DrawWall(Point(210+j-0.5,16+heightOfWall/1.5-(0.02*heightOfWall/1.5)-1,200+depthOfWall),3,1,lenghtOfWall-depthOfWall,mosaic);
	 for (int i =0 ;i<lenghtOfWall-10;i+=20){	 
		 mosquePillar.cube_cylinder_pillar(Point(210+j, 12, 210+i),marble,marble);
	 }
	 }

	 glDisable(GL_TEXTURE_2D);
};

};