#include "pch.h"
#include "Vector2.h"


Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2 Vector2::GetVector2()
{
	return Vector2(1, 1); //Quitar esto
}

void Vector2::SetVector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2 Vector2::SumaVector2(Vector2 V1, Vector2 V2)
{
	V1.x + V2.x;
	V1.y + V2.y;
	return Vector2(1, 1); //Quitar esto
}

Vector2::~Vector2()
{
}
