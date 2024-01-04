#include <windows.h> // Header File For Windows
#include <gl.h>		 // Header File For The OpenGL32 Library
#include <glu.h>	 // Header File For The GLu32 Library
#include <glaux.h>
#include <fstream>
#include <cmath>
#pragma once
class sphereSunAndMoon
	{
	public:
		sphereSunAndMoon(void);
		~sphereSunAndMoon(void);
		void drawShpere(float radius, int slices, int stacks , int texture);
		void DisplaySunAndMoon(float radiusMovment, float radiusSunAndMoon, int slices, int stacks , int textureSun , int textureMoon , 
			double angleMovment , 
			double moveX , double moveY , 
			double transletXSun ,double translateYSun, double translateZSun , 
			double translateXMoon , double translateYMoon ,double translateZMoon);
	};

