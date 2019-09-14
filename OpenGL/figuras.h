#include <GL/glut.h>
#include <cmath>
#include <iostream>

// -------------------------------------------------------------------------
#define _PI      3.1415926535897932
#define _2PI     6.28318530718


// -------------------------------------------------------------------------
void DrawCircle( GLenum mode, unsigned int samples );

// -------------------------------------------------------------------------
void DrawEllipse( GLenum mode, unsigned int samples,int rx,int ry, float r, float g, float b);

// -------------------------------------------------------------------------
void DrawUnitaryCube(GLenum mode, float r, float g, float b );

// -------------------------------------------------------------------------
void DrawUnitaryPyramid( GLenum mode, float r, float g, float b );

// -------------------------------------------------------------------------
void DrawUnitaryOctahedron( GLenum mode, float r, float g, float b );

// -------------------------------------------------------------------------
void DrawUnitaryTetrahedron( GLenum mode, float r, float g, float b );
