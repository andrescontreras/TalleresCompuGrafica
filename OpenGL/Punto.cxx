#pragma once
#include "Punto.h"
Punto::Punto(float x, float y, float r, float g, float b, float t, float negativo)
{
	tamano = t;

	color[0] = abs(((1.0f / 255) *r) -negativo);
	color[1] = abs(((1.0f / 255) *g)-negativo);
	color[2] = abs(((1.0f / 255) *b)-negativo);
	posicion[0] = x * 20;
	posicion[1] = y * 20;
}
Punto::Punto(float x, float y, float t)
{
	tamano = t;
	posicion[0] = x * 20;
	posicion[1] = y * 20;
}
Punto::~Punto()
{

}


