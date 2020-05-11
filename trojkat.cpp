#include"trojkat.h"
#define NDEBUG
#include"figura.h"
#include <GL/freeglut.h>
#include<cmath>




trojkat::trojkat() :figura(), wysokosc(2), szerokosc(2)
{}


trojkat::trojkat(double _wys, double _szer, int kol) : figura()
{
	wysokosc = _wys;
	szerokosc = _szer;
	kolejnosc = kol;
}

void trojkat::rysuj()
{
	glPushMatrix();
	{
		glTranslated(this->x, this->y, 0.0);
		glColor3d(this->red, this->green, this->blue);

		glBegin(GL_POLYGON);
		{
			glVertex3d(this->szerokosc / 2, -this->wysokosc / 2, 0);
			glVertex3d(-this->szerokosc / 2, -this->wysokosc / 2, 0);
	        glVertex3d(this->szerokosc / 2, this->wysokosc / 2, 0);
		}
		glEnd();
	}
	glPopMatrix();
}
#include<iostream> 
using namespace std; 
bool trojkat::isinside(float dx, float dy)
{
    
	if (dx <= ((this->szerokosc / 2) + this->x) && dx >= ((-this->szerokosc / 2) + this->x) && dy <= (((this->wysokosc / this->szerokosc)*dx) + this->y) && y >= ((-this->wysokosc / 2) + this->y))
	{
		return true; 
	}
	else
	{
		return false;
	}
}

