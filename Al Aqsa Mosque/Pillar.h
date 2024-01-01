
// This Class gonna be for drawing Pillar(ÃÚãÏÉ) 
#include "primitives.h"
#pragma once

class Pillar{
	// Attributes:
public:
	
	float base_side_length , cylinder_length ;
	Pillar(float base_side_length , float cylinder_length  ) ;
	void cube_cylinder_pillar(Point str , int base_texture , int cylinder_texture , bool with_lower_base = 1 , bool with_upper_base = 1);

};
