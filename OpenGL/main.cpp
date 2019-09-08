/*
Integrantes:
David Herrera
Andres Contreras
*/
/* -------------------------------------------------------------------------
 * @brief Example on how to draw simple 2D shapes
 * @author Leonardo Flórez-Valencia (florez-l@javeriana.edu.co)
 * -------------------------------------------------------------------------
 * Compilation on linux:
 *
 * g++ -std=c++17 simple_2d_scene.cxx -lm -lGL -lGLU -lglut -o mySimple2DScene
 *
 * -------------------------------------------------------------------------
 */

#include <GL/glut.h>
#include <cmath>
#include <iostream>

// -------------------------------------------------------------------------
#define _PI 3.14159265359
#define _2PI 6.28318530718
#define _SQRT3 1.73205080757
#define _SQRT3_2 0.86602540378
#define _SQRT3_3 0.57735026919
#define _SQRT3_4 0.43301270189

#define COLOR_CARRO 0.3098, 0.3098, 0.8980
#define COLOR_LLANTA 0.1019, 0.0980, 0.0941
#define COLOR_NUBE 1, 1, 1
#define COLOR_PARED 0.9686, 0.8627, 0.3137
#define COLOR_TECHO 0.8627, 0.4941, 0.0666
#define COLOR_HOJAS 0.0392, 0.572, 0.0549
#define COLOR_ARBOL 0.4, 0.254, 0.0392

#define WORLD_MIN_X -24
#define WORLD_MIN_Y -16
#define WORLD_MAX_X 24
#define WORLD_MAX_Y 16

struct WindowData
{
	unsigned long Width, Height;
	double XMin, XMax, YMin, YMax;
};
WindowData win_data;

// -------------------------------------------------------------------------
void DrawCircle(GLenum mode, unsigned int samples)
{
	glBegin(mode);
	for (unsigned int i = 0; i < samples; ++i)
	{
		float t = _2PI * float(i) / float(samples);
		glVertex2f(std::cos(t), std::sin(t));
	} // end if
	glEnd();
}

// -------------------------------------------------------------------------
void DrawCloud(GLenum mode, unsigned int samples, float rn, float gn, float bn, float x, float y)
{
	glLoadIdentity();
	glTranslatef(x + 10, y + 13, 0);
	glColor3f(rn, gn, bn);
	glBegin(mode);
	for (unsigned int i = 0; i < samples; ++i)
	{
		float t = _2PI * float(i) / float(samples);
		glVertex2f(std::cos(t), std::sin(t));
	} // end if
	glEnd();
	glTranslatef(-1.5, 0, 0);
	glBegin(mode);
	for (unsigned int i = 0; i < samples; ++i)
	{
		float t = _2PI * float(i) / float(samples);
		glVertex2f(std::cos(t), std::sin(t));
	} // end if
	glEnd();
	glTranslatef(3, 0, 0);
	glBegin(mode);
	for (unsigned int i = 0; i < samples; ++i)
	{
		float t = _2PI * float(i) / float(samples);
		glVertex2f(std::cos(t), std::sin(t));
	} // end if
	glEnd();
}

