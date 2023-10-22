#include "utils.hpp"

int randint(int min, int max) {
    return (rand() + min) % (max + 1);
}

void drawFilledOctagon(SDL_Renderer* renderer, int centerX, int centerY, int size, SDL_Color color) {
    // Calculate the top-left corner of the rectangle
    int x = centerX - size / 2;
    int y = centerY - size / 2;

    // Create an SDL_Rect to define the position and size of the filled rectangle
    SDL_Rect rect = {x, y, size, size};

    // Set the drawing color
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Render the filled rectangle on the texture
    SDL_RenderFillRect(renderer, &rect);
}

