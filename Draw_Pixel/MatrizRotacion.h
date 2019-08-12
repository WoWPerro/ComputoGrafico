#pragma once
#include "Matrix.h"
#include <math.h>

class MatrizRotacion : public Matrix
{
public:
	MatrizRotacion(float angle);
	~MatrizRotacion();
};

