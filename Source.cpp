#include <iostream>
#include<cmath>
#define NDEBUG
#include <GL/freeglut.h>
#include"figura.h"
#include"cover.h"
#include"kolo.h"
#include<ctime>
#include"pola.h"
#include<vector>
#include<list>
#include<string>
#include<sstream>
#include"pkt.h"
#include"hp.h"
#include"enemy.h"
using namespace std;
int kierunek = 0; // kierunek obierany przez kulke
int czas = 0;
bool gameover = 0; 
bool wygrana = 0; 
vector<vector<pole>> pola;
vector<vector<punkt>> punkty; 
vector<hp> zycia; 
vector<enemy> wrogowie; 
kolo obiekt(0.04, 0);
int points = 0; 
bool meta; 
int ile = 0;

// class enum do kierunku zamiast intow, funjkcja do przeliczania, poprawa X
bool start = 0; 
bool iloscpunktow; 
int kierunek1 = 0; //kierunek obierany przez X
void kamera()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	const float ar = (float)800 / (float)1000;
	glFrustum(-ar, ar, -0.5, 0.5, 2.0, 100.0);
	gluLookAt(obiekt.x, obiekt.y, 5, obiekt.x, obiekt.y, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void idle()
{
	glutPostRedisplay();
}

void display()
{

	
	cover c(obiekt.gx(), obiekt.gy()); //przykrycie planszy
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	{
		glColor3d(1, 1, 1);
		glRasterPos3f(obiekt.gx() + 0.7, obiekt.gy() + 1.0, 0.0002);
		string napis = "POINTS";
		for (int i = 0; i < napis.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, napis[i]);
		}
	}
	glPopMatrix();

	

	glPushMatrix();
	{
		glColor3d(1, 1, 1);
		glRasterPos3f(obiekt.gx() + 0.7, obiekt.gy() + 0.9, 0.0002);
		string liczba = to_string(points); 
		for (int i = 0; i < liczba.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, liczba[i]);
		}
	}
	glPopMatrix();


	glPushMatrix();
	{   //c.rysuj();
		
		for (int i = 0; i < zycia.size(); i++)
		{
			zycia[i].rysuj(); 
		}
		for (int j = 0; j < wrogowie.size(); j++)
		{
			wrogowie[j].rysuj();
		}
		obiekt.rysuj();
		for (int i = 0; i < pola.size(); i++)
		{
			for (int j = 0; j < pola.size(); j++)
			{
				pola[i][j].rysuj();
			}

		}
		 
		
	}
	glPopMatrix();
	if (start == 0)
	{
		glPushMatrix();
		{
			glColor3d(1, 1, 1);
			glRasterPos3f(-0.2, 0.7, 0.0005);
			string zasady = "Zasady gry";
			for (int i = 0; i < zasady.length(); i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, zasady[i]);
			}
			glColor3d(1, 1,1);
			glRasterPos3f(-0.5, 0.4, 0.0005);
			string jeden = "Celem gry jest zdobycie 100 punktow.";
			for (int i = 0; i < jeden.length(); i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, jeden[i]);
			}
			glColor3d(1, 1, 1);
			glRasterPos3f(-0.5, 0.1, 0.0005);
			string dwa = "Spotkanie z X skutkuje odebraniem jednego zycia.";
			for (int i = 0; i < dwa.length(); i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, dwa[i]);
			}
			glColor3d(1, 1, 1);
			glRasterPos3f(-0.5, -0.3, 0.0005);
			string trzy = "Nacisnij o, by zaczac.";
			for (int i = 0; i < trzy.length(); i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, trzy[i]);
			}
			glTranslated(0, 0, 0.0004);
			glColor3d(0, 0, 0.2);


			glBegin(GL_POLYGON);
			{
				glVertex3d(-2 / 2, 2 / 2, 0);
				glVertex3d(2/ 2, 2 / 2, 0);
				glVertex3d(2 / 2, -2 / 2, 0);
				glVertex3d(-2/ 2, -2 / 2, 0);
			}
			glEnd();
		}
		glPopMatrix();
	}
	if (wygrana == 1)
	{
		glPushMatrix();
		{
			glColor3d(0, 0, 0);
			glRasterPos3f(obiekt.gx() -0.1 , obiekt.gy(), 0.0005);
			string go = "WYGRANA";
			for (int i = 0; i < go.length(); i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, go[i]);
			}
			glTranslated(obiekt.gx(), obiekt.gy(), 0.0004);
			glColor3d(1.0, 1.0,1.0);


			glBegin(GL_POLYGON);
			{
				glVertex3d(-10 / 2, 10 / 2, 0);
				glVertex3d(10 / 2, 10 / 2, 0);
				glVertex3d(10 / 2, -10 / 2, 0);
				glVertex3d(-10 / 2, -10 / 2, 0);
			}
			glEnd();
		}
		glPopMatrix();
	}
	if (gameover == 1)
	{
		glPushMatrix();
		{
			glColor3d(1, 1, 1);
			glRasterPos3f(obiekt.gx() - 0.05, obiekt.gy(), 0.0005);
			string koniec = "KONIEC GRY";
			for (int i = 0; i < koniec.length(); i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, koniec[i]);
			}
			glColor3d(1, 1, 1);
			glRasterPos3f(obiekt.gx() - 0.06, obiekt.gy() - 0.1, 0.0005);
			string podsumowanie = "zdobyta liczba punktow:";
			for (int i = 0; i < podsumowanie.length(); i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, podsumowanie[i]);
			}
			string liczba = to_string(points);
			for (int i = 0; i < liczba.length(); i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, liczba[i]);
			}
			glTranslated(obiekt.gx(), obiekt.gy(), 0.0004);
			glColor3d(0.0, 0.0, 0.0);


			glBegin(GL_POLYGON);
			{
				glVertex3d(-10 / 2, 10 / 2, 0);
				glVertex3d(10 / 2, 10 / 2, 0);
				glVertex3d(10 / 2, -10 / 2, 0);
				glVertex3d(-10 / 2, -10 / 2, 0);
			}
			glEnd();

		}
		glPopMatrix();
	}
	glutSwapBuffers();
	kamera();
	if (zycia.size() == 0)
	{
		gameover = 1;
	}
}

