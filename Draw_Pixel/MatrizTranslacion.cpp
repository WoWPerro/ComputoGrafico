#include "pch.h"
#include "MatrizTranslacion.h"


MatrizTranslacion::MatrizTranslacion(float Tx, float Ty)
{
	mat[0][0] = 1;
	mat[1][1] = 1;
	mat[2][2] = 1;
	mat[0][2] = Tx;
	mat[1][2] = Ty;
}


MatrizTranslacion::~MatrizTranslacion()
{
}
