#include "board.hpp"

Board::Board(SDL_Renderer *renderer, int numCols, int numRows, int size, int gap)
:   renderer(renderer), 
    vect(Vector2i(((WIDTH - numCols*(size+gap))/2) - size/2, ((HEIGHT - numRows*(size+gap))/2) - size/2)), 
    numCols(numCols), 
    numRows(numRows), 
    size(size), 
    bacts(new Grid<Bac>(numCols, numRows, {false, 0})),
    gap(gap){}

void Board::draw_grid(){
    for(int i = 0; i < numCols; i++){
        for(int j = 0; j < numRows; j++){
            drawFilledOctagon(renderer, (gap+size)*i+vect.getX()+size, (gap+size)*j+vect.getY()+size, size);
        }
    }
}
void Board::draw_point(int indexX, int indexY, SDL_Color color){
    Bac targeted = bacts->at(indexX, indexY);
    if(!targeted.occupied){
        bacts->set(indexX, indexY, {true, targeted.age+1});
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        drawFilledOctagon(renderer, (gap+size)*indexX+vect.getX()+size, (gap+size)*indexY+vect.getY()+size, size, color);
    }
    cout << "occupied" << "["<<indexX<<"]" << "["<<indexY<<"]" << ": " <<  bacts->at(indexX, indexY).occupied << endl;
}
void Board::draw_random(int seeds){
    for(int i = 0; i < seeds; i++){
        while(true){
            int randomX = randint(0, numRows);
            int randomY = randint(0, numCols);
            if(bacts->at(randomX, randomY).occupied) continue;
            draw_point(randomX, randomY);
            break;
        }
    }
}
void Board::draw_border(){
    int total_gap = (gap+size);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rect = {vect.getX(), vect.getY(), total_gap*numCols+size, total_gap*numRows+size};
    SDL_RenderDrawRect(renderer, &rect);
}