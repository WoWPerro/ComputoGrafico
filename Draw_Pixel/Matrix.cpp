#include "pch.h"
#include "Matrix.h"
#include <iostream>

Matrix::Matrix(unsigned rows, unsigned cols)
{
	this->rows = rows;
	this->cols = cols;
	mat.resize(rows);
	for (int i = 0; i < mat.size(); i++)
	{
		mat[i].resize(cols, 0);
	}
}

Matrix::Matrix(const Matrix& other) //Constructor de copia (Puede acceder a los datos privados)
{
	mat = other.mat;
	rows = other.getRows();
	cols = other.getCols();
}

unsigned Matrix::getRows() const
{
	return this->rows;
}

unsigned Matrix::getCols() const
{
	return this->cols;
}

float& Matrix::operator() (const unsigned& i, const unsigned& j)
{
	return (mat[i][j]);
}

Matrix::Matrix(Matrix& rhs)
{
	mat.resize(rhs.rows);
	for (unsigned i = 0; i < mat.size(); i++)
	{
		mat[i].resize(rhs.cols, 0);
	}

	for (unsigned i = 0; i < mat.size(); i++)
	{
		for (unsigned j = 0; j < mat[i].size(); j++)
		{
			mat[i][j] = rhs(i, j);
		}
	}
}

Matrix Matrix::operator+(Matrix& rhs)
{
	Matrix mat2(rhs.getRows(), rhs.getCols());

	for (unsigned i = 0; i < rhs.getRows(); i++)
	{
		for (unsigned j = 0; j < rhs.getCols(); j++)
		{
			mat2(i, j) = mat[i][j] + (rhs(i, j));
		}
	}
	return mat2;
}

Matrix Matrix::operator-(Matrix& rhs)
{
	Matrix mat2(rhs.getRows(), rhs.getCols());

	for (unsigned i = 0; i < rhs.getRows(); i++)
	{
		for (unsigned j = 0; j < rhs.getCols(); j++)
		{
			mat2(i, j) = mat[i][j] - (rhs(i, j) );
		}
	}
	return mat2;
}

Matrix Matrix::operator*(Matrix& rhs)
{
	Matrix mat2(0, 0);

	if (this->cols == rhs.getRows())
	{
		Matrix mat3(this->rows, rhs.getCols());

		for (unsigned i = 0; i < this->cols; i++)
		{		
			for (unsigned k = 0; k < rhs.getCols(); k++)
			{
				for (unsigned j = 0; j < rhs.getRows(); j++)
				{
					mat3(i, k) += mat[i][j] * (rhs(j, k)); 
				}
			}
		}
		return mat3;
	}
	else
	{
		return mat2;
	}
}

Matrix  Matrix::transpose()
{
	Matrix mat2(this->rows, this->cols);

	for (int i = 0; i < this->cols; i++)
	{
		for (int j = 0; j < this->rows; j++)
		{
			mat2(j, i) = mat[i][j];
		}
	}
	return mat2;
}

//Escalares=============================================================

Matrix Matrix::operator+(float& rhs)
{
	Matrix mat2(this->rows, this->cols);

	for (int i = 0; i < this->cols; i++)
	{
		for (int j = 0; j < this->rows; j++)
		{
			mat2(j, i) = mat[i][j] + rhs;
		}
	}
	return mat2;
}

Matrix Matrix::operator-(float& rhs)
{
	Matrix mat2(this->rows, this->cols);

	for (int i = 0; i < this->cols; i++)
	{
		for (int j = 0; j < this->rows; j++)
		{
			mat2(j, i) = mat[i][j] - rhs;
		}
	}
	return mat2;
}

Matrix Matrix::operator*(float& rhs)
{
	Matrix mat2(this->rows, this->cols);

	for (int i = 0; i < this->cols; i++)
	{
		for (int j = 0; j < this->rows; j++)
		{
			mat2(j, i) = mat[i][j] * rhs;
		}
	}
	return mat2;
}

Matrix Matrix::operator/(float& rhs)
{
	Matrix mat2(this->rows, this->cols);

	for (int i = 0; i < this->cols; i++)
	{
		for (int j = 0; j < this->rows; j++)
		{
			mat2(j, i) = mat[i][j] / rhs;
		}
	}
	return mat2;
}

Matrix& Matrix::operator=(Matrix other)
{
	if (&other == this) // Oye la matriz que me estás pasando soy yo?
	{
		return *this;
	}

	unsigned new_rows = other.getRows();
	unsigned new_cols = other.getCols();
	mat.resize(new_rows);
	for (unsigned i = 0; i < new_rows; i++)
	{
		mat[i].resize(new_cols);
	}
	for (unsigned i = 0; i < new_rows;i++)
	{
		for (unsigned j = 0; j < new_cols; j++)
		{
			mat[i][j] = other(i, j);
		}
	}
	rows = new_rows;
	cols = new_cols;
	return *this;
}

Vector2 Matrix::operator*(Vector2& v1)
{
	Vector2 v2(0, 0);	
	v2.SetVector2XM((v1.GetVector2X()*mat[0][0]) + (v1.GetVector2Y()*mat[0][1]) + (v1.GetVector2Z()*mat[0][2]));
	v2.SetVector2YM((v1.GetVector2X()*mat[1][0]) + (v1.GetVector2Y()*mat[1][1]) + (v1.GetVector2Z()*mat[1][2]));
	v2.SetVector2ZM((v1.GetVector2X()*mat[2][0]) + (v1.GetVector2Y()*mat[2][1]) + (v1.GetVector2Z()*mat[2][2]));
	return v2;
}

void Matrix::Print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << mat[i][j];
		}
		std::cout << std::endl;
	}
}

Matrix::~Matrix()
{
}
