#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class RenderWindow 
{
	public:
		RenderWindow(const char* p_title, int p_w, int p_h);
		SDL_Texture* loadTexture(const char* p_filePath);
		void cleanUp();
		void clear();
		void display();
		SDL_Renderer* get_renderer();
		void renderText(const char* text, int x, int y, const char* = "./assets/fonts/arial.ttf", SDL_Color = {255,245,245, 255}, int =24);
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
};