#pragma once
#include"figura.h"



class kolo : public figura
{
public:
	kolo();
	kolo(double _r, int _rot);
	void rysuj();
	void rotuj(int numer);

	float gx(); 
	float gy(); 
	void nxny(); 
	
	double r;
	int rotacja; 
	int nx; 
	int ny; 

	 
};

