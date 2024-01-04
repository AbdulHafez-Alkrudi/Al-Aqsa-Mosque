#include "LeftFace.h"
#include "texture.h"
#define unbind glBindTexture(GL_TEXTURE_2D, 0);
LeftFace::LeftFace(void)
	{
	}


LeftFace::~LeftFace(void)
	{
	}
void LeftFace::FirstEntranceLeft(){
	int photo = LoadTexture("images/walls/stone3.bmp" , 255);
	int photo2 = LoadTexture("images/walls/stone1.bmp" , 255);
	glPushMatrix();
	glTranslated(-11 , -5 , -17+3);
	DrawRectangle(0 , 0 , 1 , 8 , photo);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-11 , -5 , -17+3);
			glRotated(90 , 0 , 1,  0);
	DrawRectangle(0 , 0 , 4 , 8 , photo);
	glPopMatrix();
		glPushMatrix();
		glTranslated(-11 , -5 , -21+3);
	DrawRectangle(0 , 0 , 1 , 8 , photo);
	glPopMatrix();
		glPushMatrix();
	glTranslated(-14 , -5 , -21+3);
	DrawRectangle(0 , 0 , 4 , 7 , photo);
	glPopMatrix();
		glPushMatrix();
		glTranslated(-14 , -5 , -21+3);
			glRotated(90 , 0 , 1,  0);
	DrawRectangle(0 , 0 , 4 , 7 , photo);
	glPopMatrix();
		glPushMatrix();
		glTranslated(-14 , -5 , -25+3);
	DrawRectangle(0 , 0 , 4 , 7 , photo);
	glPopMatrix();
		glPushMatrix();
	glTranslated(-14 , -5 , -25+3);
	DrawRectangle(0 , 0 , 3 , 7 , photo);
	glPopMatrix();
		glPushMatrix();
		glTranslated(-14 , -5 , -25+3);
			glRotated(90 , 0 , 1,  0);
	DrawRectangle(0 , 0 , 4 , 3 , photo);
	glPopMatrix();
		glPushMatrix();
	glTranslated(-14 , -5 , -29+3);
	DrawRectangle(0 , 0 , 4 , 7 , photo);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-14 , -2 , -29+3);
	DrawSquare(0 , 0 , 0 ,1 , photo);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-14 , -2 , -26+3);
	DrawSquare(0 , 0 , 0 ,1 , photo);
	glPopMatrix();
		glPushMatrix();
		glTranslated(-17 , -5 , -29.1+3);
	DrawRectangle(0 , 0 , 7 , 3 , photo);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-17 , -5 , -29.1+3);
		glRotated(90 , 0 ,1 ,0);
	DrawRectangle(0 , 0 , 3 , 3 , photo);
	glPopMatrix();
	glPushMatrix();
		glTranslated(-17 , -5 , -32.1+3);
	DrawRectangle(0 , 0 , 7 , 3 , photo);
	glPopMatrix();
	
	unbind;
}