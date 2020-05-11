#include"pkt.h"
#define NDEBUG
#include"figura.h"
#include <GL/freeglut.h>
#include<cmath>






punkt::punkt()
{

}


punkt::punkt(float _x, float _y, float _r, float _b, float _g)
{
	x = _x*0.1 - 2;
	y = _y*0.1 - 2;
	red = _r; 
	blue = _b; 
	green = _g; 
}


void punkt::rysuj()
{
	{
		glPushMatrix();

	
		glTranslatef(this->x, this->y, 0);
	
		glBegin(GL_POLYGON);
	
    	glColor3f(this->red, this->blue, this->green);



		
		for (int i = 0; i < 360; i += 5)

		{

			float pos_x, pos_y;

			pos_x = 0.02 * sin(i);

			pos_y = 0.02 * cos(i);

			glVertex2f(pos_x, pos_y);

		}

		glEnd();

		glPopMatrix();


	}
}