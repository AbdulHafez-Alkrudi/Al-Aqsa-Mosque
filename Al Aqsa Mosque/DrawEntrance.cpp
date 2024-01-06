#include "DrawEntrance.h"
#include "texture.h"

#define unbind glBindTexture(GL_TEXTURE_2D, 0);
DrawEntrance::DrawEntrance(void)
{
}


DrawEntrance::~DrawEntrance(void)
	{
	}
    void DrawEntrance:: DrawArch(float radius , int photo) 
	{
		glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, photo);

		glBegin(GL_TRIANGLE_FAN);
		glTexCoord2f(0.5, 0.5);  // Center of texture
		glVertex2f(0.0, 0.0);    // Center of half-circle
		int segments = 100;

		for (int i = 0; i <= segments; ++i) {
			float theta = i * (3.14 / segments);
			float x = radius * cos(theta);
			float y = radius * sin(theta);

			// Map to texture coordinates such that only the upper half is used
			glTexCoord2f((x + 1.0) * 1.5, (y + 1.0) * 1.5);
			glVertex2f(x, y);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}