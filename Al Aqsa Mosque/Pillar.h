
// This Class gonna be for drawing Pillar(√⁄„œ…) 
#include "primitives.h"
#pragma once

class Pillar{
	// Attributes:
public:
	
	float base_side_length , cylinder_length ;
	Pillar();
	Pillar(float base_side_length , float cylinder_length): base_side_length(base_side_length) , cylinder_length(cylinder_length){}


	void cube_cylinder_pillar(Point str, int base_texture , int cylinder_texture , bool with_lower_base  = 1, bool with_upper_base = 1){
		glEnable(GL_TEXTURE_2D);
		// first i'll draw the base which is a cube:
		glPushMatrix();
	
		float prev_length = 0 ; 
		float prev_height = 0 ; 
		if(with_lower_base)
		{
			primitives::DrawCupe(str,base_side_length ,base_side_length ,base_side_length, base_texture);
			prev_length = base_side_length  ; 
			prev_height = base_side_length  ; 

		}
	
		Point last_str = str ; 
	
	
		for(int i = 0 ; i < 2 ; i++){		
			glTranslated(last_str.x , last_str.y + prev_height, last_str.z);

			Point str_nextLayer = Point(0.1f * prev_length , 0 , 0.1 * prev_length);
			primitives::DrawCupe(str_nextLayer, prev_length*0.80f , 0.15f*prev_height, prev_length*0.80f, base_texture);
			last_str = str_nextLayer; 
			prev_length *= 0.80f ;
			prev_height *= 0.15f ;
		}


	 
		glTranslated(last_str.x , last_str.y + prev_height , last_str.z);

	
			// the center of the cylinder is the same as the upperside/lower of the cube:
			float x = float(prev_length/2.0f), y = /*float(prev_height/2.0f)*/ 0 , z = prev_length/2.0f;
			glTranslated(x , y , z);
			float rad = (base_side_length  * 0.4f) ;
			Point center_cylinder(0 , 0 , 0);

			primitives::DrawCylinderBody(center_cylinder,rad,rad,cylinder_length,cylinder_texture);
			if(with_upper_base){
				center_cylinder.y += cylinder_length ;
				primitives::DrawCylinderBody(center_cylinder , rad , rad * 2 , cylinder_length*0.1, cylinder_texture);
			}
		nocull;
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}

};