void InitGLUTScene(const char* window_name)
{
	glutInitWindowSize(1900, 1060);  //800 1000
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);

	glClearColor(0.2, 0.2, 0.2, 0.2);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}



void keyboard(unsigned char key, int x, int y)

{
	float kx = obiekt.gx() * 10;    //sprawdzenie, na ktorej kratce stoi aktualnie kulka - ii - rzad, jj - wiersze
	float ky = obiekt.gy() * 10;
	int ii;
	int jj;
	if (kx >= 0)
	{
		ii = (int)kx + 20;
	}
	if (kx < 0)
	{
		ii = (int)kx + 20;
	}
	if (ky >= 0)
	{
		jj = (int)ky + 20;
	}
	if (ky < 0)
	{
		jj = (int)ky + 20;
	}
	
	if (pola[ii][jj].czykasa() == true)
	{
		pola[ii][jj].kasa();
		points++;
	}


	if (kierunek == 0 && wygrana == 0 && gameover == 0){

		switch (key)

		{

		case'o':
		{
			start = 1; 
		}
		case 'd':

		{
			obiekt.rotuj(3);
			if (pola[ii][jj].be() == true || pola[ii + 1][jj].bw() == true)
			{

			}
			else
			{
		
				kierunek = 5;
		
			}
			break;

		}

		case 's':

		{obiekt.rotuj(2);
		if (pola[ii][jj].bs() == true || pola[ii][jj - 1].bn() == true)
		{

		}
		else
		{
			
			kierunek = 2;
		
		}
		break;

		}

		case 'a':

		{obiekt.rotuj(1);
		if (pola[ii][jj].bw() == true || pola[ii - 1][jj].be() == true)
		{

		}
		else
		{
			
			kierunek = 3;
			

		}

		break;

		}

		case 'w':

		{
			obiekt.rotuj(4);
			if (pola[ii][jj].bn() == true || pola[ii][jj + 1].bs() == true)
			{

			}
			else
			{
			
				kierunek = 4;
			
			}
			
		
		break;
		}

		default:

			break;
		}
	}
	else
	{ }
	
	obiekt.nxny();
	kamera();
	if (ii == 40 && jj == 1)
	{
		meta = 1; 
		cout << "meta"; 
	}
	if (points == 100)
	{
		
		wygrana = 1; 
		
	}
	if (zycia.size() == 0)
	{
		gameover = 1; 
	}
}



