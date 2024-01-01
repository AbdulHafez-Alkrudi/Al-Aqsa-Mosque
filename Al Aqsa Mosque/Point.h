#include <math.h>
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#pragma once 


class Point
{
public:
	float x,y,z;
	Point(void){};
	~Point(void){};

	Point(float x, float y, float z)
	{
		this->x=x;
		this->y=y;
		this->z=z;
	};

	static float distance(Point a, Point b)
	{
		return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
	};
};