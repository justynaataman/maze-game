#include"kolo.h"
#define NDEBUG
#include"figura.h"
#include <GL/freeglut.h>
#include<cmath>


kolo::kolo() :figura(), r(2)
{}

kolo::kolo(double _r, int _rot) : figura()
{
	r = _r; 
	rotacja = _rot; 
}

void kolo::rysuj()
{
	{

		glPushMatrix();
		
		glColor3f(1.0, 1.0, 1.0);

		glTranslatef(this->x, this->y, 0);
		glRotated(this->rotacja*90, 0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		
		for (int i = 0; i < 360; i += 5)

		{

			float pos_x, pos_y;

			pos_x = (r*0.1) * sin(i);

			pos_y = (r*0.1) * cos(i);

			glVertex2f(pos_x, pos_y + (this->r / 2));

		}

		glEnd();

		

		glColor3f(0.3, 0.0, 0.0);

	

		glBegin(GL_POLYGON);

		for (int i = 0; i < 360; i += 5)

		{

			float pos_x, pos_y;

			pos_x = r * sin(i);

			pos_y = r * cos(i);

			glVertex2f(pos_x, pos_y);

		}

		glEnd();

		glPopMatrix();
		

	}
}
#include<iostream>


void kolo::rotuj(int numer)
{
	this->rotacja = numer; 
}




void kolo::nxny()
{


	
	float tx = x * 10; 
	float ty = y * 10; 
	if (tx >= 0)
	{
		nx = (int)tx + 20;
		
	}
	if (tx < 0)
	{
		nx = (int)tx + 19;
		
	}
	if (ty >= 0)
	{
		ny = (int)ty + 20;
	
	}
	if (ty < 0)
	{
		ny = (int)ty + 19;
		
	}
		
}

float kolo::gx()
{
	return this->x;
}

float kolo::gy()
{
	return this->y;
}