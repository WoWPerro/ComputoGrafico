// Draw_Pixel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "SDL.h"
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "Vector2.h"

//Screen dimension constants
int SCREEN_WIDTH = 1280;  //Hacer variables y modificar con respecto a la entrada de los par�metros para pasarlo desde consola
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
	SDL_RenderPresent(gRenderer);
}

void DrawVector(Vector2 v1)
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0x00, 0xFF);


	SDL_RenderDrawPoint(gRenderer, 0, 0);
}

int main(int argc, char* args[])
{
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
			}

			DrawPlano();

		}

	}

	//Free resources and close SDL
	close();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file