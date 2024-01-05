#pragma once
#include <cmath>
#include "primitives.h"
#include "texture.h"
#include "Point.h"
class Door
{
public:
	float length , height , width , angle ;
	bool opened ;
	Door(float length , float height , float width);

	void DrawSingleDoor (bool flip_the_openning_direction = false , int texture = 0 , int side_texture = 0);
	void DrawDoubledDoor(int texture , int side_texture = 0 );

	void openning_trigger(bool *keys);
};

