// Draw_Pixel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include <list>
#include <iostream>
#include "SDL.h"
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "Vector2.h"
#include "Matrix.h"
#include "Text.h"
#include "MatrizEscalamiento.h"
#include "MatrizRotacion.h"
#include "MatrizTranslacion.h"
#include <vector>
#include <math.h>

//Screen dimension constants
int SCREEN_WIDTH = 1920;  //Hacer variables y modificar con respecto a la entrada de los parámetros para pasarlo desde consola
int SCREEN_HEIGHT = 1080; 
	
//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Computo Grafico", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN_DESKTOP);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF); //Dibuja en blanco


			}
		}
	}

	return success;
}


void close()
{
	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;


	SDL_Quit();
}

void DrawText(float SX, float SY, float angle, float TX, float TY, Matrix T2)
{
	Text text(gRenderer, "arial.ttf", 25, "Matriz de transformacion", { 255, 0, 0, 255 });

	Text EscalamientoX(gRenderer, "arial.ttf", 12, std::to_string(SX), { 255, 0, 0, 255 });
	Text EscalamientoY(gRenderer, "arial.ttf", 12, std::to_string(SY), { 255, 0, 0, 255 });
	Text Angulo    (gRenderer, "arial.ttf", 12, std::to_string(angle), { 255, 0, 0, 255 });
	Text TranslacionX (gRenderer, "arial.ttf", 12, std::to_string(TX), { 255, 0, 0, 255 });
	Text TranslacionY (gRenderer, "arial.ttf", 12, std::to_string(TY), { 255, 0, 0, 255 });

	Text EscalamientoXT(gRenderer, "arial.ttf", 12, "SX", { 255, 255, 0, 255 });
	Text EscalamientoYT(gRenderer, "arial.ttf", 12, "SY", { 255, 255, 0, 255 });
	Text AnguloT(gRenderer, "arial.ttf", 12, "angle", { 255, 255, 0, 255 });
	Text TranslacionXT(gRenderer, "arial.ttf", 12, "TX", { 255, 255, 0, 255 });
	Text TranslacionYT(gRenderer, "arial.ttf", 12, "TY", { 255, 255, 0, 255 });

	Text Matriz00(gRenderer, "arial.ttf", 12, std::to_string(T2(0, 0)), { 255, 0, 0, 255 });
	Text Matriz01(gRenderer, "arial.ttf", 12, std::to_string(T2(0, 1)), { 255, 0, 0, 255 });
	Text Matriz02(gRenderer, "arial.ttf", 12, std::to_string(T2(0, 2)), { 255, 0, 0, 255 });
	Text Matriz10(gRenderer, "arial.ttf", 12, std::to_string(T2(1, 0)), { 255, 0, 0, 255 });
	Text Matriz11(gRenderer, "arial.ttf", 12, std::to_string(T2(1, 1)), { 255, 0, 0, 255 });
	Text Matriz12(gRenderer, "arial.ttf", 12, std::to_string(T2(1, 2)), { 255, 0, 0, 255 });
	Text Matriz20(gRenderer, "arial.ttf", 12, std::to_string(T2(2, 0)), { 255, 0, 0, 255 });
	Text Matriz21(gRenderer, "arial.ttf", 12, std::to_string(T2(2, 1)), { 255, 0, 0, 255 });
	Text Matriz22(gRenderer, "arial.ttf", 12, std::to_string(T2(2, 2)), { 255, 0, 0, 255 });

	SDL_Rect point;
	point.w = 300;
	point.h = 300;
	point.x = 0;
	point.y = 0;

	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(gRenderer, &point);

	text.Display(0, 0, gRenderer);
	EscalamientoX.Display(40, 50, gRenderer);
	EscalamientoY.Display(40, 70, gRenderer);
	Angulo.Display(120, 90, gRenderer);
	TranslacionX.Display(190, 50, gRenderer);
	TranslacionY.Display(190, 70, gRenderer);

	EscalamientoXT.Display(20, 50, gRenderer);
	EscalamientoYT.Display(20, 70, gRenderer);
	AnguloT.Display(80, 90, gRenderer);
	TranslacionXT.Display(170, 50, gRenderer);
	TranslacionYT.Display(170, 70, gRenderer);

	Matriz00.Display(10, 150, gRenderer);
	Matriz01.Display(80, 150, gRenderer);
	Matriz02.Display(150, 150, gRenderer);
	Matriz10.Display(10, 170, gRenderer);
	Matriz11.Display(80, 170, gRenderer);
	Matriz12.Display(150, 170, gRenderer);
	Matriz20.Display(10, 190, gRenderer);
	Matriz21.Display(80, 190, gRenderer);
	Matriz22.Display(150, 190, gRenderer);
}

