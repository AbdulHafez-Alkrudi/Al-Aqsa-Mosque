#pragma once
#include <cmath>
#include "primitives.h"
#include "texture.h"
#include "Point.h"
class Door
{
public:
	float length , height , width ;
	bool opened ;
	static float angle ;
	Door(float length , float height , float width);

	void DrawSingleDoor (bool flip_the_openning_direction , int texture = 0 , int side_texture = 0);
	void DrawDoubledDoor(int texture , int side_texture = 0 );

	static void openning_trigger(bool *keys){
		if(keys['O']){
			angle = min(90 , angle + 1);
		}
		if(keys['C']){
			angle = max(0  , angle - 1);
		}
	}
};

