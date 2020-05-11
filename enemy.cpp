#include"enemy.h"
#define NDEBUG
#include"figura.h"
#include <GL/freeglut.h>
#include<cmath>


enemy::enemy()
{}

enemy::enemy(float eex, float eey)
{
	ex = eex*0.1 - 2;
	ey = eey*0.1 - 2;
	kierunek = 0; 
}

void enemy::rysuj()
{
	{

		glPushMatrix();
		{
			glTranslated(ex, ey, 0.0);
			glColor3d(1.0, 0.6, 0.0);
			glRotated(45, 0.0, 0.0, 1.0);
			glBegin(GL_POLYGON);
			{

				glVertex3d(-0.006 / 2, 0.1 / 2, 0);
				glVertex3d(0.006 / 2, 0.1 / 2, 0);
				glVertex3d(0.006 / 2, -0.1 / 2, 0);
				glVertex3d(-0.006 / 2, -0.1 / 2, 0);
			}
			glEnd();
		}
		glPopMatrix();
		glPushMatrix();
		{
			glTranslated(ex, ey, 0.0);
			glColor3d(1.0, 0.6, 0.0);
			glRotated(-45, 0.0, 0.0, 1.0);
			glBegin(GL_POLYGON);
			{

				glVertex3d(-0.006 / 2, 0.1 / 2, 0);
				glVertex3d(0.006 / 2, 0.1 / 2, 0);
				glVertex3d(0.006 / 2, -0.1 / 2, 0);
				glVertex3d(-0.006 / 2, -0.1 / 2, 0);
			}
			glEnd();
		}

		glPopMatrix();

	}
}
#include<iostream>

void enemy::mxmy()
{



	float tx = ex * 10;
	float ty = ey * 10;
	if (tx >= 0)
	{
		mx = (int)tx + 20;

	}
	if (tx < 0)
	{
		mx = (int)tx + 19;

	}
	if (ty >= 0)
	{
		my = (int)ty + 20;

	}
	if (ty < 0)
	{
		my = (int)ty + 19;

	}

}

float enemy::mmx()
{
	return this->ex;
}

float enemy::mmy()
{
	return this->ey;
}

void enemy::przesun(double dx, double dy)
{
	ex += dx;
	ey += dy;
}

void enemy::zmianakierunku(int nowy)
{
	kierunek = nowy; 
}

int enemy::kierunekk()
{
	return kierunek; 
}