void DrawPlano()
{
	//Clear screen
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer); //Hacer una cruz con una escala "Plano coordenado"

	SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);

	for (int i = SCREEN_HEIGHT / 2; i < SCREEN_HEIGHT; i += 5)
	{
		for (int j = 0; j < SCREEN_WIDTH; j += 1)
		{
			SDL_RenderDrawPoint(gRenderer, j, i);
		}
	}

	for (int i = SCREEN_HEIGHT / 2; i > 0; i -= 5)
	{
		for (int j = 0; j < SCREEN_WIDTH; j += 1)
		{
			SDL_RenderDrawPoint(gRenderer, j, i);
		}
	}

	for (int i = SCREEN_WIDTH / 2; i > 0; i -= 5)
	{
		for (int j = 0; j < SCREEN_HEIGHT; j += 1)
		{
			SDL_RenderDrawPoint(gRenderer, i, j);
		}
	}

	for (int i = SCREEN_WIDTH / 2; i < SCREEN_WIDTH; i += 5)
	{
		for (int j = 0; j < SCREEN_HEIGHT; j += 1)
		{
			SDL_RenderDrawPoint(gRenderer, i, j);
		}
	}

	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);

	for (int i = SCREEN_HEIGHT / 2; i < SCREEN_HEIGHT; i += 50)
	{
		for (int j = 0; j < SCREEN_WIDTH; j += 1)
		{
			SDL_RenderDrawPoint(gRenderer, j, i);
		}
	}

	for (int i = SCREEN_HEIGHT / 2; i > 0; i -= 50)
	{
		for (int j = 0; j < SCREEN_WIDTH; j += 1)
		{
			SDL_RenderDrawPoint(gRenderer, j, i);
		}
	}

	for (int i = SCREEN_WIDTH / 2; i > 0; i -= 50)
	{
		for (int j = 0; j < SCREEN_HEIGHT; j += 1)
		{
			SDL_RenderDrawPoint(gRenderer, i, j);
		}
	}

	for (int i = SCREEN_WIDTH / 2; i < SCREEN_WIDTH; i += 50)
	{
		for (int j = 0; j < SCREEN_HEIGHT; j += 1)
		{
			SDL_RenderDrawPoint(gRenderer, i, j);
		}
	}

	//Draw vertical line of yellow dots
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	for (int i = 0; i < SCREEN_HEIGHT; i += 1)
	{
		SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
	}

	for (int i = 0; i < SCREEN_WIDTH; i += 1)
	{
		SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT / 2);
	}

	//Update screen
	//SDL_RenderPresent(gRenderer);
}

void DrawVector(Vector2 *v1)
{
	SDL_Rect point;

	point.w = 10;
	point.h = 10;
	point.x = ((50 * v1->GetVector2X() - (point.w / 2)) + SCREEN_WIDTH / 2);
	point.y = (-(50 * v1->GetVector2Y() + (point.h / 2)) + SCREEN_HEIGHT / 2);

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(gRenderer, &point);
	//SDL_RenderPresent(gRenderer);
}

void DrawVector(Vector2 v1)
{
	SDL_Rect point;

	point.w = 10;
	point.h = 10;
	point.x = ((50 * v1.GetVector2X() - (point.w / 2)) + SCREEN_WIDTH / 2);
	point.y = (-(50 * v1.GetVector2Y() + (point.h / 2)) + SCREEN_HEIGHT / 2);

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(gRenderer, &point);
	//SDL_RenderPresent(gRenderer);
}

void DrawVectores(std::list <Vector2> Vectores)	
{
	for (std::list<Vector2>::iterator it = Vectores.begin(); it != Vectores.end(); ++it)
	{
		DrawVector(*it);
	}
}

std::list <Vector2> MultiplyVectores(std::list <Vector2> Vectores, Matrix T)
{
	std::list <Vector2> Vectores2;
	for (std::list<Vector2>::iterator it = Vectores.begin(); it != Vectores.end(); ++it)
	{
		Vectores2.push_back (T * *it);
	}
	return Vectores2;
}

void DrawMatrix(Matrix m1)
{
	if ((m1.getCols() == 2 && m1.getRows() == 1))
	{
		SDL_Rect point;

		point.w = 10;
		point.h = 10;
		point.x = ((50 * m1(0, 0) - (point.w / 2)) + SCREEN_WIDTH / 2);
		point.y = (-(50 * m1(0, 1) + (point.h / 2)) + SCREEN_HEIGHT / 2);

		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderFillRect(gRenderer, &point);
		//SDL_RenderPresent(gRenderer);
	}

}

