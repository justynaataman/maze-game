#include"hp.h"
#define NDEBUG

#include <GL/freeglut.h>
#include<cmath>


hp::hp()
{}

hp::hp(double hhx, double hhy)
{
	hx = hhx;
	hy = hhy;
}

void hp::rysuj()
{




	float r = 0.1*sqrt(3) / 3;
	glPushMatrix();
	{
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(hx, hy, 0);
		glRotated(180, 0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		{
			for (int i = 0; i < 360; i += 120)
			{
				float pomX = r * sin(3.14*i / 180);
				float pomY = r * cos(3.14*i / 180);
				glVertex2f(pomX, pomY);
			}
		}
		glEnd();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glColor3f(1.0, 0.0, 0.0);

		glTranslatef(hx - 0.02, hy + 0.03, 0);
		
		glBegin(GL_POLYGON);

		for (int i = 0; i < 360; i += 5)

		{

			float pos_x, pos_y;

			pos_x = 0.035 * sin(i);

			pos_y = 0.035 * cos(i);

			glVertex2f(pos_x, pos_y + (0.035 / 2));

		}

		glEnd();
	}
	glPopMatrix(); 
	glPushMatrix();
	{
		glColor3f(1.0, 0.0, 0.0);

		glTranslatef(hx + 0.02, hy + 0.03, 0);

		glBegin(GL_POLYGON);

		for (int i = 0; i < 360; i += 5)

		{

			float pos_x, pos_y;

			pos_x = 0.035 * sin(i);

			pos_y = 0.035 * cos(i);

			glVertex2f(pos_x, pos_y + (0.035 / 2));

		}

		glEnd();
	}
	glPopMatrix();

}


void hp::przesun(double dx, double dy)
{
	hx += dx;
	hy += dy;
}