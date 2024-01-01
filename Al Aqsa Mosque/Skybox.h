#pragma once
#include "Point.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "primitives.h"

class Skybox
{
public:
	Point bottom_left_back;
	float length, depth, hight;
	int texture;
	Skybox(void){};
	~Skybox(void){};

	Skybox(Point bottom_left_back, float length, float depth, float hight, int texture)
	{
		this->bottom_left_back=bottom_left_back;
		this->depth=depth;
		this->hight=hight;
		this->length=length;
		this->texture=texture;
	};

	void DrawSkybox()
	{
		glPushMatrix();
		primitives::DrawCupe(bottom_left_back,length,hight,depth,texture);
		glPopMatrix();
	};
};