bool Buttonclick(SDL_Rect point, int x, int y)
{
	if (x > point.x && x < point.x + point.w)
	{
		if (y > point.y && y < point.y + point.h)
		{
			return true;
		}
	}
	return false;
}

void DrawLine(float x1, float y1, float x2, float y2)
{
	x1 = ((50 * x1) + (SCREEN_WIDTH / 2));
	x2 = ((50 * x2) + (SCREEN_WIDTH / 2));
	y1 = (-(50 * y1) + (SCREEN_HEIGHT / 2));
	y2 = (-(50 * y2) + (SCREEN_HEIGHT / 2));

	float y = y1;
	float x = x1;
	float i1 = 0;
	float j1 = 0;

	if (x1 < x2)
	{
		x = x1;
		i1 = x2;
	}
	else
	{
		x = x2;
		i1 = x1;
	}

	if (y1 < y2)
	{
		y = y1;
		j1 = y2;
	}
	else
	{
		y = y2;
		j1 = y1;
	}

	float m = 0;
	float c = 0;
	m = ((y2 - y1) / (x2 - x1));
	c = y1 - (m * x1);
	if (m < 1)
	{
		//std::cout << "----------------------" << std::endl;
		//for (x1; x1<x2;x1++)

		//for (int i = -50; i < 50; i++)
		//{
			int i = x;
			int j = y;
			while (i <= i1 && j <= j1)
			{

			
			x = (y - c)/m;
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0xEC, 0xFF);
			SDL_RenderDrawPoint(gRenderer, x, y);
			y--;
			i = x;
			j = y;
			}
	}
	else if (m > 1)
	{
		int i = x;
		int j = y;
		//for (int i = -50; i < 50; i++)
		while (i <= i1 && j >= j1)
		{
			y = m * x + c;
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0xEC, 0xFF);
			SDL_RenderDrawPoint(gRenderer, x, y);
			x--;
			i = x;
			j = y;
		}
	}
}

void DrawLine2(float x1, float y1, float x2, float y2)
{
	x1 = ((50 * x1) + (SCREEN_WIDTH / 2));
	x2 = ((50 * x2) + (SCREEN_WIDTH / 2));
	y1 = (-(50 * y1) + (SCREEN_HEIGHT / 2));
	y2 = (-(50 * y2) + (SCREEN_HEIGHT / 2));
	float dx = 0;
	float dy = 0;
	float denominador = 1;
	double xincr = 0;
	double yincr = 0;
	float x = 0;
	float y = 0;
	dx = x2 - x1;
	dy = y2 - y1;
	if (abs(dy) < abs(dx))
	{
		denominador = abs(dx);
	}
	else if (abs(dy) >= abs(dx))
	{
		denominador = abs(dy);
	}
	xincr = (dx / denominador);
	yincr = (dy / denominador);
	x = x1;
	y = y1;
	for (int i = 0; i <= denominador; i++)
	{
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0xEC, 0xFF);
		SDL_RenderDrawPoint(gRenderer, x, y);
		x = x + xincr;
		y = y + yincr;
	}
}

void DrawBresenham(int x, int y, int dx, int dy, int incrX, int incrY)
{
	//Bresenham algorithm
	int i = 0;
	int p = (2 * dy) - dx;
	if (dx > dy) //Pendiente
	{
		while (i < dx)
		{
			SDL_RenderDrawPoint(gRenderer, x, y);
			x += incrX;
			if (p < 0)
			{
				p = p + (2 * dy);
			}
			else
			{
				y += incrY;
				p = p + (2 * (dy - dx));
			}
			std::cout << "P [" << p << "] dx[" << dx << "] dy[" << dy << "]" << std::endl;
			i++;
		}
	}
	else
	{
		while (i < dy)
		{
			SDL_RenderDrawPoint(gRenderer, x, y);
			y += incrY;
			if (p < 0)
			{
				p = p + (2 * dx);
			}
			else
			{
				x += incrX;
				p = p + (2 * (dx - dy));
			}
			i++;
		}
	}
}

