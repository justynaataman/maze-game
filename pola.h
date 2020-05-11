#pragma once

class pole
{
protected:
	float x; 
	float y; 
	bool n; //gora
	bool s; //dol 
	bool w; //lewo
	bool e; //prawo
	bool moneta = 1;
	bool wypelnienie; 

public:
	pole(); 
	pole(float dx, float dy, bool dn, bool ds, bool dw, bool de);
	void rysuj(); 
	float kx(); 
	float ky(); 
	bool bn(); 
	bool bs(); 
	bool bw(); 
	bool be(); 
	bool czykasa(); 
	void kasa(); 
	void rn(); 
	void rs();
	void rw();
	void re();
	void fn();
	void fs();
	void fw();
	void fe();
	void _wypelnienie();
};