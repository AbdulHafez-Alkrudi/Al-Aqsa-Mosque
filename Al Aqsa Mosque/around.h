#pragma once
#include <windows.h>	
#include <gl.h>			
#include <glu.h>		
#include <glaux.h>		
#include <cmath>
#include "texture.h"
#include "Point.h"
#include "Skybox.h"
#include "primitives.h"
#include "camera.h"
#include "DrawWall.h"
#include "House.h"
#include "Door.h"
#include <vector>

using std::vector;
class around
{
public:
	Point bottom_left_back;
	float length, depth;
	int texture_house_roof[4];
	int texture_house_door, texture_house_wall, texture_house_window,
		texture_mill_door,  texture_mill_wall,  texture_mill_window,  texture_mill_roof, texture_mill_blade,
		texture_tree_brown,  texture_tree_green;
	vector <House> h;
	around(void){};
	~around(void){};
	around(Point bottom_left_back,	float length, float depth, int texture_house_door,int texture_house_wall, int texture_house_window,int texture_house_roof[4])
	{
		this->bottom_left_back = bottom_left_back;
		this->length = length;
		this->depth= depth;
		this->texture_house_door= texture_house_door;
		this->texture_house_wall= texture_house_wall;
		this->texture_house_window= texture_house_window;
		for (int i=0; i<4; i++)
			this->texture_house_roof[i]= texture_house_roof[i];

		int house_in_row=length/5, house_in_colomn=(depth-6)/4;
		int mill_in_row=(length)/13;
		for (int i=0; i<house_in_row; i++)
		{
			for (int j=1; j<house_in_colomn; j++)
			{
				int x=rand()%4;
				h.push_back(*(new House(Point (5*i,0,4*j+6),4,3,1,3,texture_house_door,texture_house_wall,texture_house_window,texture_house_roof[x])));
			}
		}

	};


	void Drawaround()
	{

		glPushMatrix();
		glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);
		int house_in_row=length/5, house_in_colomn=(depth-6)/4;
		int mill_in_row=length/11;
		for (auto x:h)
			x.DrawHousewithoutDome(Point(0,0,0),100,40,40,40,texture_house_door,texture_house_wall,texture_house_window);
		

		glPopMatrix();
	};
};