void DrawLine3(int x1, int y1, int x2, int y2)
{
	//Bresenham algorithm
	x1 = (x1 * 50) + (SCREEN_WIDTH / 2);
	x2 = (x2 * 50) + (SCREEN_WIDTH / 2);
	y1 = (-y1 * 50) + (SCREEN_HEIGHT / 2);
	y2 = (-y2 * 50) + (SCREEN_HEIGHT / 2);
	int dx = x2 - x1;
	int dy = y2 - y1;
	int x = x1;
	int y = y1;
	
	//int p = (2*dy) - dx;
	
	if (dx < 0)
	{
		if (dy < 0)
		{
			DrawBresenham(x, y, abs(dx), abs(dy), -1, -1);
		}
		else if (dy > 0)
		{
			DrawBresenham(x, y, abs(dx), abs(dy), -1, 1);
		}
	}
	else if (dx > 0)
	{
		if (dy < 0)
		{
			DrawBresenham(x, y, abs(dx), abs(dy), 1, -1);
		}
		else if (dy > 0)
		{
			DrawBresenham(x, y, abs(dx), abs(dy), 1, 1);
		}
	}
}

void DrawCircle(float xc, float yc, float r)
{
	xc = (50 * xc) + (SCREEN_WIDTH / 2);
	yc = (-50 * yc) + (SCREEN_HEIGHT / 2);
	r = r * 50;
	float p = 1- r;
	float x = 0;
	float y = r;

	do{
		//Aprovechar simetría del círculo
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x40, 0xFF);
		SDL_RenderDrawPoint(gRenderer, x + xc, y + yc);
		SDL_RenderDrawPoint(gRenderer, x + xc, -y + yc);
		SDL_RenderDrawPoint(gRenderer, -x + xc, y + yc);
		SDL_RenderDrawPoint(gRenderer, -x + xc, -y + yc);
		SDL_RenderDrawPoint(gRenderer, y + xc, x + yc);
		SDL_RenderDrawPoint(gRenderer, y + xc, -x + yc);
		SDL_RenderDrawPoint(gRenderer, -y + xc, x + yc);
		SDL_RenderDrawPoint(gRenderer, -y + xc, -x + yc);
		if (p <= 0)
		{
			x++;
			p = p + (2 * x) + 3;
		}
		else if (p > 0)
		{
			x++;
			y = y - 1;
			p = (2 * x) - (2 * y) + 5 + p;
		}
	} while (x <= y);
	
}

void DrawBezierLine3(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	x1 += SCREEN_WIDTH / 2;
	x2 += SCREEN_WIDTH / 2;
	x3 += SCREEN_WIDTH / 2;
	x4 += SCREEN_WIDTH / 2;
	y1 = -y1 + SCREEN_HEIGHT / 2;
	y2 = -y2 + SCREEN_HEIGHT / 2;
	y3 = -y3 + SCREEN_HEIGHT / 2;
	y4 = -y4 + SCREEN_HEIGHT / 2;
	float x = 0;
	float y = 0;
	for (float i = 0; i < 1; i = i + 0.0001)
	{
		x = ((1 - i)*(1 - i)*(1 - i)*(x1)) + (3 * i*(1 - i)*(1 - i)*(x2)) + (3 * i*i*(1 - i)*(x3)) + (i*i*i*(x4));
		y = ((1 - i)*(1 - i)*(1 - i)*(y1)) + (3 * i*(1 - i)*(1 - i)*(y2)) + (3 * i*i*(1 - i)*(y3)) + (i*i*i*(y4));
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x40, 0xFF);
		SDL_RenderDrawPoint(gRenderer, x, y);
	}
}

