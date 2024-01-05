#include "Door.h"

Door::Door(float length , float height , float width): length(length) , height(height) , width(width){
	angle = 0 , opened = false ;
}

void Door::DrawSingleDoor(bool flip_the_openning_direction, int texture , int side_tex){
	// the drawing will always start in 0,0,0 , so do the translate before calling the function :)
	
	glPushMatrix();
	//primitives::DrawCoordinates(false , 1);
	if(flip_the_openning_direction){
		glTranslated(length*2+0.01 , 0 , width);
		glRotated(180-angle,0,1,0);
	}
	else{
		glRotated(angle , 0 , 1 , 0);
	}
	//primitives::DrawCoordinates(1 , 1);

	int safe_space = 0.2;

	primitives::DrawWall(Point(0,0,0),length , height,width , 0);

	// front side
	primitives::DrawQuad(Point(0,0,safe_space) , Point(length , 0 , safe_space) , Point(length , height , safe_space) , Point(0 , height , safe_space), texture , 1);
	
	// back side
	primitives::DrawQuad(Point(0,0,width+safe_space) , Point(length , 0 , width + safe_space) , Point(length , height , width + safe_space) , Point(0 , height , width+safe_space), texture , 1 );
	
	// left side
	primitives::DrawQuad(Point(0,0,width+safe_space) , Point(0,0,safe_space) , Point(0,height+safe_space,safe_space) , Point(0 , height +safe_space , width + safe_space) , side_tex );

	// right side
	primitives::DrawQuad(Point(length,0,width+safe_space) , Point(length,0,safe_space) , Point(length,height+safe_space,safe_space) , Point(length , height +safe_space, width + safe_space) , side_tex );

	// upper side
	primitives::DrawQuad(Point(0,height+safe_space,safe_space) , Point(length,height+safe_space,safe_space) , Point(length,height+safe_space,width+safe_space) , Point(0 , height +safe_space, width+safe_space) , side_tex );

	glPopMatrix();
}

void Door::DrawDoubledDoor(int texture , int side_texture){
	// the same as the single one:

	glPushMatrix();
	//angle = 45 ; 

	this->DrawSingleDoor(false , texture , side_texture);
	this->DrawSingleDoor(true  , texture , side_texture);

	glPopMatrix();
}


void Door::openning_trigger(bool *keys){
		if(keys['O']){
			angle = min(90 , angle + 1);
		}
		if(keys['C']){
			angle = max(0  , angle - 1);
		}
}

