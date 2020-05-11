#pragma once




class enemy
{
public:
	enemy();
	enemy(float eex, float eey); 
	void rysuj();

	void ruch();
	float mmx();
	float mmy();
	void mxmy();
	void przesun(double dx, double dy);
	int kierunek; 
	float ex; 
	float ey; 
	int mx;
	int my;
	void zmianakierunku(int nowy); 
	int kierunekk(); 


};

