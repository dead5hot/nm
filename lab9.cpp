#include <bits/stdc++.h>

#include "Tridiagonal.hpp"
using namespace std;
void show(vector<vector<double>>& grid) {
    int m = grid.size(), n = grid.at(0).size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6.3lf ", grid[i][j]);
        }
        printf("\n");
    }
}
void solve(vector<vector<double>>& grid, double h, double k, double c_square) {
    int n = grid.at(0).size();
    int n_iterations = grid.size();

    int n_variables = n - 2;

    double alpha = k * c_square / (h * h);
    for (int iter = 1; iter < n_iterations; iter++) {
        vector<double> a(n_variables + 1), b(n_variables + 1),
            c(n_variables + 1), d(n_variables + 1);

        for (int i = 1; i <= n_variables; i++) {
            a.at(i) = -alpha;
            b.at(i) = 2 + 2 * alpha;
            c.at(i) = -alpha;

            d.at(i) = alpha * grid.at(iter - 1).at(i - 1) +
                      (2 - 2 * alpha) * grid.at(iter - 1).at(i) +
                      alpha * grid.at(iter - 1).at(i + 1);

            if (i == 1) {
                a.at(i) = 0;
                d.at(i) -= -alpha * grid.at(iter).at(i - 1);
            } else if (i == n_variables) {
                c.at(i) = 0;
                d.at(i) -= -alpha * grid.at(iter).at(i + 1);
            }
        }

        vector<double> x = TriDiagonal::solve(a, b, c, d);
        for (int i = 1; i <= n_variables; i++) {
            grid.at(iter).at(i) = x.at(i);
        }
    }
}

int main() {
    vector<vector<double>> grid(8, vector<double>(9, 0));
    for (int i = 0; i < 9; i++) {
        grid.at(0).at(i) = 4 * i - i * i / 2.0;
    }
    solve(grid, 1, 1 / 8.0, 4);
    show(grid);
    return 0;
}