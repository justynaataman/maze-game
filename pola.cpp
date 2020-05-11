#include"pola.h"
#define NDEBUG
#include"figura.h"
#include <GL/freeglut.h>
#include<cmath>


pole::pole()
{}


	

pole::pole(float dx, float dy, bool dn, bool de, bool ds, bool dw)
{
	x = dx*0.1 - 2;
	y = dy*0.1 - 2;
	n = dn;
	s = ds;
	w = dw;
	e = de;

}

void pole::rysuj()
{
	glPushMatrix();
	{
		glTranslated(this->x, this->y, 0.0);

		glColor3d(0.9, 0.9, 0.8);




		if (n == 1)
		{
			glBegin(GL_LINES);
			glVertex3f(-0.05, 0.05, 0);
			glVertex3f(0.05, 0.05, 0);
			glEnd();
		}

		if (s == 1)
		{
			glBegin(GL_LINES);
			glVertex3f(-0.05, -0.05, 0);
			glVertex3f(0.05, -0.05, 0);
			glEnd();
		}

		if (w == 1)
		{
			glBegin(GL_LINES);
			glVertex3f(-0.05, 0.05, 0);
			glVertex3f(-0.05, -0.05, 0);
			glEnd();
		}

		if (e == 1)
		{
			glBegin(GL_LINES);
			glVertex3f(0.05, 0.05, 0);
			glVertex3f(0.05, -0.05, 0);
			glEnd();
		}

	}
	glPopMatrix();
	if (moneta == 1)
	{
		glPushMatrix();


		glTranslatef(this->x, this->y, 0.0);

		glBegin(GL_POLYGON);

		glColor3f(1.0, 0.0, 1.0);




		for (int i = 0; i < 360; i += 5)

		{

			float pos_x, pos_y;

			pos_x = 0.005 * sin(i);

			pos_y = 0.005 * cos(i);

			glVertex2f(pos_x, pos_y);

		}

		glEnd();

		glPopMatrix();
		if (wypelnienie == 1)
		{
			glPushMatrix();
			{
				glTranslated(this->x, this->y, 0.0);
				glColor3d(0, 0, 0);

				glBegin(GL_POLYGON);
				{
					glVertex3d(-0.1 / 2, 0.1 / 2, 0);
					glVertex3d(0.1 / 2, 0.1 / 2, 0);
					glVertex3d(0.1 / 2, -0.1 / 2, 0);
					glVertex3d(-0.1 / 2, -0.1 / 2, 0);

				}
				glEnd();
			}
			glPopMatrix();
		}
	}
}



float pole::kx()
{
	return this->x; 
}
float pole::ky()
{
	return this->y;
}

bool pole::bn()
{
	if (this->n == 1)
	{
		return true; 
	}
}
bool pole::bs()
{
	if (this->s == 1)
	{
		return true; 
	}
}
bool pole::bw()
{
	if (this->w == 1)
	{
		return true; 
	}
}
bool pole::be()
{
	if (this->e == 1)
	{
		return true; 
	}
}

bool pole::czykasa()
{
	if (moneta == true)
	{
		return true; 
	}
}
void pole::kasa()
{
	this->moneta = false; 
}

void pole::rn()
{
	n = true; 
}
void pole::rw()
{
	w = true;
}
void pole::re()
{
	e = true;
}
void pole::rs()
{
	s = true;
}

void pole::fn()
{
	n = false;
}
void pole::fw()
{
	w = false;
}
void pole::fe()
{
	e = false;
}
void pole::fs()
{
	s = false;
}

void pole::_wypelnienie()
{
	wypelnienie = true;
}