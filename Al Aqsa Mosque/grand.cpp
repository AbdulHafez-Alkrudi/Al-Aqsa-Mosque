#include "grand.h"
#include "texture.h"
grand::grand(void)
	{
	}


grand::~grand(void)
	{
	}
void grand::drawGrand(float TranslateX , float TranslateY , float TranslateZ , float width , float hieght , int Photo)
	{
		glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(TranslateX ,TranslateY , TranslateZ);
	glRotated(90 , 0 , 0 ,1);
	int i=0 , j=hieght , num=0;

	while(num!=width*hieght&& j!=0)
	{
		DrawSquare( 0,i, j , 1 , Photo);
		i++ , num++;
		if(i==width)
			{
				j-- , i=0;
			}
		}
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}
//10 , -5 , -31
// j = hieght =25 , i = width = 20