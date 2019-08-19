//  introOpenGL.cpp
//  Creado por Andrea Rueda, 01/2018
//
// #include <GL/glut.h>

#include <GL/freeglut.h>
#include <GL/gl.h>
#include "Punto.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct WindowData
{
  unsigned long Width, Height;
  double XMin, XMax, YMin, YMax;
};
WindowData win_data;
float varOrx = 0  ;
float varOry = 0 ;
float varOr2x = 0 ;
float varOr2y  =  0;
//

void myInit(void) {

	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluOrtho2D(0, 25, 0, 25);
	//glOrtho(0, 640, 0, 480, 1.0, -1.0);

}




//
/* funciones para pintar puntos*/
void dibujarPunto(Punto p) {
	glColor3fv(p.color);
	glPointSize(p.tamano);
	glBegin(GL_POINTS);
	glVertex2fv(p.posicion);
	glEnd();
}


void dibujarLinea(float x1, float x2, float y,float negativo) {
	float r1=255,g1=76,b1=51,r2=247,g2=94,b2=187;
	float bandera = true;
	for (float i = x1; i < x2; i=i+0.3)
	{
		bandera = !bandera;

		if (bandera)
		{
			dibujarPunto(Punto(i, y, r1, g1, b1, rand() % 4 + 1.2,negativo));
		}
		else
		{
			dibujarPunto(Punto(i, y, r2, g2, b2, rand() % 4 + 1.2,negativo));
		}
	}
}

void dibujarPuntoMismoColor(Punto p[], float tam, float r, float g, float b, float negativo) {

	for (int i = 0; i < tam; i++)
	{
		p[i].color[0] = abs(((1.0f / 255) *r) - negativo);
		p[i].color[1] = abs(((1.0f / 255) *g) - negativo);
		p[i].color[2] = abs(((1.0f / 255) *b) - negativo) ;
		dibujarPunto(p[i]);
	}
}




