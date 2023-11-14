#include <iostream>
#include <vector>

int main() {
    const int size = 8;
    const int max_iterations = 4; // Example number, adjust as needed
    
    std::vector<std::vector<double>> grid(size+1, std::vector<double>(size+1, 0));

    // Setting boundary conditions
    for (int i = 0; i <= size; ++i) {
        grid[i][0] = i * i;
        grid[size][i] = 10 * i;
        grid[i][size] = 3 * i + 4;
    }

    std::vector<std::vector<double>> newGrid = grid;

    for (int iteration = 1; iteration <= max_iterations; ++iteration) {
        for (int i = 1; i < size; ++i) {
            for (int j = 1; j < size; ++j) {
                newGrid[i][j] = 0.25 * (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1]);
            }
        }
        grid = newGrid;  // Update the grid for the next iteration
    }

    // Output the result after specified iterations
    for (int i = 0; i <= size; ++i) {
        for (int j = 0; j <= size; ++j) {
            std::cout.precision(4);
            std::cout << std::fixed << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
