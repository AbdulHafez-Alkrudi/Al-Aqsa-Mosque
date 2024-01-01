#include "minaret.h"
#include "Pillar.h"
#include "DrawWall.h"
 Minaret::Minaret(float width , float height): width(width) , height(height){}

 void Minaret::draw_minaret(Point str , int base_texture , int pillar_texture , int wall_texture , int ground_texture ){
	glPushMatrix();
	 glTranslated(str.x , str.y , str.z);
	 str = Point(0 , 0 , 0) ;

	 primitives::DrawCupe(str,width , height,width,base_texture);

	 glTranslated(str.x , str.y + height , str.z);

	 str = Point(0,0,0);

	 primitives::Draw3dQuad(str, width, width , width*1.6 , width*1.6 , height*0.1 , base_texture);

	 float shift = width * 0.3 ; 
	 float ground_length = width*1.6;
	 glTranslated(-shift , height * 0.1, -shift);

	 float wall_height = ground_length * 0.2 , wall_length = ground_length , wall_width = ground_length * 0.05;

	 // upper wall 
	 primitives::DrawWall(Point(0,0,0) , wall_length , wall_height , wall_width, wall_texture);
	 // left wall 
	 primitives::DrawWall(Point(0,0,0) , wall_width , wall_height , wall_length , wall_texture);
	 // lower wall 
	 primitives::DrawWall(Point(0,0,ground_length - wall_width*1.2 ) , wall_length, wall_height , wall_width , wall_texture);
	 // right wall 
	 primitives::DrawWall(Point(ground_length,0,0) , wall_width , wall_height, wall_length , wall_texture);


	 float pillar_height = wall_height * 2.5 , pillar_width = wall_width ; 

	 Pillar pillar(pillar_width , pillar_height);

	 // upper left
	 pillar.cube_cylinder_pillar(Point(shift*0.1,0,shift*0.1),pillar_texture , pillar_texture, false);
	
	 // upper right 
	 pillar.cube_cylinder_pillar(Point(wall_length+shift*0.1,0,shift*0.1),pillar_texture , pillar_texture , false);
	 
	 // lower right 
	 pillar.cube_cylinder_pillar(Point(shift*0.1,0,wall_length - wall_width),pillar_texture , pillar_texture , false );
	 
	 // lower left 
	 pillar.cube_cylinder_pillar(Point(wall_length,0,wall_length - wall_width),pillar_texture , pillar_texture , false);
	 // this shift caused by the upper base of the pillars and it's gonna be by the rad of it 
	 float shifting = pillar_width * 0.8 ;
	 glTranslated(-shifting , pillar_height + pillar_width * 0.6 + 0.001, -shifting) ;

	 // the roof
	 primitives::DrawWall(Point(0 , 0 , 0) , wall_length + shifting * 2, wall_length * 0.03, wall_length + shifting , wall_texture) ;

	 glTranslated(0 , wall_length * 0.03 + 0.0001, wall_width/2);


	 Point cylinder_center = Point( wall_length/2.0f , 0 , wall_length/2.0f);
	 float last_rad = wall_length/2 ;
	 float cylinder_height = wall_length  ;
	 float cnt = 0 ;


	 for(float i = 0.0 ; i <= cylinder_height ; i+=1){
		 if(last_rad <= 0.1) break;
		 primitives::DrawCylinderBody(cylinder_center, last_rad , last_rad*0.9, 1 , pillar_texture);   
		glTranslated(0 , 1 , 0);
		last_rad *=0.9;
	 }

	 //primitives::DrawCylinderBody(cylinder_center, rad , rad*0.6, cylinder_height , pillar_texture);   

	 glPopMatrix();
 }