int czas1; 
void timer(int count)
{
	if (start == 1)
	{
		float kx = obiekt.gx() * 10;
		float ky = obiekt.gy() * 10;
		int ii;
		int jj;
		if (kx >= 0)
		{
			ii = (int)kx + 20;
		}
		if (kx < 0)
		{
			ii = (int)kx + 20;
		}
		if (ky >= 0)
		{
			jj = (int)ky + 20;
		}
		if (ky < 0)
		{
			jj = (int)ky + 20;
		}




		for (int i = 0; i < wrogowie.size(); i++)     //losowanie kierunku dla kazdego elementu wektorsa z X
		{

			if (wrogowie[i].kierunekk() == 0)
			{
				int a = rand() % 4;
				if (a == 1)
				{
					wrogowie[i].zmianakierunku(5);

					czas1 = 0;
				}
				if (a == 2)
				{
					wrogowie[i].zmianakierunku(2);
					czas1 = 0;
				}
				if (a == 3)
				{
					wrogowie[i].zmianakierunku(3);
					czas1 = 0;
				}
				if (a == 4)
				{
					wrogowie[i].zmianakierunku(4);
					czas1 = 0;
				}
			}
			switch (wrogowie[i].kierunekk())
			{

			case 5:
			{
				float e1x = wrogowie[i].mmx() * 10;     //sprawdzenie na ktorej kratce stoi element wektora
				float e1y = wrogowie[i].mmy() * 10;
				int ii1;
				int jj1;
				if (e1x >= 0)
				{
					ii1 = (int)e1x + 20;
				}
				if (e1x < 0)
				{
					ii1 = (int)e1x + 20;
				}
				if (e1y >= 0)
				{
					jj1 = (int)e1y + 20;
				}
				if (e1y < 0)
				{
					jj1 = (int)e1y + 20;
				}

				if (pola[ii1][jj1].be() == true || pola[ii1 + 1][jj1].bw() == true)
				{
					wrogowie[i].zmianakierunku(0);
					czas1 = 0;
				}

				else
				{
					wrogowie[i].przesun(0.005, 0);
					czas1++;

					if (czas1 == 20)
					{
						if (pola[ii1][jj1].be() == true || pola[ii1 + 1][jj1].bw() == true)
						{
							wrogowie[i].zmianakierunku(0);
							czas1 = 0;
						}
						czas1 = 0;
					}
				}
				if (ii1 == ii && jj1 == jj)
				{

					wrogowie.erase(wrogowie.begin() + i);
					zycia.pop_back();
					
				}

				break;
			}
			case 2:
			{
				float e1x = wrogowie[i].mmx() * 10;
				float e1y = wrogowie[i].mmy() * 10;
				int ii1;
				int jj1;
				if (e1x >= 0)
				{
					ii1 = (int)e1x + 20;
				}
				if (e1x < 0)
				{
					ii1 = (int)e1x + 20;
				}
				if (e1y >= 0)
				{
					jj1 = (int)e1y + 20;
				}
				if (e1y < 0)
				{
					jj1 = (int)e1y + 20;
				}
				if (pola[ii1][jj1].bw() == true || pola[ii1 - 1][jj1].be() == true)
				{
					wrogowie[i].zmianakierunku(0);
					czas1 = 0;
				}
				else
				{
					wrogowie[i].przesun(-0.005, 0);

					czas1++;
					if (czas1 == 20)
					{
						if (pola[ii1][jj1].bw() == true || pola[ii1 - 1][jj1].be() == true)
						{
							wrogowie[i].zmianakierunku(0);
							czas1 = 0;
						}
						czas1 = 0;
					}

				}

				if (ii1 == ii && jj1 == jj)
				{
					wrogowie.erase(wrogowie.begin() + i);
					zycia.pop_back();
				}
				break;
			}
			case 3:
			{float e1x = wrogowie[i].mmx() * 10;
			float e1y = wrogowie[i].mmy() * 10;
			int ii1;
			int jj1;
			if (e1x >= 0)
			{
				ii1 = (int)e1x + 20;
			}
			if (e1x < 0)
			{
				ii1 = (int)e1x + 20;
			}
			if (e1y >= 0)
			{
				jj1 = (int)e1y + 20;
			}
			if (e1y < 0)
			{
				jj1 = (int)e1y + 20;
			}

			if (pola[ii1][jj1].bs() == true || pola[ii1][jj1 - 1].bn() == true)  //jesli X jest przy scianie, nastepuje zmiana kierunku
			{
				wrogowie[i].zmianakierunku(0);
				czas1 = 0;
			}
			else
			{
				wrogowie[i].przesun(0, -0.005);

				czas1++;
				if (czas1 == 20)
				{
					if (pola[ii1][jj1].bs() == true || pola[ii1][jj1 - 1].bn() == true)
					{
						wrogowie[i].zmianakierunku(0);
						czas1 = 0;
					}
					czas1 = 0;
				}
			}

			if (ii1 == ii && jj1 == jj)  // jesli x i y kulki = x i y wrogów
			{
				wrogowie.erase(wrogowie.begin() + i);
				zycia.pop_back();
			}
			break;
			}
			case 4:
			{
				float e1x = wrogowie[i].mmx() * 10;
				float e1y = wrogowie[i].mmy() * 10;
				int ii1;
				int jj1;
				if (e1x >= 0)
				{
					ii1 = (int)e1x + 20;
				}
				if (e1x < 0)
				{
					ii1 = (int)e1x + 20;
				}
				if (e1y >= 0)
				{
					jj1 = (int)e1y + 20;
				}
				if (e1y < 0)
				{
					jj1 = (int)e1y + 20;
				}

				if (pola[ii1][jj1].bn() == true || pola[ii1][jj1 + 1].bs() == true)
				{
					wrogowie[i].zmianakierunku(0);
					czas1 = 0;
				}
				else
				{
					wrogowie[i].przesun(0, 0.005);
					czas1++;
					if (czas1 == 20)
					{
						if (pola[ii1][jj1].bn() == true || pola[ii1][jj1 + 1].bs() == true)
						{
							wrogowie[i].zmianakierunku(0);
							czas1 = 0;
						}
						czas1 = 0;
					}
				}
				if (ii1 == ii && jj1 == jj)
				{
					wrogowie.erase(wrogowie.begin() + i);
					zycia.pop_back();
				}
				break;
			}

			}
		}


		switch (kierunek)
		{
		case 5:
		{
			if (czas < 25)
			{

				obiekt.przesun(0.004, 0);
				for (int i = 0; i < zycia.size(); i++)
				{
					zycia[i].przesun(0.004, 0);
				}
				czas++;
			}
			else
			{

				czas = 0;
				kierunek = 0;
			}
			break;
		}
		case 2:
		{
			if (czas < 25)
			{
				obiekt.przesun(0, -0.004);
				for (int i = 0; i < zycia.size(); i++)
				{
					zycia[i].przesun(0, -0.004);
				}
				czas++;

			}
			else
			{
				czas = 0;
				kierunek = 0;
			}
			break;
		}
		case 3:
		{
			if (czas < 25)
			{
				obiekt.przesun(-0.004, 0);
				for (int i = 0; i < zycia.size(); i++)
				{
					zycia[i].przesun(-0.004, 0);
				}
				czas++;

			}
			else
			{
				czas = 0;
				kierunek = 0;
			}
			break;
		}	case 4:
		{
			if (czas < 25)
			{
				obiekt.przesun(0, 0.004);
				for (int i = 0; i < zycia.size(); i++)
				{
					zycia[i].przesun(0, 0.004);
				}
				czas++;

			}
			else
			{
				czas = 0;
				kierunek = 0;
			}
			break;
		}
		}
	}
	if (zycia.size() == 0)
	{
		gameover = 1;
	}
		glutTimerFunc(1, timer, 0);
	
}

