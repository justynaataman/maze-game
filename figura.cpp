#include"figura.h"
#define NDEBUG

#include <GL/freeglut.h>
#include<cmath>
#include<ctime>


figura::figura() :
x(0), y(0), red(1), green(0), blue(0), alfa(1){
}

void figura::przesun(double dx, double dy)
{
	x += dx;
	y += dy;
}
void figura::ustawkolor(double newred, double newgreen, double newblue)
{
	this->red = newred;
	this->green = newgreen;
	this->blue = newblue;

}

void figura::ustawpolozenie(double dx, double dy)
{
	this->x = dx; 
	this->y = dy; 
	
}



void figura::obroc(float dalfa) {
	alfa += dalfa;
	rysuj();
}