void myDisplay(float negativo) {
	/*float b[] = {1.0, 1.0, 0.0};
	glColor3fv(b)*/;

	// Contorno Estrella
	Punto contornoEstrella[] = { Punto(0, 4.8, 4),
	Punto(0.3, 4.9, 4),
	Punto(0.5, 5.1, 4),
	Punto(0.8, 5, 4),
	Punto(1, 5.1, 4),
	Punto(1.3, 5.2, 4),
	Punto(1.5, 5.4, 4),
	Punto(1.7, 5.5, 4),
	Punto(2, 5.6, 4),
	Punto(2.3, 5.7, 4),
	Punto(2.5, 5.8, 4),
	Punto(2.7, 5.8, 4),
	Punto(3, 5.9, 4),
	Punto(3.3, 6.0, 4),
	Punto(3.5, 6.1, 4),
	Punto(3.8, 6.2, 4),
	Punto(3.8, 5.7, 4),
	Punto(3.8, 5.5, 4),
	Punto(3.8, 5.3, 4),
	Punto(3.8, 5.0, 4),
	Punto(3.8, 4.8, 4),
	Punto(3.8, 4.5, 4),
	Punto(3.8, 4.3, 4),
	Punto(3.8, 4.0, 4),
	Punto(3.8, 3.7, 4),
	Punto(3.8, 3.5, 4),
	Punto(3.8, 3.3, 4),
	Punto(3.8, 3.0, 4),
	Punto(3.8, 2.7, 4),
	Punto(3.8, 2.5, 4),
	Punto(3.8, 2.3, 4),
	Punto(3.8, 2.0, 4),
	Punto(3.8, 1.7, 4),
	Punto(3.8, 1.5, 4),
	Punto(3.9, 1.3, 4),
	Punto(3.9, 1, 4),
	Punto(4, 0.7, 4),
	Punto(4.1, 0.7, 4),
	Punto(4.2, 0.7, 4),
	Punto(4.3, 0.8, 4),
	Punto(4.4, 0.8, 4),
	Punto(4.5, 0.8, 4),
	Punto(4.7, 1.3, 4),
	Punto(5, 1.5, 4),
	Punto(5.1, 1.7, 4),
	Punto(5.2, 2, 4),
	Punto(5.3, 2.5, 4),
	Punto(5.5, 2.7, 4),
	Punto(5.6, 3.0, 4),
	Punto(5.7, 3.2, 4),
	Punto(5.8, 3.5, 4),
	Punto(5.9, 3.7, 4),
	Punto(6, 4, 4),
	Punto(6.2, 4.3, 4),
	Punto(6.3, 4.7, 4),
	Punto(6.4, 5, 4),
	Punto(6.5, 5.3, 4),
	Punto(6.6, 5.5, 4),
	Punto(6.7, 5.8, 4),
	Punto(6.8, 6, 4),
	Punto(6.9, 6.3, 4),
	Punto(7.0, 6.4, 4),
	Punto(7.1, 6.6, 4),
	Punto(7.2, 6.6, 4),
	Punto(7.3, 6.9, 4),
	Punto(7.5, 7, 4),
	Punto(7.7, 6.8, 4),
	Punto(8.0, 6.7, 4),
	Punto(8.3, 6.6, 4),
	Punto(8.5, 6.6, 4),
	Punto(8.7, 6.5, 4),
	Punto(9, 6.4, 4),
	Punto(9.3, 6.3, 4),
	Punto(9.5, 6.2, 4),
	Punto(9.7, 6.1, 4),
	Punto(10, 6, 4),
	Punto(10.3, 5.9, 4),
	Punto(10.5, 5.8, 4),
	Punto(10.7, 5.7, 4),
	Punto(11, 5.6, 4),
	Punto(11.3, 5.5, 4),
	Punto(11.5, 5.4, 4),
	Punto(11.7, 5.4, 4),
	Punto(12.0, 5.3, 4),
	Punto(12.3, 5.3, 4),
	Punto(12.5, 5.3, 4),
	Punto(12.7, 5.4, 4),
	Punto(12.9, 5.5, 4),
	Punto(12.9, 5.6, 4),
	Punto(12.7, 5.7, 4),
	Punto(12.6, 5.9, 4),
	Punto(12.4, 6, 4),
	Punto(12.2, 6.2, 4),
	Punto(12, 6.4, 4),
	Punto(11.8, 6.6, 4),
	Punto(11.5, 6.9, 4),
	Punto(11.3, 7.0, 4),
	Punto(11.0, 7.3, 4),
	Punto(10.7, 7.6, 4),
	Punto(10.5, 7.7, 4),
	Punto(10.3, 7.8, 4),
	Punto(10, 8.2, 4),
	Punto(9.7, 8.3, 4),
	Punto(9.5, 8.6, 4),
	Punto(9.3, 8.7, 4),
	Punto(9.0, 9.0, 4),
	Punto(8.7, 9.3, 4),
	Punto(8.5, 9.5, 4),
	Punto(8.4, 9.9, 4),
	Punto(8.4, 10.3, 4),
	Punto(8.4, 10.5, 4),
	Punto(8.4, 10.5, 4),
	Punto(8.6, 10.8, 4),
	Punto(8.6, 11.0, 4),
	Punto(8.7, 11.3, 4),
	Punto(8.8, 11.5, 4),
	Punto(8.9, 11.7, 4),
	Punto(9.0, 12.0, 4),
	Punto(9.0, 12.3, 4),
	Punto(9.1, 12.5, 4),
	Punto(9.2, 12.7, 4),
	Punto(9.3, 12.8, 4),
	Punto(9.3, 12.9, 4),
	Punto(9.3, 13, 4),
	Punto(9.3, 13.3, 4),
	Punto(9.1, 13.4, 4),
	Punto(8.9, 13.3, 4),
	Punto(8.5, 13.2, 4),
	Punto(8.3, 13, 4),
	Punto(8, 12.8, 4),
	Punto(7.7, 12.6, 4),
	Punto(7.5, 12.4, 4),
	Punto(7.3, 12.3, 4),
	Punto(7, 12, 4),
	Punto(6.7, 11.8, 4),
	Punto(6.5, 11.5, 4),
	Punto(6.3, 11.4, 4),
	Punto(6.0, 11.2, 4),
	Punto(5.7, 11.1, 4),
	Punto(5.5, 11.1, 4),
	Punto(5.3, 11.1, 4),
	Punto(5.0, 11.2, 4),
	Punto(4.7, 11.3, 4),
	Punto(4.5, 11.4, 4),
	Punto(4.3, 11.5, 4),
	Punto(4.0, 11.6, 4),
	Punto(3.7, 11.7, 4),
	Punto(3.4, 12, 4),
	Punto(3.0, 12.2, 4),
	Punto(2.7, 12.3, 4),
	Punto(2.5, 12.5, 4),
	Punto(2.3, 12.6, 4),
	Punto(2.0, 12.7, 4),
	Punto(1.7, 12.8, 4),
	Punto(1.5, 12.8, 4),
	Punto(1.3, 12.7, 4),
	Punto(1.4, 12.3, 4),
	Punto(1.5, 12, 4),
	Punto(1.7, 11.6, 4),
	Punto(1.8, 11.3, 4),
	Punto(2, 11, 4),
		Punto(2.2, 10.7, 4),
		Punto(2.3, 10.5, 4),
	Punto(2.6, 10.1, 4),
		Punto(2.7, 9.8, 4),
		Punto(2.9, 9.7, 4),
		Punto(3.2, 9.4, 4),
	Punto(3, 9.3, 4),
		Punto(2.7, 9.0, 4),
		Punto(2.5, 8.8, 4),
		Punto(2.3, 8.6, 4),
	Punto(2, 8.5, 4),
		Punto(1.7, 8.3, 4),
		Punto(1.5, 8.2, 4),
		Punto(1.3, 8.0, 4),
		Punto(1.0, 7.8, 4),
		Punto(0.7, 7.6, 4),
	Punto(0.5, 7.3, 4),
		Punto(0.3, 7.2, 4),
	Punto(0, 6.9, 8),
	};
	// Fin Contorno Estrella
	// relleno estrella
	dibujarLinea(8.7, 9.0, 13.3,negativo);
	dibujarLinea(8.4, 9.0, 13.0,negativo);
	dibujarLinea(8.1, 9.0, 12.7,negativo);
	dibujarLinea(7.8, 8.9, 12.5,negativo);
	dibujarLinea(7.4, 8.9, 12.3,negativo);
	dibujarLinea(7.1, 8.8, 12.0,negativo);
	dibujarLinea(6.8, 8.6, 11.7,negativo);
	dibujarLinea(6.6, 8.5, 11.5,negativo);
	dibujarLinea(6.2, 8.5, 11.3,negativo);

	dibujarLinea(1.5, 2.0, 12.7,negativo);
	dibujarLinea(1.4, 2.3, 12.5,negativo);
	dibujarLinea(1.5, 2.6, 12.3,negativo);
	dibujarLinea(1.6, 3.3, 12.0,negativo);
	dibujarLinea(1.7, 3.8, 11.7,negativo);
	dibujarLinea(1.8, 4.3, 11.5,negativo);
	dibujarLinea(2.0, 4.7, 11.3,negativo);
	dibujarLinea(2.2, 8.5, 11,negativo);
	dibujarLinea(2.3, 8.4, 10.7,negativo);
	dibujarLinea(2.4, 8.3, 10.5,negativo);
	dibujarLinea(2.6, 8.3, 10.3,negativo);
	dibujarLinea(2.7, 8.3, 10,negativo);
	dibujarLinea(2.9, 8.3, 9.7, negativo);
	dibujarLinea(3.3, 8.4, 9.5, negativo);
	dibujarLinea(3.1, 8.6, 9.3, negativo);
	dibujarLinea(3,9,9, negativo);
	dibujarLinea(2.4,9.2, 8.7, negativo);
	dibujarLinea(2.2,9.5, 8.5, negativo);
	dibujarLinea(1.7,9.7, 8.3, negativo);
	dibujarLinea(2.4,10.1, 8, negativo);
	dibujarLinea(1,10.5, 7.7, negativo);
	dibujarLinea(0.7,10.7, 7.5, negativo);
	dibujarLinea(0.5,11, 7.3, negativo);
	dibujarLinea(0,11.3, 7.0, negativo);
	dibujarLinea(0,6.1, 6.7, negativo);
	dibujarLinea(0, 3.7, 6.3, negativo);
	dibujarLinea(0, 2.9, 6.0, negativo);
	dibujarLinea(0, 2.4, 5.7, negativo);
	dibujarLinea(0, 1.5, 5.5, negativo);
	dibujarLinea(0, 0.9, 5.3, negativo);

	dibujarLinea(8.2, 11.5, 6.7, negativo);
	dibujarLinea(8.8, 11.8, 6.5, negativo);
	dibujarLinea(9.4, 12.1, 6.3, negativo);
	dibujarLinea(10.1, 12.3, 6.0, negativo);
	dibujarLinea(10.9, 12.5, 5.7, negativo);
	dibujarLinea(11.6, 12.7, 5.5, negativo);

	dibujarLinea(3.9, 6.8, 6.3, negativo);
	dibujarLinea(3.9, 6.7, 6.0, negativo);
	dibujarLinea(3.9, 6.6, 5.7, negativo);
	dibujarLinea(3.9, 6.4, 5.5, negativo);
	dibujarLinea(3.9, 6.3, 5.3, negativo);
	dibujarLinea(3.9, 6.2, 5.0, negativo);
	dibujarLinea(3.9, 6.2, 4.7, negativo);
	dibujarLinea(3.9, 6.0, 4.5, negativo);
	dibujarLinea(3.9, 6.0, 4.3, negativo);
	dibujarLinea(3.9, 6.8, 4.0, negativo);
	dibujarLinea(3.9, 5.7, 3.7, negativo);
	dibujarLinea(3.9, 5.4, 3.5, negativo);
	dibujarLinea(3.9, 5.5, 3.3, negativo);
	dibujarLinea(3.9, 5.5, 3.0, negativo);
	dibujarLinea(3.9, 5.3, 2.7, negativo);
	dibujarLinea(3.9, 5.2, 2.5, negativo);
	dibujarLinea(3.9, 5.2, 2.3, negativo);
	dibujarLinea(3.9, 5.1, 2.0, negativo);
	dibujarLinea(3.9, 4.8, 1.7, negativo);
	dibujarLinea(3.9, 4.8, 1.5, negativo);
	dibujarLinea(3.9, 4.6, 1.3, negativo);





	// Division mar
	Punto divisionMar[] = { Punto(0, 22.8, 4),
	Punto(1.3, 22.2, 4),
	Punto(3, 22.6, 4),
	Punto(4, 22.8, 4),
	Punto(4.6, 22.5, 4),
	Punto(5.9, 21.7, 4),
	Punto(6.4, 21, 4),
	Punto(7, 20.1, 4),
	Punto(7.5, 19.3, 4),
	Punto(8.1, 18, 4),
	Punto(8.5, 17, 4),
	Punto(10, 16.2, 4),
	Punto(11.8, 15.6, 4),
	Punto(12.9, 15.5, 4),
	Punto(14.7, 13.8, 4),
	Punto(15.7, 13.1, 4),
	Punto(16.7, 12.5, 4),
	Punto(17.8, 12, 4),
	Punto(19, 11.5, 4),
	Punto(21, 11, 4),
	};
	// Fin Division mar

	// Inicio Mar
	float j = 0.0;
    float k = 0.0;
    float p = 0.0;
	for(float i = 0.0; i <= 14.5; i += 0.3 )
        dibujarPunto(Punto(21.0,29-i,82.0,65.0,220.0,3,negativo));
    srand (time(NULL));
    for(float i = 29; i >= 24.90 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 21; j+= 0.3 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,169, 230, 238,rand() % 3 + 1.2,negativo));
    }
    srand (time(NULL));
    for(float i = 24.80; i >= 22.4; i-= 0.2 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 10; j+= 0.5 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,169, 230, 238,rand() % 2 + 1.2,negativo));
    }

    for(float i = 22.50; i >=10 ; i-= 0.4 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 5 + k;j <= 21; j+= 0.5 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j,i,169, 230, 238,rand() % 2 + 1.2,negativo));
        k += 0.5+ (float)(rand() % 5 + (1) )/100;
    }
    dibujarPunto(Punto(12,16,169, 230, 238,rand() % 2 + 1.2,negativo));
    dibujarPunto(Punto(10,17,169, 230, 238,rand() % 2 + 1.2,negativo));
    dibujarPunto(Punto(10,18,169, 230, 238,rand() % 2 + 1.2,negativo));
    dibujarPunto(Punto(9,18,169, 230, 238,rand() % 2 + 1.2,negativo));
    dibujarPunto(Punto(9,17.3,169, 230, 238,rand() % 2 + 1.2,negativo));
    dibujarPunto(Punto(8,17.3,169, 230, 238,rand() % 2 + 1.4,negativo));
    dibujarPunto(Punto(8.5,16.3,169, 230, 238,rand() % 2 + 1.4,negativo));
    dibujarPunto(Punto(8.3,17.1,169, 230, 238,rand() % 2 + 1.4,negativo));
    dibujarPunto(Punto(8.7,16.6,169, 230, 238,rand() % 2 + 1.4,negativo));
    dibujarPunto(Punto(8.9,17.5,169, 230, 238,rand() % 2 + 1.4,negativo));
    dibujarPunto(Punto(11.8,17.1,169, 230, 238,rand() % 2 + 1.4,negativo));
    dibujarPunto(Punto(11.5,16.2,169, 230, 238,rand() % 2 + 1.4,negativo));
    dibujarPunto(Punto(11.6,17.3,169, 230, 238,rand() % 2 + 1.4,negativo));
    dibujarPunto(Punto(11.9,16.86,169, 230, 238,rand() % 2 + 1.4,negativo));
    dibujarPunto(Punto(11.3,17.2,169, 230, 238,rand() % 2 + 1.4,negativo));
    srand (time(NULL));
    for(float i = 29; i >= 24.90 ; i-= 0.1 + (float)(rand() % 6 + (1) )/100)
    {
        for(j = 0;j <= 21; j+= 0.33 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,82.0,65.0,220.0,rand() % 3 + 1.4,negativo));
    }
    srand (time(NULL));
    k = 0.0;
    for(float i = 24.80; i >=14.5 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 7.2 + k;j <= 21; j+= 0.3 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j,i,169, 230, 238,rand() % 3 + 1.2,negativo));
        k += 0.15 + (float)(rand() % 5 + (1) )/100;
    }
    srand (time(NULL));
    k = 0.0;
    for(float i = 24.80; i >=14.5 ; i-= 0.14 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 7.2 + k;j <= 21; j+= 0.33 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j,i,82.0,65.0,220.0,rand() % 3 + 1.4,negativo));
        k += 0.205 + (float)(rand() % 5 + (1) )/100;
    }
	//Inicio Arena
    //Color beige
    for(float i = 10.7; i >= 0 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 21; j+= 0.5 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,226, 133, 26,1.4,negativo));
    }
    for(float i = 15.5; i >= 10.8 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 10; j+= 0.5 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,226, 133, 26,1.4,negativo));
    }
    for(float i = 21.7; i >= 15.6 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 5.9; j+= 0.5 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,226, 133, 26,1.4,negativo));
    }
    for(float i = 21.7; i >= 15.6 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 5.75;j <= 5.75 + p ; j+= 0.4 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,226, 133, 26,1.4,negativo));
        p += 0.08;
    }
    p = 0;
    for(float i = 16.2; i >= 10.6 ; i-= 0.2 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 10;j <= 10 + p ; j+= 0.3 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,226, 133, 26,1.4,negativo));
        p += 0.45;
    }
    p = 0;
    for(float i = 22.8; i >= 21.8 ; i-= 0.25 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 5.9 + p ; j+= 0.35 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,226, 133, 26,1.4,negativo));
    }
    dibujarPunto(Punto(12.5,15.4,226, 133, 26,1.4,negativo));
    dibujarPunto(Punto(12.3,15.5,226, 133, 26,1.4,negativo));
    dibujarPunto(Punto(12.2,15.1,226, 133, 26,1.4,negativo));
    dibujarPunto(Punto(12.1,15.2,226, 133, 26,1.4,negativo));
    dibujarPunto(Punto(12.8,15.3,226, 133, 26,1.4,negativo));
    dibujarPunto(Punto(12.6,15,226, 133, 26,1.4,negativo));
    dibujarPunto(Punto(13,15.3,226, 133, 26,1.4,negativo));
    dibujarPunto(Punto(13,15,226, 133, 26,1.4,negativo));

    //Color Amarillo
    for(float i = 10.7; i >= 0 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 21; j+= 0.7 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,240, 236, 172,1.4,negativo));
    }
    for(float i = 15.5; i >= 10.8 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 10; j+= 0.5 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,240, 236, 172,1.4,negativo));
    }
    for(float i = 21.7; i >= 15.6 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 5.9; j+= 0.5 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,240, 236, 172,1.4,negativo));
    }
    for(float i = 21.7; i >= 15.6 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 5.75;j <= 5.75 + p ; j+= 0.4 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,240, 236, 172,1.4,negativo));
        p += 0.08;
    }
    p = 0;
    for(float i = 16.2; i >= 10.6 ; i-= 0.2 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 10;j <= 10 + p ; j+= 0.3 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,240, 236, 172,1.4,negativo));
        p += 0.45;
    }
    p = 0;
    //Color cafe
    for(float i = 10.7; i >= 0 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 21; j+= 0.9 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,144, 104, 52,1.4,negativo));
            dibujarPunto(Punto(j+0,i,144, 104, 52,1.4,negativo));
    }
    for(float i = 15.5; i >= 10.8 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 10; j+= 0.5 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,144, 104, 52,1.4,negativo));
            dibujarPunto(Punto(j+0,i,144, 104, 52,1.4,negativo));
    }
    for(float i = 21.7; i >= 15.6 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 5.9; j+= 0.5 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,144, 104, 52,1.4,negativo));
            dibujarPunto(Punto(j+0,i,144, 104, 52,1.4,negativo));
    }
    for(float i = 21.7; i >= 15.6 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 5.75;j <= 5.75 + p ; j+= 0.4 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,144, 104, 52,1.4,negativo));
            dibujarPunto(Punto(j+0,i,144, 104, 52,1.4,negativo));
        p += 0.08;
    }
    p = 0;
    for(float i = 16.2; i >= 10.6 ; i-= 0.2 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 10;j <= 10 + p ; j+= 0.3 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,144, 104, 52,1.4,negativo));
            dibujarPunto(Punto(j+0,i,144, 104, 52,1.4,negativo));
        p += 0.45;
    }
    p = 0;
    //Color naranja
    for(float i = 10.7; i >= 0 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 21; j+= 0.6 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,240, 152, 37,1.4,negativo));
    }
    for(float i = 15.5; i >= 10.8 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 10; j+= 0.5 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,240, 152, 37,1.4,negativo));
    }
    for(float i = 21.7; i >= 15.6 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 0;j <= 5.9; j+= 0.5 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,240, 152, 37,1.4,negativo));
    }
    for(float i = 21.7; i >= 15.6 ; i-= 0.1 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 5.75;j <= 5.75 + p ; j+= 0.4 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,240, 152, 37,1.4,negativo));
        p += 0.08;
    }
    p = 0;
    for(float i = 16.2; i >= 10.6 ; i-= 0.2 + (float)(rand() % 5 + (1) )/100)
    {
        for(j = 10;j <= 10 + p ; j+= 0.3 + (float)(rand() % 21 + (-10) )/100 )
            dibujarPunto(Punto(j+0,i,240, 152, 37,1.4,negativo));
        p += 0.45;
    }
    p = 0;

	dibujarPuntoMismoColor(contornoEstrella, 179, 255, 76, 51,negativo);
	dibujarPuntoMismoColor(divisionMar, 20, 247, 187, 94, negativo);


}

