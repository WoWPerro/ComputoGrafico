#include "pch.h"
#include "Text.h"
#include <iostream>
#include <fstream> 



Text::Text(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color)
{
	//std::ofstream outfile("test.txt");
	//outfile.close();

	TTF_Init();
	//printf("TTF_OpenFont: %s\n", TTF_GetError());

	_text_texture = LoadFont(renderer, font_path, font_size, message_text, color);
	SDL_QueryTexture(_text_texture, nullptr, nullptr, &_text_rect.w, &_text_rect.h);
}

void Text::Display(int x, int y, SDL_Renderer *renderer) const
{
	_text_rect.x = x;
	_text_rect.y = y;
	SDL_RenderCopy(renderer, _text_texture, nullptr, &_text_rect);
}

SDL_Texture *Text::LoadFont(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color)
{
	TTF_Font *font = TTF_OpenFont(font_path.c_str(), font_size);
	if (!font)
	{
		std::cerr << "failed to load font \n";
	}
	auto text_surface = TTF_RenderText_Solid(font, message_text.c_str(), color);
	if (!text_surface)
	{
		std::cerr << "failed to create text surface\n";
	}
	auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	if (!text_texture)
	{
		std::cerr << "Failed to create text texture\n";
	}
	SDL_FreeSurface(text_surface);
	return text_texture;
}


//SDL_Texture* Text::renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer)
//{
//	TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
//	if (font == nullptr) {
//		std::cout << "TTF_OpenFont";
//		return nullptr;
//	}
//	SDL_Surface *surf = TTF_RenderText_Blended_Wrapped(font, message.c_str(), color, 950);
//	if (surf == nullptr) {
//		TTF_CloseFont(font);
//		std::cout << "TTF_RenderText";
//		return nullptr;
//	}
//	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
//	if (texture == nullptr) {
//		std::cout << "CreateTexture";
//	}
//	SDL_FreeSurface(surf);
//	TTF_CloseFont(font);
//	return texture;
//}
//
//void Text::renderText(const std::string &message, const std::string &fontFile)
//{
//	if (message.size() == 0)
//		return;
//
//	SDL_Color color = { 0, 0, 0, 255 };
//	SDL_Texture *image = renderText(message.c_str(), "sample.ttf", color, 64, renderer);
//	SDL_Rect dst;
//	dst.x = 0;
//	dst.y = 0;
//	SDL_QueryTexture(image, NULL, NULL, &dst.w, &dst.h);
//	renderTexture(image, renderer, dst);
//}


Text::~Text()
{
}
