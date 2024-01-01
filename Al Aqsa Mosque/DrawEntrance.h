#include "primitives.h"
#pragma once
class DrawEntrance:public primitives
	{
	public:
		DrawEntrance(void);
		~DrawEntrance(void);
		void DrawArch(float radius , int photo);
		void DrawArch(float radius , float x1 , float y1 , float x2 , float y2);

	};

//25 