void myDisplay2(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(win_data.Width/2, 0, win_data.Width/2, win_data.Height);
    glLoadIdentity();
    myDisplay(0);
    glViewport(0, 0, win_data.Width/2, win_data.Height);
    glLoadIdentity();
    myDisplay(1);
    glFlush();
    glutPostRedisplay();


}
void myResize(int width, int height) {

  win_data.Width = width;
  win_data.Height = ( height > 0 )? height: 1;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(varOrx, 420/2+varOr2x, varOry,580/2+varOr2y);
  glMatrixMode(GL_MODELVIEW);

}

void KeyboardCbk( unsigned char key, int x, int y )
{

}

// -------------------------------------------------------------------------
void SpecialKeyboardCbk( int key, int x, int y )
{
    switch (key){
        case GLUT_KEY_RIGHT:
        varOrx += 2;
        varOr2x += 2;
        break;
    case GLUT_KEY_LEFT:
        varOrx -= 2;
        varOr2x -= 2;
        break;
    case GLUT_KEY_UP:
        varOry += 2;
        varOr2y += 2;
        break;
    case GLUT_KEY_DOWN:
        varOry -= 2;
        varOr2y -= 2;
        break;
    }
    glLoadIdentity();
    if(varOrx < 0)
    {
        varOrx  = 0;
        varOr2x = 0;
    }
    if(varOr2x > 420/2)
    {
        varOrx  = 420/2;
        varOr2x = 420/2;
    }
    if(varOry < 0)
    {
        varOry  = 0;
        varOr2y = 0;
    }
    if(varOr2y > 580/2)
    {
        varOry  = 580/2;
        varOr2y = 580/2;
    }
    myResize(win_data.Width,win_data.Height);
}
int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(420, 580);

	glutInitWindowPosition(100, 100);

	glutCreateWindow("Graphics Window");

	glutDisplayFunc(myDisplay2);

	glutReshapeFunc(myResize);

	glutKeyboardFunc( KeyboardCbk );

    glutSpecialFunc( SpecialKeyboardCbk );

	myInit();

	glutMainLoop();

	return 0;

}
