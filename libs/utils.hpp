#include <SDL2/SDL.h>
#include <cmath>
#include <cstdlib>
#include "constant.hpp"

void drawFilledOctagon(SDL_Renderer* renderer, int centerX, int centerY, int = 20, SDL_Color = BAC_COLOR);
int randint(int min, int max);