int g_viewport_width = 0;
int g_viewport_height = 0;

void SetCallbackFunctions()
{
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(1000, timer, NULL);
	

}
void InitObjects()
{
	
	
	srand(time(NULL));
	for (int i = 0; i < 42; i++)
	{

		vector<pole> v;

		for (int j = 0; j < 42; j++)     //losowanie scian pól
		{
			int a[4] = { 0, 0, 0, 0 };
			if (rand() % 10  == 0)
				a[0] = 1;
			int b[4] = { 0, 0, 0, 0 };
			if (rand() % 10 == 0)
				b[0] = 1;
			int c[4] = { 0, 0, 0, 0 };
			if (rand() % 10 == 0)
				c[0] = 1;
			int d[4] = { 0, 0, 0, 0 };
			if (rand() % 10 == 0)
				d[0] = 1;
			pole n(i, j, a[0], b[0], c[0], d[0]);
			v.push_back(n);
		}

		pola.push_back(v);
	}
	
	for (int i = 0; i < 42; i++)
	{
		for (int j = 0; j < 42; j++)
		{

			if (pola[i][j].bn() == true && pola[i][j].bw() == true && pola[i][j].bs() == true && pola[i][j].be() == true)
			{
				pola[i][j].fn(); 
				pola[i][j].fs();
				pola[i][j].be();
				pola[i][j].bw();
			}

		}
	}
	
	for (int x = 0; x < 42; x++)     //ramka
	{
		pola[x][0].rs();
		pola[x][0].rn();
		pola[x][0].rw();
		pola[x][0].re();
		pola[x][0]._wypelnienie();
		
	}
	for (int y = 0; y < 42; y++)     //ramka
	{
		pola[0][y].rs();
		pola[0][y].rn();
		pola[0][y].rw();
		pola[0][y].re();
		pola[0][y]._wypelnienie();

	}
	for (int v = 0; v < 42; v++)     //ramka
	{
		pola[41][v].rs();
		pola[41][v].rn();
		pola[41][v].rw();
		pola[41][v].re();
		pola[41][v]._wypelnienie();

	}
	for (int n = 0; n < 42; n++)     //ramka
	{
		pola[n][41].rs();
		pola[n][41].rn();
		pola[n][41].rw();
		pola[n][41].re();
		pola[n][41]._wypelnienie();

	}
}

int main(int argc, char *argv[])
{
	
	hp h(obiekt.gx() + 1.05, obiekt.gy() + 1.01);
	zycia.push_back(h);
	hp h1(obiekt.gx() + 1.20, obiekt.gy() + 1.01);
	zycia.push_back(h1);
	hp h2(obiekt.gx() + 1.35, obiekt.gy() + 1.01);
	zycia.push_back(h2);
	for (int i = 0; i < 155; i++)
	{
		int a = rand() % 40;
		if (a == 0)
		{
			a = rand() % 40;
		}int b = rand() % 40;
		if (b == 0)
		{
			b = rand() % 40;
		}
		enemy e(a, b);
		wrogowie.push_back(e);
	}
	glutInit(&argc, argv);
	InitGLUTScene("Naprawde fajna gra");
	SetCallbackFunctions();
	InitObjects();
	glutTimerFunc(100, timer, NULL);
	glutMainLoop();

	return 0;
}