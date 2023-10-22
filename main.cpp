#include "libs/window.hpp"
#include "libs/board.hpp"
#include "libs/constant.hpp"

using namespace std;


static void welcome() {
    cout << "Welcome to the game of Life, a simulation of the lifecycle of a bacteria colony." << endl;
    cout << "Cells live and die by the following rules:" << endl << endl;
    cout << "\tA cell with 1 or fewer neighbors dies of loneliness" << endl;
    cout << "\tLocations with 2 neighbors remain stable" << endl;
    cout << "\tLocations with 3 neighbors will spontaneously create life" << endl;
    cout << "\tLocations with 4 or more neighbors die of overcrowding" << endl << endl;
    cout << "In the animation, new cells are dark and fade to gray as they age." << endl << endl;
    cout << "Hit [enter] to continue....   ";
}

// void draw_grid(SDL_Renderer *renderer, int numCols = 10, int numRows = 10, int size = 20, int gap = 1){
//     gap = (gap+size);
//     for(int i = 0; i < numCols; i++){
//         for(int j = 0; j < numRows; j++){
//             drawFilledCircle(renderer, gap*i+10+size/2, gap*j+10+size/2, size/2);
//         }
//     }
// }
// void draw_point(SDL_Renderer *renderer, int indexX = 10, int indexY = 10, int size = 20, int gap = 1){
//     gap = (gap+size);
//     SDL_SetRenderDrawColor(renderer, 25, 80, 255, 255);
//     drawFilledCircle(renderer, 10 + size/2 + indexX*gap, 10 + indexY*gap+ size/2, size/4);
// }
// void draw_border(SDL_Renderer *renderer, int numCols = 10, int numRows = 10, int size = 20, int gap = 1){
//     int total_gap = (gap+size);
//     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//      SDL_Rect rect = {10-2*gap, 10-2*gap, total_gap*numCols+3*gap, total_gap*numRows+3*gap};
//     SDL_RenderDrawRect(renderer, &rect);
// }

int main(int argc, char** argv){
    
    welcome();
    RenderWindow window(TITLE, WIDTH, HEIGHT);

    // Create a renderer.
    SDL_Renderer *renderer = window.get_renderer();

    // Set the drawing color.
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);



    // Draw the rectangle.
    Board board(renderer, NUM_ROWS, NUM_COLS, SIZE, GAP);
    board.draw_random(10);
    board.draw_border();


    bool running = true;
    SDL_Event event;
    while(running){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
					running = false;
        }
        window.display();
        SDL_Delay(DELAY);
        
    }
    window.cleanUp();
    return 0;
}
