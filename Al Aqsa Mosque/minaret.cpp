#include "minaret.h"
#include "Pillar.h"
#include "DrawWall.h"
 Minaret::Minaret(float width , float height): width(width) , height(height){}

 void Minaret::draw_minaret(Point str , int base_texture , int pillar_texture , int wall_texture , int ground_texture ){
	 glEnable(GL_TEXTURE_2D);
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
	 float roof_length = wall_length + shifting * 2 , roof_height = wall_length * 0.03 + shifting , roof_width = wall_length + shifting ;
	 primitives::DrawWall(Point(0 , 0 , 0) , roof_length, roof_height , roof_width, wall_texture) ;

	 glTranslated(0 , roof_height + 0.0001, 0);


	 Point cylinder_center = Point(roof_length/2.0f , 0 , roof_width/2.0f);
	 float last_rad = min(roof_length , roof_width)/2.0f ;
	 
	 float cnt = 0 ;


	while(last_rad >= 0.1) {
		primitives::DrawCylinderBody(cylinder_center, last_rad , last_rad*0.9, 1 , pillar_texture);   
		glTranslated(0 , 0.5 , 0);
		
		last_rad *= 0.95 ;
	 }

	 //primitives::DrawCylinderBody(cylinder_center, rad , rad*0.6, cylinder_height , pillar_texture);   

	 glPopMatrix();
	 glDisable(GL_TEXTURE_2D);
 }