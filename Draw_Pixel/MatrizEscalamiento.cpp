#include "pch.h"
#include "MatrizEscalamiento.h"

MatrizEscalamiento::MatrizEscalamiento(float sx, float sy)
{
	mat[0][0] = sx;
	mat[1][1] = sy;
	mat[2][2] = 1;
}


MatrizEscalamiento::~MatrizEscalamiento()
{
}
