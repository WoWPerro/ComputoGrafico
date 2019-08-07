#include "pch.h"
#include "Vector2.h"
#include "SDL.h"
#include <SDL.h>


Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

//GETS
float Vector2::GetVector2X()
{
	return this->x;
}

float Vector2::GetVector2Y()
{
	return this->y;
}

float Vector2::GetVector2Z()
{
	return this->z;
}

Vector2 Vector2::GetVector2()
{
	Vector2 temp;
	temp.x = this->x;
	temp.y = this->y;
	return temp;
}

//SETS
void Vector2::SetVector2XM(float x)
{
	this->x = x;
}

void Vector2::SetVector2YM(float y)
{
	this->y = y;
}

void Vector2::SetVector2ZM(float z)
{
	this->z = z;
}

void Vector2::SetVector2M(int x, int y)
{
	this->x = x;
	this->y = y;
}

//OPERACIONES
void Vector2::SumaVector2M(Vector2 V2)
{
	this->x += V2.x;
	this->y += V2.y;
}

void Vector2::SumaVector2M(float F2, float F3)
{
	this->x += F2;
	this->y += F3;
}

Vector2 Vector2::operator+ (Vector2 v1)
{
	Vector2 temp;
	temp.x = x + v1.x;
	temp.y = y + v1.y;
	return (temp);

}

Vector2 Vector2::operator= (Vector2 v1)
{
	Vector2 temp;
	temp.x = v1.x;
	temp.y = v1.y;
	return (temp);
}


Vector2 Vector2::operator * (Vector2 v1)
{
	Vector2 temp;
	temp.x = this->x;
	temp.y = this->y;
	temp.x * v1.x;
	temp.y * v1.y;
	return (temp);
}

Vector2 Vector2::operator * (float n)
{
	Vector2 temp;
	temp.x = this->x;
	temp.y = this->y;
	temp.x * n;
	temp.y * n;
	return (temp);
}

void Vector2::RestaVector2M(Vector2 V2)
{
	this->x -= V2.x;
	this->y -= V2.y;
}

void Vector2::RestaVector2M(float F2, float F3)
{
	this->x -= F2;
	this->y -= F3;
}

float Vector2::PointProductVector2(Vector2 V2)
{
	return ((this->x * V2.x) + (this->y * V2.y));
}

float Vector2::NormaVector2()
{
	return sqrtf(((this->x * this->x) + (this->y * this->y)));
}

void Vector2::CrossProductVector2(Vector2 V2)
{

}


//void Vector2::SetRenderer(SDL_Renderer *gRenderer)
//{
//	this->gRenderer = gRenderer;
//}

//void Vector2::DrawVector2()
//{
//	SDL_Rect point;
//	
//	point.x = this->x;
//	point.y = this->y;
//	point.w = 10;
//	point.h = 10;
//
//	SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 0);
//	SDL_RenderFillRect(gRenderer, &point);
//}

Vector2::~Vector2()
{
}
