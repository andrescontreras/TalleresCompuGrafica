/* -------------------------------------------------------------------------
 * @brief Example on how to capture mouse clicks in OpenGL
 * @author Leonardo Fl�rez-Valencia (florez-l@javeriana.edu.co)
 * -------------------------------------------------------------------------
 * Compilation on linux:
 *
 * g++ -std=c++17 mouse_click.cxx -lm -lGL -lGLU -lglut -o myMouseClickTest
 *
 * -------------------------------------------------------------------------
 */

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <stdlib.h>
using namespace std;


// -------------------------------------------------------
int clic[4];
// -------------------------------------------------------------------------
void Init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluOrtho2D(0, 25, 0, 25);
}
// -------------------------------------------------------------------------
std::vector<int> Bresenham_0()
{
	std::vector<int> puntos;
	int dx = clic[2] - clic[0];
	int dy = clic[3] - clic[1];
	int yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int D = (dy << 1) - dx;
	int y = clic[1];
	for (int x = clic[0]; x < clic[2]; x++)
	{
		puntos.push_back(x);
		puntos.push_back(y);
		if (D > 0)
		{
			y = y + yi;
			D = D - (dx << 1);
		}
		D = D + (dy << 1);
	}
	return puntos;
}
std::vector<int> Bresenham_1()
{
	std::vector<int> puntos;
	int dx = clic[2] - clic[0];
	int dy = clic[3] - clic[1];
	int xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int D = (dx << 1) - dy;
	int x = clic[0];
	for (int y = clic[1]; y < clic[3]; y++)
	{
		puntos.push_back(x);
		puntos.push_back(y);
		if (D > 0)
		{
			x = x + xi;
			D = D - (dy << 1);
		}
		D = D + (dx << 1);
	}
	return puntos;
}
// -------------------------------------------------------------------------
std::vector<int> DDA_0()
{
	std::vector<int> puntos;
	double dx = clic[2] - clic[0];
	double dy = clic[3] - clic[1];
	int step;
	if (abs(dy) < abs(dx))
		step = abs(dx);
	else
		step = abs(dy);
	dx = (double)dx / step;
	dy = (double)dy / step;
	int x = clic[0];
	int y = clic[1];
	double my = y;
	double mx = x;
	for (int i = 1; i < step; i++)
	{
		puntos.push_back((int)mx);
		puntos.push_back((int)my);
		mx = mx + dx;
		my = my + dy;
	}
	return puntos;
}

std::vector<int> puntosComunes(std::vector<int> DDA, std::vector<int> BRES) {
	std::vector<int> puntos;
	int iguales = 0, porcentaje;
	for (int i = 0; i < DDA.size(); i = i + 2)
	{

		for (int j = 0; j < BRES.size(); j = j + 2)
		{

			if (DDA[i] == BRES[j] && DDA[i + 1] == BRES[j + 1])
			{
				iguales += 1;
				puntos.push_back((int)DDA[i]);
				puntos.push_back((int)DDA[i + 1]);
			}


		}
	}
	if (iguales > 0)
	{
		porcentaje = (iguales * 100) / DDA.size();
		cout << "===============================================================\n";
		cout << "Puntos DDA: " << DDA.size() << endl;
		cout << "Puntos Bresenham: " << BRES.size() << endl;
		cout << "Puntos iguales: " << iguales << endl;
		cout << "Porcentaje de puntos comunes: " << porcentaje <<" %" << endl;
		cout << "===============================================================\n";
	}
	return puntos;
}
// -------------------------------------------------------------------------
void PrintLine(std::vector<int> puntos)
{
	for (int i = 0; i < puntos.size(); i = i + 2)
	{
		glVertex2i(puntos[i], puntos[i + 1]);
	}
}
// -------------------------------------------------------------------------
void DibujarLineas()
{
	std::vector<int> puntosComun;
	std::vector<int> DDA;
	std::vector<int> Bres;
	glColor3f(1, 0, 0);
	/*glPointSize(1.5)*/;
	std::cout << clic[0] << " ," << clic[1] << "  " << clic[2] << " ," << clic[3] << std::endl;
	glBegin(GL_POINTS);
	glVertex2f(20, 20);
	if (clic[2] - clic[0] != 0 && clic[3] - clic[1] != 0)
		DDA = DDA_0();
	PrintLine(DDA);
	glEnd();
	glBegin(GL_POINTS);
	if (abs(clic[2] - clic[0]) > abs(clic[3] - clic[1]))
	{
		if (clic[2] - clic[0] > 0)
		{
			std::cout << "1" << std::endl;
			Bres = Bresenham_0();
		}
		else
		{
			std::cout << "2" << std::endl;
			int tempx = clic[0];
			int tempy = clic[1];
			clic[0] = clic[2];
			clic[1] = clic[3];
			clic[2] = tempx;
			clic[3] = tempy;
			Bres = Bresenham_0();
		}
	}
	else
	{
		if (clic[3] - clic[1] > 0)
		{
			std::cout << "3" << std::endl;
			Bres = Bresenham_1();
		}
		else
		{
			std::cout << "4" << std::endl;
			int tempx = clic[0];
			int tempy = clic[1];
			clic[0] = clic[2];
			clic[1] = clic[3];
			clic[2] = tempx;
			clic[3] = tempy;
			Bres = Bresenham_1();
		}
	}
	glColor3f(0, 1, 0);
	PrintLine(Bres);
	glEnd();
	glBegin(GL_POINTS);
	puntosComun = puntosComunes(Bres, DDA);
	glColor3f(0, 0, 1);
	PrintLine(puntosComun);
	glEnd();

}
// -------------------------------------------------------------------------
void MouseCbk(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		clic[0] = x;
		clic[1] = glutGet(GLUT_WINDOW_HEIGHT) - y;
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		clic[2] = x;
		clic[3] = glutGet(GLUT_WINDOW_HEIGHT) - y;
	} // end if

}

// -------------------------------------------------------------------------
void DisplayCbk()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DibujarLineas();

	glFlush();
}

void myResize(int w, int h) {

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluOrtho2D(0, w, 0, h);

}
// -------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	int w, h;
	cout << "Ingrese el tamano de la pantalla \n";
	cout << "Ejemplo W H \n";
	cin >> w >> h;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(w, h);
	glutCreateWindow("mouse_click test!!!");
	glutDisplayFunc(DisplayCbk);
	glutMouseFunc(MouseCbk);
	glutReshapeFunc(myResize);
	Init();
	glutMainLoop();

	return(0);
}

// eof - mouse_click.cxx
