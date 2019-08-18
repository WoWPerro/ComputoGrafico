// Draw_Pixel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <list>
#include "pch.h"
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

void DrawText()
{
	Text text(gRenderer, "arial.ttf", 25, "Matriz de transformacion", { 255, 0, 0, 255 });


	SDL_Rect point;
	point.w = 300;
	point.h = 300;
	point.x = 0;
	point.y = 0;

	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(gRenderer, &point);

	text.Display(0, 0, gRenderer);
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

//void generateVector(int mouseX, int mouseY)
//{
//	double x = (((mouseX) - (SCREEN_WIDTH/2.)) / 50.);
//	double y = -(((mouseY) - (SCREEN_HEIGHT/2.)) / 50.);
//
//	Vector2 *V1 = new Vector2(x, y);
//	DrawVector(V1);
//	//return *V1;
//}

//void mousePress(SDL_MouseButtonEvent& b, int mouseX, int mouseY) 
//{
//	if (b.button == SDL_BUTTON_LEFT) 
//	{
//		/*std::cout << mouseX << "  ";
//		std::cout << mouseY << std::endl;*/
//		generateVector(mouseX, mouseY);
//	}
//}

int main(int argc, char* args[])
{
	int mouseX;
	int mouseY;
	std::list <Vector2> Vectores;

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
						/*std::cout << mouseX << "  ";
						std::cout << mouseY << std::endl;*/
						double x = (((mouseX)-(SCREEN_WIDTH / 2.)) / 50.);
						double y = -(((mouseY)-(SCREEN_HEIGHT / 2.)) / 50.);

						Vector2 *V1 = new Vector2(x, y);
						//DrawVector(V1);
						Vectores.push_back(*V1);
					}
				}
			}

			

			//PRUEBAS
			//DRAW
			DrawPlano();
			DrawVectores(Vectores);
			Vector2 *V1 = new Vector2(2, 1);
			DrawVector(V1);

			Vector2 V2(2, 1);

			Matrix Transform(3, 3);
			Transform(0, 0) = 2;
			Transform(1, 1) = 2;

			DrawVector(Transform * *V1);

			Matrix M2(1, 2);
			M2(0, 0) = 1;
			M2(0, 1) = 1;

			//DrawMatrix(M2);

			Matrix M1(2, 2);
			M1(0, 0) = 4; 
			M1(1, 1) = 1;
			//M1.Print();

			Matrix M5(0, 0);
			M5 = (M1 * M2);
			//DrawMatrix(M5);
			//M5.Print();

			M1.transpose();

			
			/*5 1 1
			
			4 1 0
			0 1 0
			0 0 0*/

			DrawText();

			SDL_RenderPresent(gRenderer);

			MatrizEscalamiento MS(1.5, 2);
			//MS.Print();
			MatrizRotacion MR(90);
			//MR.Print();
			MatrizTranslacion MT(1.5, 1.5);
			//MT.Print();
		}

	}

	//Free resources and close SDL
	close();

	return 0;
}