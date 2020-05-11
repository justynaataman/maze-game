#pragma once




class hp
{
public:
	hp();
	hp(double  hhx, double hhy); 
	void rysuj();
	void przesun(double dx, double dy);
protected:
	double hx;
	double hy;
};