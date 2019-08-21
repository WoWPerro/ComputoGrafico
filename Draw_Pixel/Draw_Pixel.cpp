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

//Screen dimension constants
int SCREEN_WIDTH = 1280;  //Hacer variables y modificar con respecto a la entrada de los parámetros para pasarlo desde consola
int SCREEN_HEIGHT = 720; 
	

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
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
	float m = 0;
	float c = 0;
	m = ((y2 - y1) / (x2 - x1));
	c = y1 - (m * x1);
	if (m < 1)
	{
		//std::cout << "----------------------" << std::endl;
		//for (x1; x1<x2;x1++)
		for (int i = -50; i < 50; i++)
		{
			x = (y - c)/m;
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0xEC, 0xFF);
			SDL_RenderDrawPoint(gRenderer, x, y);
			//std::cout << x << ":" << y << std::endl;
			y--;
			/*if (y > y2)
			{
				return;
			}*/
		}
		//std::cout << "----------------------" << std::endl;
	}
	else if (m > 1)
	{
		for (int i = -50; i < 50; i++)
		{
			y = m * x + c;
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0xEC, 0xFF);
			SDL_RenderDrawPoint(gRenderer, x, y);
			x--;
			/*if (x > x2)
			{
				return;
			}*/
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
	float xincr = 0;
	float yincr = 0;
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
	xincr = dx / denominador;
	yincr = dy / denominador;
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

int main(int argc, char* args[])
{
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

						if (!Menu)
						{
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
			}



			//PRUEBAS
			//DRAW
			DrawPlano();

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
				angle -= .1f;
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
				angle += .1f;
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
			apply.x = 245;
			apply.y = 200;
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

			SDL_Rect background;
			background.w = 300;
			background.h = 300;
			background.x = 0;
			background.y = 0;
			if (Buttonclick(background, mouseX, mouseY) && leftclick)
			{
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

			//Vector2 *V1 = new Vector2(2, 1);
			//DrawVector(V1);

			//Vector2 V2(2, 1);

			//Matrix Transform(3, 3);
			//Transform(0, 0) = 2;
			//Transform(1, 1) = 2;

			//DrawVector(Transform * *V1);

			//Matrix M2(1, 2);
			//M2(0, 0) = 1;
			//M2(0, 1) = 1;

			////DrawMatrix(M2);

			//Matrix M1(2, 2);
			//M1(0, 0) = 4; 
			//M1(1, 1) = 1;
			////M1.Print();

			//Matrix M5(0, 0);
			//M5 = (M1 * M2);
			////DrawMatrix(M5);
			////M5.Print();

			//M1.transpose();

			//
			//*5 1 1
			//
			//4 1 0
			//0 1 0
			//0 0 0*/

			//MatrizEscalamiento MS(1.5, 2);
			////MS.Print();
			//MatrizRotacion MR(90);
			////MR.Print();
			//MatrizTranslacion MT(1.5, 1.5);
			////MT.Print();

			
			







			//DrawLine(1, 1, 3, 2);
			//DrawLine(0, 0, 1, 2);
			//DrawLine(0, -1, -2, -3);

			DrawLine2(1, 1, 2, 2);
			DrawLine2(-1, -2, 0, 0);

			SDL_RenderPresent(gRenderer);
		}

	}

	//Free resources and close SDL
	close();

	return 0;
}