#include <bits/stdc++.h>
using namespace std;

int main() {
    const double a = 1.0;
    const double dx = 0.1;
    const double dt = 0.01;
    const double L = 10.0;
    const int Nx = static_cast<int>(L / dx);
    const int Nt = 1;  // Number of time steps. Adjust as needed.

    vector<vector<double>> y(Nx, vector<double>(Nt, 0));

    // Initial condition
    for (int i = 0; i < Nx; i++) {
        y[i][0] = (i * dx * (L - i * dx)) / 100.0;
    }

    for (int j = 0; j < Nt - 1; j++) {
        for (int i = 1; i < Nx - 1; i++) {
            y[i][j + 1] =
                y[i][j] + (a * a * dt / (dx * dx)) *
                              (y[i + 1][j] - 2 * y[i][j] + y[i - 1][j]);
        }
    }

    // Print the solution at the final time step
    for (int i = 0; i < Nx; i++) {
        cout << i * dx << "\t" << y[i][Nt - 1] << " ";
    }

    return 0;
}
