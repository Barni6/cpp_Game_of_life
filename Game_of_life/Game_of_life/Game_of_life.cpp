#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class GameOfLife {
public:
    GameOfLife(int size) : height(size), width(size) {
        srand(time(nullptr));
        initializeGrid(0.1);
    }

    GameOfLife(int height, int width) : height(height), width(width) {
        srand(time(nullptr));
        initializeGrid(0.1);
    }

    GameOfLife(int size, float probability) : height(size), width(size) {
        srand(time(nullptr));
        initializeGrid(probability);
    }

    GameOfLife(int height, int width, float probability) : height(height), width(width) {
        srand(time(nullptr));
        initializeGrid(probability);
    }

    GameOfLife(int height, int width, int top, int left, const std::vector<std::vector<bool>>& pattern): height(height), width(width) {
        grid.resize(height, std::vector<bool>(width, false));

        for (int i = 0; i < pattern.size(); ++i) {
            for (int j = 0; j < pattern[i].size(); ++j) {
                if (i + top >= 0 && i + top < height && j + left >= 0 && j + left < width) {
                    grid[i + top][j + left] = pattern[i][j];
                }
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const GameOfLife& game);

    void play(int steps) {
        for (int step = 0; step < steps; ++step) {
            updateGrid();
            std::cout << *this << std::endl;
            std::cin.ignore(); // Wait for user input (ENTER key)
        }
    }

private:
    int height;
    int width;
    std::vector<std::vector<bool>> grid;

    void initializeGrid(float probability) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                float random = static_cast<float>(rand()) / RAND_MAX;
                grid[i][j] = (random < probability);
            }
        }
    }

    void updateGrid() {
        std::vector<std::vector<bool>> newGrid = grid;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int liveNeighbors = countLiveNeighbors(i, j);
                if (grid[i][j]) {
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        newGrid[i][j] = false;
                    }
                }
                else {
                    if (liveNeighbors == 3) {
                        newGrid[i][j] = true;
                    }
                }
            }
        }

        grid = newGrid;
    }

    int countLiveNeighbors(int row, int col) const {
        int count = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int newRow = (row + i + height) % height;
                int newCol = (col + j + width) % width;
                if (!(i == 0 && j == 0) && grid[newRow][newCol]) {
                    ++count;
                }
            }
        }
        return count;
    }
};

std::ostream& operator<<(std::ostream& os, const GameOfLife& game) {
    for (const auto& row : game.grid) {
        for (bool cell : row) {
            os << (cell ? '*' : ' ') << ' ';
        }
        os << std::endl;
    }
    return os;
}

int main() {
    //// Példa használat
    //int size = 10;
    //GameOfLife squareGrid(size);
    //squareGrid.play(100); // Játék 100 lépésig vagy ENTER-ig

    int height = 5;
    int width = 8;
    GameOfLife customGrid(height, width, 2, 3, { {1, 0, 1, 0, 1, 0, 1, 0} });
    customGrid.play(100); // Játék 100 lépésig vagy ENTER-ig

    return 0;
}
