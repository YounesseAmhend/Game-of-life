#include "SDL2/SDL.h"
#include "utils.hpp"
#include "constant.hpp"
#include "grid.hpp"

using namespace std; 

class Vector2i
{
    int x, y;
    public:
        Vector2i(int x, int y):x(x), y(y){};
        int getX(){return x;};
        int getY(){return y;};
        void setX(int value){x = value;};
        void setY(int value){y = value;};
};

typedef struct Bac{
    bool occupied;
    int age;
} Bac;

class Board{
    public:
        Board(SDL_Renderer *renderer, int numCols, int numRows, int size, int gap);
        void draw_grid();
        void draw_border();
        void draw_point(int indexX, int indexY, SDL_Color = BAC_COLOR);
        void draw_random(int seeds);

    private:
        int numCols, numRows, size, gap;
        Grid<Bac>* bacts; 
        SDL_Renderer *renderer;
        Vector2i vect;
};