void DrawBezierLine6(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float x5, float y5, float x6, float y6, float x7, float y7)
{
	x1 = (x1 * 50) + SCREEN_WIDTH / 2;
	x2 = (x2 * 50) + SCREEN_WIDTH / 2;
	x3 = (x3 * 50) + SCREEN_WIDTH / 2;
	x4 = (x4 * 50) + SCREEN_WIDTH / 2;
	x5 = (x5 * 50) + SCREEN_WIDTH / 2;
	x6 = (x6 * 50) + SCREEN_WIDTH / 2;
	x7 = (x7 * 50) + SCREEN_WIDTH / 2;
	y1 = (-y1* 50) + SCREEN_HEIGHT / 2;
	y2 = (-y2* 50) + SCREEN_HEIGHT / 2;
	y3 = (-y3* 50) + SCREEN_HEIGHT / 2;
	y4 = (-y4* 50) + SCREEN_HEIGHT / 2;
	y5 = (-y5* 50) + SCREEN_HEIGHT / 2;
	y6 = (-y6* 50) + SCREEN_HEIGHT / 2;
	y7 = (-y7* 50) + SCREEN_HEIGHT / 2;

	float x = 0;
	float y = 0;
	for (float i = 0; i < 1; i = i + 0.0001)
	{
		x = ((1 - i)*(1 - i)*(1 - i)*(x1)) + (3 * i*(1 - i)*(1 - i)*(x2)) + (3 * i*i*(1 - i)*(x3)) + (i*i*i*(x4));
		y = ((1 - i)*(1 - i)*(1 - i)*(y1)) + (3 * i*(1 - i)*(1 - i)*(y2)) + (3 * i*i*(1 - i)*(y3)) + (i*i*i*(y4));

		x = (pow((1 - i),6)*(x1)) + (6 * i* pow((1 - i),5)*(x2)) + (15 * pow (i,2) * pow((1 - i), 4)*(x3)) + (20 * pow(i, 3) * pow((1 - i), 3)*(x4)) + (15 * pow(i, 4) * pow((1 - i), 2)*(x5)) + (6 * pow(i, 5) * pow((1 - i), 1)*(x6)) + (pow(i, 6) *(x7));
		y = (pow((1 - i),6)*(y1)) + (6 * i* pow((1 - i),5)*(y2)) + (15 * pow(i, 2) * pow((1 - i), 4)*(y3)) + (20 * pow(i, 3) * pow((1 - i), 3)*(y4)) + (15 * pow(i, 4) * pow((1 - i), 2)*(y5)) + (6 * pow(i, 5) * pow((1 - i), 1)*(y6)) + (pow(i, 6) *(y7));
		
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x40, 0xFF);
		SDL_RenderDrawPoint(gRenderer, x, y);
	}

}

unsigned long fact(unsigned long n)
{
	if (n == 1)
	{
		return 1;
	}
	
	if (n == 0)
	{
		return 1;
	}

	if (n != 0)
	{
		unsigned int counter = n - 1;
		while (counter > 0)
		{
			n = n * counter;
			counter--;
		}
		return n;
	}
}

long Factorial(long n)
{
	if (n <= 1) {
		return 1;
	}
	else {
		return n * Factorial(n - 1);
	}
}

int Pascal(int x, int y)
{
	return (fact(x)) / (fact(y))*(fact(x - y));
}

void DrawBezierN(std::list<Vector2> Vectores)
{
	std::list<Vector2>::iterator it2 = Vectores.begin();
	float n = (Vectores.size());		int counter = 0;
	float i = 0;
	float j = 0;

		for (float t = 0; t <= 1; t += .0001)
		{
			float k = 0;

				i = 0;
				j = 0;
				
			for (std::list<Vector2>::iterator it = Vectores.begin(); it != Vectores.end(); ++it)
			{
					
				if (k <= n)
				{
					k++;
				}
					
				long factor1 = (Factorial(n - k));
				long factor2 = (Factorial(k));
				float b = ((Factorial(n)) / (factor2 * factor1));
				i = (i + ((it->GetVector2X()) * b * pow(t, k) * pow(1 - t, n - k)));
				j = (j + ((it->GetVector2Y()) * b * pow(t, k) * pow(1 - t, n - k)));

				DrawVector(*it);	
			}
			SDL_RenderDrawPoint(gRenderer, ((i * 50) + SCREEN_WIDTH / 2), ((-j * 50) + SCREEN_HEIGHT / 2));
		}		
}

void drawLines(std::list<Vector2> Vectores)
{
	for (std::list<Vector2>::iterator it = Vectores.begin(); it != Vectores.end(); ++it)
	{
		DrawVector(*it);
		if (std::next(it, 1) != Vectores.end())
		{
			DrawLine2(it->GetVector2X(), it->GetVector2Y(), std::next(it, 1)->GetVector2X(), std::next(it, 1)->GetVector2Y());
		}
		
	}
}

void drawCircles(std::list<Vector2> Vectores, float r)
{
	for (std::list<Vector2>::iterator it = Vectores.begin(); it != Vectores.end(); ++it)
	{
		DrawVector(*it);
		DrawCircle(it->GetVector2X(), it->GetVector2Y(), r);		
	}
}

void DrawEstrellaExam()
{
	DrawCircle(0, 0, 2);
	DrawLine2(-1.88, 0.5, 1.94, .5);
	DrawLine2(1.94, .5, -1, -1.74);
	DrawLine2(-1, -1.74, 0, 2.04);
	DrawLine2(0, 2.04, 0.96, -1.7);
	DrawLine2(0.96, -1.7, -1.88, 0.5);
}

void DrawTriangleExam()
{
	DrawVector(Vector2(2.8, 0));
	DrawVector(Vector2(1.4, 4.2));
	DrawVector(Vector2(-5.6, 0));

	DrawLine2(2.8, 0, 1.4, 4.2);
	DrawLine2(1.4, 4.2,-5.6, 0);
	DrawLine2(-5.6, 0, 2.8, 0);
}

