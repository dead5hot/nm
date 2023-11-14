#include <bits/stdc++.h>
using namespace std;
/*
    Poisson Equation
    Solve d^2u / dx^2 + d^2u / dy^2 = -10(x + y)
    in square mesh x = 0, y = 0, x = 4, y = 4
    h = 1
*/
#define DIM 5
void show(vector<vector<double>>& grid) {
    int m = grid.size(), n = grid.at(0).size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%9.3lf ", grid[i][j]);
        }
        printf("\n");
    }
}
double f(double x, double y) { return -10 * (x + y); }
double mid_point(vector<vector<double>>& u, size_t row, size_t col) {
    return (u[row + 1][col] + u[row - 1][col] + u[row][col + 1] +
            u[row][col - 1]) / 4;
}

void solve(vector<vector<double>>& u, double h, size_t n) {
    size_t row, col, i;
    for (i = 0; i < n; ++i) {
        for (row = 1; row < DIM - 1; ++row) {
            for (col = 1; col < DIM - 1; ++col) {
                u[row][col] = mid_point(u, row, col) - h * h * f(row, col) / 4;
            }
        }
    }
}

int main() {
    vector<vector<double>> u = {{200, 200, 200, 200, 200},
                               {100, 0, 0, 0, 50},
                               {100, 0, 0, 0, 60},
                               {100, 0, 0, 0, 70},
                               {0, 0, 0, 0, 0}};

    solve(u, 1.0, 2);
    show(u);
    return 0;
}
