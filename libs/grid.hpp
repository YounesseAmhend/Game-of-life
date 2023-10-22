#include <vector>
#include <iostream>

using namespace std;

template <typename T>

class Grid {
public:
    // Constructor to create an empty grid
    Grid() {}

    // Constructor to create a grid with specific dimensions and initialize elements
    Grid(int rows, int cols, const T& initialValue = T())
        : grid(rows, std::vector<T>(cols, initialValue)) {}

    // Function to resize the grid to the specified dimensions and initialize elements
    void resize(int rows, int cols, const T& initialValue = T()) {
        grid.resize(rows, std::vector<T>(cols, initialValue));
    }

    // Access and modify elements in the grid
    T& at(int row, int col) {
        return grid[row][col];
    }

    void set(int row, int col, T value){
        grid[row][col] = value;
    }

    // Get the number of rows in the grid
    int getRows() const {
        return grid.size();
    }


    // Get the number of columns in the grid
    int getCols() const {
        if (getRows() > 0) {
            return grid[0].size();
        }
        return 0;
    }

private:
    vector<vector<T>> grid;
};