void EmptyVectores(std::list <Vector2> &Vectores)
{
	Vectores.empty();
}

void DrawInstructions()
{
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	Text Instrucciones(gRenderer, "arial.ttf", 25, "Presiona ESC para salir", { 255, 0, 0, 255 });
	Text Instrucciones1(gRenderer, "arial.ttf", 25, "[1]/[5] Activa/Desactiva Matriz", { 255, 0, 0, 255 });
	Text Instrucciones2(gRenderer, "arial.ttf", 25, "[2]/[6] Activa/Desactiva Matriz", { 255, 0, 0, 255 });
	Text Instrucciones3(gRenderer, "arial.ttf", 25, "[3]/[7] Activa/Desactiva Matriz", { 255, 0, 0, 255 });
	Text Instrucciones4(gRenderer, "arial.ttf", 25, "[4]/[8] Activa/Desactiva Matriz", { 255, 0, 0, 255 });
	Instrucciones.Display(0, 0, gRenderer);
	Instrucciones1.Display(0, 0, gRenderer);
	Instrucciones2.Display(0, 0, gRenderer);
	Instrucciones3.Display(0, 0, gRenderer);
	Instrucciones4.Display(0, 0, gRenderer);
}

int main(int argc, char* args[])
{
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	int mouseX = 0;
	int mouseY = 0;
	std::list <Vector2> Vectores;
	bool leftclick = false;
	float SX = 1;
	float SY = 1;
	float angle = 1;
	float TX = 1;
	float TY = 1;
	bool Menu = false;
	std::string State = "Null";
	bool button1 = false;
	bool button2 = false;
	bool button3 = false;
	bool button4 = false;
	bool matrix = false;
	short counterM = 0;
	bool lines = false;
	short counterL = 0;
	bool circles = false;
	short counterC = 0;
	bool curvas = false;
	short counterCu = 0;
	bool NotUsedButton1 = false;
	bool NotUsedButton2 = false;
	bool NotUsedButton3 = false;
	bool NotUsedButton4 = false;
	bool NotUsedButton5 = false;
	bool NotUsedButton6 = false;
	bool NotUsedButton7 = false;
	bool NotUsedButton8 = false;

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}

				if (e.type == SDL_MOUSEMOTION)
				{
					//Get the mouse offsets
					mouseX = e.motion.x;
					mouseY = e.motion.y;
				}

				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					SDL_MouseButtonEvent& b = e.button;
					if (b.button == SDL_BUTTON_LEFT)
					{
						leftclick = true;
						/*std::cout << mouseX << "  ";
						std::cout << mouseY << std::endl;*/
						double x = (((mouseX)-(SCREEN_WIDTH / 2.)) / 50.);
						double y = -(((mouseY)-(SCREEN_HEIGHT / 2.)) / 50.);

						if (!Menu && !button1 || !Menu)
						{
							std::list <Vector2>::iterator itv;
							Vector2 *V1 = new Vector2(x, y);
							Vectores.push_back(*V1);
						}
						
					}
				}
				if (e.type == SDL_MOUSEBUTTONUP)
				{
					SDL_MouseButtonEvent& b = e.button;
					if (b.button == SDL_BUTTON_LEFT)
					{
						leftclick = false;
					}
				}

				if (e.type = SDL_KEYDOWN)
				{
					if (e.key.keysym.sym == SDLK_1)
					{
						if (!NotUsedButton1)
						{
							button1 = true;
						}
						NotUsedButton1 = true;
					}

					if (e.key.keysym.sym == SDLK_2)
					{
						if (!NotUsedButton2)
						{
							button2 = true;
						}
						NotUsedButton2 = true;
					}

					if (e.key.keysym.sym == SDLK_3)
					{
						if (!NotUsedButton3)
						{
							button3 = true;
						}
						NotUsedButton3 = true;
					}

					if (e.key.keysym.sym == SDLK_4)
					{
						if (!NotUsedButton4)
						{
							button4 = true;
						}
						NotUsedButton4 = true;
					}
					
					if (e.key.keysym.sym == SDLK_5)
					{
						if (!NotUsedButton5)
						{
							button1 = false;
						}
						NotUsedButton5 = true;
					}

					if (e.key.keysym.sym == SDLK_6)
					{
						if (!NotUsedButton6)
						{
							button2 = false;
						}
						NotUsedButton6 = true;
					}

					if (e.key.keysym.sym == SDLK_7)
					{
						if (!NotUsedButton7)
						{
							button3 = false;
						}
						NotUsedButton7 = true;
					}

					if (e.key.keysym.sym == SDLK_8)
					{
						if (!NotUsedButton8)
						{
							button4 = false;
						}
						NotUsedButton8 = true;
					}

					if (e.key.keysym.sym == SDLK_ESCAPE)
					{
						quit = true;
					}
				}
				
				if (e.type = SDL_KEYUP)
				{
					if (e.key.keysym.sym == SDLK_1)
					{
						NotUsedButton1 = false;
					}

					if (e.key.keysym.sym == SDLK_2)
					{
						NotUsedButton2 = false;
					}

					if (e.key.keysym.sym == SDLK_3)
					{
						NotUsedButton3 = false;
					}

					if (e.key.keysym.sym == SDLK_4)
					{
						NotUsedButton4 = false;
					}
					if (e.key.keysym.sym == SDLK_5)
					{
						NotUsedButton5 = false;
					}

					if (e.key.keysym.sym == SDLK_6)
					{
						NotUsedButton6 = false;
					}

					if (e.key.keysym.sym == SDLK_7)
					{
						NotUsedButton7 = false;
					}

					if (e.key.keysym.sym == SDLK_8	)
					{
						NotUsedButton8 = false;
					}
				}

				if (button1)
				{
					matrix = true;
				}
				else
				{
					matrix = false;
				}

				if (button2)
				{
					lines = true;
				}
				else
				{
					lines = false;
				}

				if (button3)
				{
					circles = true;
				}
				else
				{
					circles = false;
				}

				if (button4)
				{
					curvas = true;						
				}
				else
				{
					curvas = false;
				}
			}



			//PRUEBAS
			//DRAW
			DrawPlano();

			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_Rect point;
			point.w = 420;
			point.h = 300;
			point.x = 0;
			point.y = SCREEN_HEIGHT - 100;
			SDL_RenderFillRect(gRenderer, &point);

			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
			Text Instrucciones(gRenderer, "arial.ttf", 25, "Presiona ESC para salir", { 255, 0, 0, 255 });
			Text Instrucciones1(gRenderer, "arial.ttf", 25, "[1]/[5] Activa/Desactiva Matriz", { 255, 0, 0, 255 });
			Text Instrucciones2(gRenderer, "arial.ttf", 25, "[2]/[6] Activa/Desactiva Lineas", { 255, 0, 0, 255 });
			Text Instrucciones3(gRenderer, "arial.ttf", 25, "[3]/[7] Activa/Desactiva Circulos", { 255, 0, 0, 255 });
			Text Instrucciones4(gRenderer, "arial.ttf", 25, "[4]/[8] Activa/Desactiva Curvas Bezier", { 255, 0, 0, 255 });
			Instrucciones.Display(SCREEN_WIDTH - 300, 0, gRenderer);
			Instrucciones1.Display(0, SCREEN_HEIGHT - 100, gRenderer);
			Instrucciones2.Display(0, SCREEN_HEIGHT - 75, gRenderer);
			Instrucciones3.Display(0, SCREEN_HEIGHT - 50, gRenderer);
			Instrucciones4.Display(0, SCREEN_HEIGHT - 25, gRenderer);
			

			if (lines)
			{
				//DrawLine(1, 1, 3, 2);

				drawLines(Vectores);

				//DrawLine(0,0,-7,5);
				//DrawLine(0,0,-7,5);
				//DrawLine2(0,0,7,6);

				//DrawLine3(-2, -1, 3, -4);

				//DrawLine3(0,0,-2,2);
				//DrawLine3(1, 1, 0, 0);
				//DrawTriangleExam();
			}

			if (circles)
			{
				drawCircles(Vectores, 1);
				//DrawEstrellaExam();
			}

			if (curvas)
			{
				//DrawBezierLine3(0, 0, 200, 300, -100, 300, 100, 0);
				DrawBezierN(Vectores);
				//DrawBezierLine6(0, 0, 1, 1, 1, -1, 2, 0, 3, 1, 4, 0, 5, -1);
			}

			if (matrix)
			{
				MatrizEscalamiento MS(SX, SY);
				//MS.Print();

				MatrizRotacion MR(angle);
				//MR.Print();

				MatrizTranslacion MT(TX, TY);
				//MT.Print();

				Matrix T1(3, 3);
				T1 = (MR * MS);
				//T1.Print();

				Matrix T2(3, 3);
				T2 = (T1 * MT);
				//T2.Print();

				DrawVectores(Vectores);

				SDL_Rect point1;
				point1.w = 10;
				point1.h = 10;
				point1.x = 5;
				point1.y = 50;
				if (Buttonclick(point1, mouseX, mouseY) && leftclick)
				{
					SX -= .1f;
				}

				SDL_Rect point2;
				point2.w = 10;
				point2.h = 10;
				point2.x = 5;
				point2.y = 70;
				if (Buttonclick(point2, mouseX, mouseY) && leftclick)
				{
					SY -= .1f;
				}

				SDL_Rect point3;
				point3.w = 10;
				point3.h = 10;
				point3.x = 65;
				point3.y = 90;
				if (Buttonclick(point3, mouseX, mouseY) && leftclick)
				{
					angle -= 1.f;
				}

				SDL_Rect point4;
				point4.w = 10;
				point4.h = 10;
				point4.x = 155;
				point4.y = 50;
				if (Buttonclick(point4, mouseX, mouseY) && leftclick)
				{
					TX -= .1f;
				}

				SDL_Rect point5;
				point5.w = 10;
				point5.h = 10;
				point5.x = 155;
				point5.y = 70;
				if (Buttonclick(point5, mouseX, mouseY) && leftclick)
				{
					TY -= .1f;
				}

				SDL_Rect point6;
				point6.w = 10;
				point6.h = 10;
				point6.x = 95;
				point6.y = 50;
				if (Buttonclick(point6, mouseX, mouseY) && leftclick)
				{
					SX += .1f;
				}

				SDL_Rect point7;
				point7.w = 10;
				point7.h = 10;
				point7.x = 95;
				point7.y = 70;
				if (Buttonclick(point7, mouseX, mouseY) && leftclick)
				{
					SY += .1f;
				}

				SDL_Rect point8;
				point8.w = 10;
				point8.h = 10;
				point8.x = 175;
				point8.y = 90;
				if (Buttonclick(point8, mouseX, mouseY) && leftclick)
				{
					angle += 1.f;
				}

				SDL_Rect point9;
				point9.w = 10;
				point9.h = 10;
				point9.x = 245;
				point9.y = 50;
				if (Buttonclick(point9, mouseX, mouseY) && leftclick)
				{
					TX += .1f;
				}

				SDL_Rect point10;
				point10.w = 10;
				point10.h = 10;
				point10.x = 245;
				point10.y = 70;
				if (Buttonclick(point10, mouseX, mouseY) && leftclick)
				{
					TY += .1f;
				}

				SDL_Rect apply;
				apply.w = 50;
				apply.h = 50;
				apply.x = 230;
				apply.y = 230;
				if (Buttonclick(apply, mouseX, mouseY) && leftclick)
				{
					std::list <Vector2> Vectoresmodificados = MultiplyVectores(Vectores, T2);
					Vectores.clear();

					for (std::list<Vector2>::iterator it = Vectoresmodificados.begin(); it != Vectoresmodificados.end(); ++it)
					{
						Vectores.push_back(*it);
					}
					Vectoresmodificados.clear();
				}

				SDL_Rect erase;
				erase.w = 50;
				erase.h = 50;
				erase.x = 100;
				erase.y = 230;
				if (Buttonclick(erase, mouseX, mouseY) && leftclick)
				{
					Vectores.clear();
				}


				SDL_Rect background;
				background.w = 300;
				background.h = 300;
				background.x = 0;
				background.y = 0;
				if (Buttonclick(background, mouseX, mouseY))
				{
					//std::cout << "You clicked on Menu" << std::endl;
					Menu = true;
				}
				else
				{
					Menu = false;
				}

				DrawText(SX, SY, angle, TX, TY, T2);
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderFillRect(gRenderer, &point1);
				SDL_RenderFillRect(gRenderer, &point2);
				SDL_RenderFillRect(gRenderer, &point3);
				SDL_RenderFillRect(gRenderer, &point4);
				SDL_RenderFillRect(gRenderer, &point5);
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x10, 0xFF, 0xFF);
				SDL_RenderFillRect(gRenderer, &point6);
				SDL_RenderFillRect(gRenderer, &point7);
				SDL_RenderFillRect(gRenderer, &point8);
				SDL_RenderFillRect(gRenderer, &point9);
				SDL_RenderFillRect(gRenderer, &point10);
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderFillRect(gRenderer, &apply);
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xA5, 0x00, 0xFF);
				SDL_RenderFillRect(gRenderer, &erase);
			}
			
			
			
			SDL_RenderPresent(gRenderer);
		}

	}

	//Free resources and close SDL
	close();

	return 0;
}