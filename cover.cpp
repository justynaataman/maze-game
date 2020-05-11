#include"cover.h"
#define NDEBUG
#include"figura.h"
#include <GL/freeglut.h>
#include<cmath>


cover::cover()
{}

cover::cover(float dx, float dy)
{
	x = dx;
	y = dy;
	

}

void cover::rysuj()
{
	glPushMatrix();
	{
		glTranslated(this->x, this->y + 0.3 + 5, 0.0001);
		glColor3d(0, 0, 0);


		glBegin(GL_POLYGON);
		{
			glVertex3d(-10 / 2, 10 / 2, 0);
			glVertex3d(10 / 2, 10 / 2, 0);
			glVertex3d(10/ 2, -10 / 2, 0);
			glVertex3d(-10 / 2, -10 / 2, 0);
		}
		glEnd();
		

	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslated(this->x, this->y - 0.3 - 5, 0.0001);
		glColor3d(0.0, 0.0, 0.0);


		glBegin(GL_POLYGON);
		{
			glVertex3d(-10 / 2, 10 / 2, 0);
			glVertex3d(10 / 2, 10 / 2, 0);
			glVertex3d(10 / 2, -10 / 2, 0);
			glVertex3d(-10 / 2, -10 / 2, 0);
		}
		glEnd();


	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslated(this->x + 0.3 + 5, this->y, 0.0001);
		glColor3d(0.0,0.0,0.0);


		glBegin(GL_POLYGON);
		{
			glVertex3d(-10 / 2, 10 / 2, 0);
			glVertex3d(10 / 2, 10 / 2, 0);
			glVertex3d(10 / 2, -10 / 2, 0);
			glVertex3d(-10 / 2, -10 / 2, 0);
		}
		glEnd();


	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslated(this->x - 0.3 - 5, this->y, 0.0001);
		glColor3d(0.0, 0.0,0.0);


		glBegin(GL_POLYGON);
		{
			glVertex3d(-10 / 2, 10 / 2, 0);
			glVertex3d(10 / 2, 10 / 2, 0);
			glVertex3d(10 / 2, -10 / 2, 0);
			glVertex3d(-10 / 2, -10 / 2, 0);
		}
		glEnd();


	}
	glPopMatrix();

}

