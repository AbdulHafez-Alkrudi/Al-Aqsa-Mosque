#pragma once 
#include "primitives.h"

class Minaret{
public:

	float width , height ;

	 Minaret(float width , float height);
	 void draw_minaret(Point str , int base_texture , int pillar_texture , int wall_texture , int ground_texture );

};