// -------------------------------------------------------------------------
void DrawSquare(GLenum mode)
{
	glBegin(mode);
	{
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);
	}
	glEnd();
}
// -------------------------------------------------------------------------
void DrawCar(GLenum mode, unsigned int samples, float rc, float gc, float bc, float rll, float gll, float bll, float x, float y)
{
	glLoadIdentity();
	glScalef(0.5, 0.5, 1);
	glTranslatef(x + -10, y + 0, 0);
	glColor3f(rll, gll, bll);
	glBegin(mode);
	for (unsigned int i = 0; i < samples; ++i)
	{
		float t = _2PI * float(i) / float(samples);
		glVertex2f(std::cos(t), std::sin(t));
	} // end for
	glEnd();
	glTranslatef(-7.5, 0, 0);
	glBegin(mode);
	for (unsigned int i = 0; i < samples; ++i)
	{
		float t = _2PI * float(i) / float(samples);
		glVertex2f(std::cos(t), std::sin(t));
	} // end for
	glEnd();
	glTranslatef(8.5, 2, 0);
	glColor3f(rc, gc, bc);
	glBegin(mode);
	{
		glVertex2f(-1.5, -1);
		glVertex2f(-1.5, 1);
		glVertex2f(1.5, 1);
		glVertex2f(1.5, -1);
	}
	glEnd();
	glTranslatef(-5.5, 1, 0);
	glBegin(mode);
	{
		glVertex2f(-4.5, -2);
		glVertex2f(-4.5, 2);
		glVertex2f(4.5, 2);
		glVertex2f(4.5, -2);
	}
	glEnd();
}
// -------------------------------------------------------------------------
void DrawHouse(GLenum mode, float rc, float gc, float bc, float rt, float gt, float bt, float x, float y)
{
	glLoadIdentity();
	glScalef(1.8, 1.8, 1);
	glTranslatef(x + 5, y + 5, 0);
	glColor3f(rc, gc, bc);
	glBegin(mode);
	{
		glVertex2f(-0.5, -0.85);
		glVertex2f(-0.5, 0.85);
		glVertex2f(0.5, 0.85);
		glVertex2f(0.5, -0.85);
	}
	glEnd();
	glTranslatef(0, 1.2, 0);
	glColor3f(rt, gt, bt);
	glBegin(mode);
	{
		glVertex2f(-1, -_SQRT3_4);
		glVertex2f(1, -_SQRT3_4);
		glVertex2f(0, _SQRT3_4);
	}
	glEnd();
}
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
void DrawTree(GLenum mode, float ra, float ga, float ba, float rh, float gh, float bh, float x, float y)
{
	glLoadIdentity();
	glTranslatef(x + 10, y + 10, 0);
	glColor3f(ra, ga, ba);
	glBegin(mode);
	{
		glVertex2f(-0.5, -1.75);
		glVertex2f(-0.5, 1.75);
		glVertex2f(0.5, 1.75);
		glVertex2f(0.5, -1.75);
	}
	glEnd();
	/*glLoadIdentity();*/
	glColor3f(rh, gh, bh);
	glTranslatef(0, 2.10, 0);
	glBegin(mode);
	{
		glVertex2f(-1, -_SQRT3_4);
		glVertex2f(1, -_SQRT3_4);
		glVertex2f(0, _SQRT3_4);
	}
	glEnd();
	glTranslatef(0, 0.5, 0);
	glBegin(mode);
	{
		glVertex2f(-1, -_SQRT3_4);
		glVertex2f(1, -_SQRT3_4);
		glVertex2f(0, _SQRT3_4);
	}
	glEnd();
	glTranslatef(0, 0.5, 0);
	glBegin(mode);
	{
		glVertex2f(-1, -_SQRT3_4);
		glVertex2f(1, -_SQRT3_4);
		glVertex2f(0, _SQRT3_4);
	}
	glEnd();
}
// -------------------------------------------------------------------------
void DrawTriangle(GLenum mode)
{
	glBegin(mode);
	{
		glVertex2f(-0.5, -_SQRT3_4);
		glVertex2f(0.5, -_SQRT3_4);
		glVertex2f(0, _SQRT3_4);
	}
	glEnd();
}

// -------------------------------------------------------------------------
void DrawBase()
{
	glBegin(GL_LINES);
	{
		glColor3f(1, 0, 0);
		glVertex2f(WORLD_MIN_X, 0);
		glVertex2f(WORLD_MAX_X, 0);

		glColor3f(0, 1, 0);
		glVertex2f(0, WORLD_MIN_Y);
		glVertex2f(0, WORLD_MAX_Y);
	}
	glEnd();
}

// -------------------------------------------------------------------------
void Init()
{
	glClearColor(0.3137, 0.5960, 0.9686, 0.0);
}

// -------------------------------------------------------------------------
void ResizeCbk(int width, int height)
{
	win_data.Width = width;
	win_data.Height = (height > 0) ? height : 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluOrtho2D(WORLD_MIN_X, WORLD_MAX_X, WORLD_MIN_Y, WORLD_MAX_Y);
}

// -------------------------------------------------------------------------
void DisplayCbk()
{

	// Reset viewport and model matrix
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	float aspect1 = (float)win_data.Width / (float)win_data.Height;
	glOrtho(-aspect1, aspect1, -1, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1, 1, 1);

	for (int i = -24; i < 45; i += 15)
	{
		DrawCar(GL_POLYGON, 100, COLOR_CARRO, COLOR_LLANTA, i, -6);
	}

	for (int i = -30; i < 10; i += 2)
	{
		DrawTree(GL_POLYGON, COLOR_ARBOL, COLOR_HOJAS, i, -3);
	}
	for (int i = -24; i < 8; i += 4)
	{
		DrawHouse(GL_POLYGON, COLOR_PARED, COLOR_TECHO, i, -4);
	}

	for (int i = -28; i < 10; i += 8)
	{
		DrawCloud(GL_POLYGON, 100, COLOR_NUBE, i, 0);
	}

	// Finish
	glutSwapBuffers();
}

// -------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(5, 5);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("2D test!!!");
	glutDisplayFunc(DisplayCbk);
	glutReshapeFunc(ResizeCbk);
	Init();
	glutMainLoop();

	return (0);
}

// eof - mouse_click.cxx
