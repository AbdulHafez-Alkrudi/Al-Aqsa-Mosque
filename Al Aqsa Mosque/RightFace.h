#include "primitives.h"

#pragma once
class RightFace:public primitives
	{
	public:
		RightFace(void);
		~RightFace(void);
		void drawWall(float widthWall , float hieghtWall ,float Translatex, float Translatey , float Translatez,float RotateX , float RotateY , float RotateZ,float angle , int photo);
		void DrawSquare(float x1 , float y1 , float z1 , float width , int photo);
	};

