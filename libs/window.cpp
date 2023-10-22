#include "Window.hpp"



RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{

    if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
	if (SDL_Init(SDL_INIT_AUDIO) < 0) 
        printf("SDL_Init failed: %s\n", SDL_GetError());
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) 
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
	if (TTF_Init() != 0) 
        std::cerr << "SDL_ttf initialization failed: " << TTF_GetError() << std::endl;

	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
    SDL_Quit();
	IMG_Quit();
	TTF_Quit();
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

// void RenderWindow::render(Entity &entity)
// {
//     SDL_Rect src, dest;
//     src.x = entity.getCurrentFrame().x;
//     src.y = entity.getCurrentFrame().y;
//     src.w = entity.getCurrentFrame().w;
//     src.h = entity.getCurrentFrame().h;

//     dest.x = entity.getPosition().x;
//     dest.y = entity.getPosition().y;
//     dest.w = entity.getCurrentFrame().w*entity.getScale() ;
//     dest.h = entity.getCurrentFrame().h*entity.getScale() ; 

// 	SDL_RenderCopy(renderer, entity.getTexture(), &src, &dest);
// }

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}
void RenderWindow::renderText(const char* text, int x, int y, const char* fontText, SDL_Color color, int size) {
    TTF_Font* font = TTF_OpenFont(fontText, size);

	if(font == NULL){
		std::cerr << SDL_GetError() << std::endl;
	}

	SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);

	if(surface == NULL){
		std::cerr << "error surface : " << SDL_GetError() << std::endl;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	if(texture == NULL){
		std::cerr <<"error texture : " << SDL_GetError() << std::endl;
	}

	SDL_Rect rect = { x, y, surface->w, surface->h };

	if(SDL_RenderCopy(renderer, texture, NULL, &rect) < 0){
		std::cerr << "something went wrong "<< SDL_GetError() << std::endl;
	};
	
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
	display();
	
}
SDL_Renderer* RenderWindow::get_renderer(){
	return renderer;
}