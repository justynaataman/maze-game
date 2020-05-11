#pragma once 
#include"figura.h"



class trojkat: public figura
{
public:
	trojkat(); 
	trojkat(double _wys, double _szer, int kol); 
	void rysuj(); 
	bool isinside(float dx, float dy);
	
protected:
	double wysokosc;
	double szerokosc;
	
};