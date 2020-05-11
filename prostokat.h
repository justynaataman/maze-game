#pragma once
#include"figura.h"


class prostokat: public figura
{
public: 
	prostokat();

	prostokat(double wys, double szer, int kol);
	//prostokat(double dx, double dy, double szer, double wys);
	void  rysuj();
	
	bool isinside(float dx, float dy);
protected:
	
	double szerokosc; 
	double wysokosc; 
	


};

