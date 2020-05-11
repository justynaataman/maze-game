#pragma once



class figura
{
public:
	double x, y;
	double red, green, blue;
	float alfa;
	
	float predkoscruchu; 
public:
	figura();


	virtual void rysuj() = 0;
	
	void przesun(double dx, double dy);
	void ustawkolor(double newred, double newgreen, double newblue);
	void ustawpolozenie(double dx, double dy); 
	void obroc(float dalfa); 
	
};