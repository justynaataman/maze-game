#pragma once 

class punkt
{
protected:
	float x; 
	float y; 
	float red; 
	float blue; 
	float green; 


public: 
	punkt(); 
	punkt(float _x, float _y, float _r, float _b, float _g); 
	void rysuj(); 
 
};