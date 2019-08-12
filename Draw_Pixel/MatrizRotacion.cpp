#include "pch.h"
#include "MatrizRotacion.h"


MatrizRotacion::MatrizRotacion(float angle)
{
	mat[0][0] = cos(angle *	57.2958);
	mat[0][1] = -sin(angle *	57.2958);
	mat[1][0] = sin(angle *	57.2958);
	mat[1][1] = cos(angle *	57.2958);
	mat[2][2] = 1;
}


MatrizRotacion::~MatrizRotacion()
{
}
