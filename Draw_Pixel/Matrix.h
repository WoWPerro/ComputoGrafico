#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "Vector2.h"

class Matrix
{
private:
	std::vector< std::vector<float> > mat;
	unsigned rows;
	unsigned cols;

public:
	Matrix(unsigned rows, unsigned cols);
	Matrix(Matrix& rhs);
	Matrix(const Matrix& other); //Constructor de copia
	virtual ~Matrix();

	Matrix& operator=(Matrix rhs);
	Matrix operator+(Matrix& rhs);
	Matrix operator-(Matrix& rhs);
	Matrix operator*(Matrix& rhs);
	Matrix transpose();

	//Mult por escalar
	Matrix operator+(float& rhs);
	Matrix operator-(float& rhs);
	Matrix operator*(float& rhs);
	Matrix operator/(float& rhs);

	//Mult por vector
	Vector2 operator*(const Vector2& v1);
	float& operator() (const unsigned& i, const unsigned& j);

	unsigned getRows() const;
	unsigned getCols() const;
	
	void Print();
};

#endif MATRIX_H