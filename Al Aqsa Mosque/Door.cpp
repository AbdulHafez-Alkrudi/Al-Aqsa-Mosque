#include "Door.h"

Door::Door(float length , float height , float width): length(length) , height(height) , width(width){
	angle = 0 , opened = false ;
}

void Door::DrawSingleDoor(bool flip_the_openning_direction, int texture ){
	// the drawing will always start in 0,0,0 , so do the translate before calling the function :)
	
	/*glRotated(angle , 0 , 1 , 0) ;*/
	glPushMatrix();
	primitives::DrawCoordinates(false , 1);
	if(flip_the_openning_direction){
		glTranslated(length*2+0.01 , 0 , width);
		glRotated(180-angle,0,1,0);
	}
	else{
		glRotated(angle , 0 , 1 , 0);
	}
	primitives::DrawCoordinates(false , 1);

	primitives::DrawWall(Point(0,0,0),length , height,width,texture);

	glPopMatrix();
}

void Door::DrawDoubledDoor(int texture ){
	// the same as the single one:

	glPushMatrix();
	//angle = 45 ; 
	this->DrawSingleDoor(false , texture);
	this->DrawSingleDoor(true);
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

