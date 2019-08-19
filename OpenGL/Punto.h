#pragma once
#ifndef __PUNTO___H__
#define __PUNTO___H__
#include <iostream>
class Punto
{
public:
	/// constructor
	Punto(float x, float y, float r, float g, float b, float t, float negativo);
	Punto(float x, float y, float t);
	virtual ~Punto();

	float color[3];
	float posicion[2];
	float tamano;
};
#endif // PUNTO_H_INCLUDED

