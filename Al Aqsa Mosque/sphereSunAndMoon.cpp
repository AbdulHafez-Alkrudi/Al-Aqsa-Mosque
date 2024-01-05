#include "sphereSunAndMoon.h"

sphereSunAndMoon::sphereSunAndMoon(void)
	{
	}


sphereSunAndMoon::~sphereSunAndMoon(void)
	{
	}
void sphereSunAndMoon::drawShpere(float radius, int slices, int stacks , int texture)
	{
glBindTexture(GL_TEXTURE_2D, texture);
    for (int i = 0; i < stacks; ++i) {
        float phi1 = static_cast<float>(3.14) * static_cast<float>(i) / stacks;
        float phi2 = static_cast<float>(3.14) * static_cast<float>(i + 1) / stacks;

        for (int j = 0; j < slices; ++j) {
            float theta1 = 2.0f * static_cast<float>(3.14) * static_cast<float>(j) / slices;
            float theta2 = 2.0f * static_cast<float>(3.14) * static_cast<float>(j + 1) / slices;

            // Vertices
            float x1 = radius * sin(phi1) * cos(theta1);
            float y1 = radius * sin(phi1) * sin(theta1);
            float z1 = radius * cos(phi1);

            float x2 = radius * sin(phi1) * cos(theta2);
            float y2 = radius * sin(phi1) * sin(theta2);
            float z2 = radius * cos(phi1);

            float x3 = radius * sin(phi2) * cos(theta2);
            float y3 = radius * sin(phi2) * sin(theta2);
            float z3 = radius * cos(phi2);

            float x4 = radius * sin(phi2) * cos(theta1);
            float y4 = radius * sin(phi2) * sin(theta1);
            float z4 = radius * cos(phi2);

            // Texture coordinates
            float s1 = static_cast<float>(j) / slices;
            float t1 = static_cast<float>(i) / stacks;
            float s2 = static_cast<float>(j + 1) / slices;
            float t2 = static_cast<float>(i + 1) / stacks;

            // Draw the faces with texture coordinates
            glBegin(GL_QUADS);
            glTexCoord2f(s1, t1); glVertex3f(x1, y1, z1);
            glTexCoord2f(s2, t1); glVertex3f(x2, y2, z2);
            glTexCoord2f(s2, t2); glVertex3f(x3, y3, z3);
            glTexCoord2f(s1, t2); glVertex3f(x4, y4, z4);
            glEnd();
        }
    }
	}
// float radiusMovment = 1000 , radiusSunAndMoon = 30; 
// int slices = 50, int stacks = 100;
//double angleMovment = 0 , moveX = 0 , moveY =0 , translateXSun = -200 , translateYSun = 200 , translateZSun =-200 , translateXMoon = -200, translateYMoon = 150 , translateZMoon = -200; 
void sphereSunAndMoon::DisplaySunAndMoon(float radiusMovment, float radiusSunAndMoon, int slices, int stacks , int textureSun , int textureMoon ,
										 double angleMovment , double moveX , double moveY , 
										 double transletXSun ,double translateYSun, double translateZSun , 
										 double translateXMoon , double translateYMoon , double translateZMoon)//radius is the radius of circuler movment , slices is the number of the squere you want to draw squere always is 
//DisplaySunAndMoon(30 , 50 , 100 , sun , moon ,0 ,0 , 0 , -200 , 200 , -200 ,-200 , 150 , -200)
	{
	if(angleMovment>=(2*6.28))
			angleMovment=0;
		 if(angleMovment>=0&&angleMovment<=4.71){
			glPushMatrix(); // display sphere sun
			glTranslated(transletXSun , translateYSun , translateZSun);
		glTranslated(moveX, moveY,0);
		drawShpere(radiusSunAndMoon , slices , stacks , textureSun);		
		glPopMatrix();
		moveX = radiusMovment *cos(angleMovment);
		moveY = radiusMovment *sin(angleMovment);
		angleMovment+=0.01;
			}
		else
			{
			// spherMoon;
			glPushMatrix();
			glTranslated(translateXMoon , translateYMoon , translateZMoon); //x = -200 , y = 150 , z = -200
				glTranslated(moveX, moveY,0);
				drawShpere(radiusSunAndMoon , slices , stacks , textureMoon);			
		glPopMatrix();
		moveX = radiusMovment *cos(angleMovment);
		moveY = radiusMovment *sin(angleMovment);
		angleMovment+=0.01;
			}
	}
