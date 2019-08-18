#pragma once
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL.h"
#include <string>

class Text
{
public:
	Text(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);

	void Display(int x, int y, SDL_Renderer *renderer) const;

	static SDL_Texture *LoadFont(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);

	/*void renderText(const std::string &message, const std::string &fontFile);
	SDL_Texture * renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);
	void renderTexture(KImage *tex, int x, int y);
	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst);*/

	~Text();

private:
	SDL_Texture * _text_texture = nullptr;
	mutable SDL_Rect _text_rect;
};

