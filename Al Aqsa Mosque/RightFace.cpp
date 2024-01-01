#include "RightFace.h"
#include "texture.h"

RightFace::RightFace(void)
	{
	}


RightFace::~RightFace(void)
	{
	}
void RightFace::DrawSquare(float x1 , float y1 , float z1 , float width , int photo)
	{
	glBindTexture(GL_TEXTURE_2D, photo);
	glBegin(GL_QUADS);
	glTexCoord2d( 0 , 0);
	glVertex3f(x1 , y1 , z1);
	glTexCoord2d( width , 0);
	glVertex3f(x1 ,y1, z1+width);
	glTexCoord2d( width , width);
	glVertex3f(x1, y1+width , z1+width);
	glTexCoord2d( 0 ,width);
	glVertex3f(x1 , y1+width , z1);
	glEnd();
	}
void RightFace::drawWall(float widthWall , float hieghtWall ,float Translatex, float Translatey , float Translatez,float RotateX , float RotateY , float RotateZ,float angle , int photo)
	{
	glPushMatrix();
	glTranslated(Translatex , Translatey , Translatez);
	glRotated(angle , RotateX , RotateY , RotateZ);
	float i=0 , j = hieghtWall , num = 0;
	while(num!=widthWall* hieghtWall&& j!=0)
	{
		DrawSquare( 0,i, j , 1 , photo);
		i++ , num++;
		if(i==widthWall)
			{
				j-- , i=0;
			}
	}
	glPopMatrix();
	}
