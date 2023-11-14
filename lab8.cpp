#include <bits/stdc++.h>
/*
    Solve the parabolic heat equation
    u0,t = 0; u4,t = 100 for all t
    h = 0.5; k = 0.125; c^2 = 1
    u1,0 = 20; u2,0 = 40; u3,0 = 60

    alpha = k * c^2 / h^2 = 0.5
    ui,j+1 = (ui-1,j + ui+1,j) / 2;
*/
int main() {
    double h = 0.5, k = 0.125;

    // x = [0 to 4] and t = [0 to 0.750]
    int rows = std::round((0.750 - 0) / k) + 1;
    int cols = std::round((4 - 0) / 1) + 1;
    double u[rows][cols];

    u[0][0] = 0, u[0][1] = 20, u[0][2] = 40, u[0][3] = 60, u[0][4] = 100;

    for(int r = 1; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            if(c == 0) {
                u[r][c] = 0;
            }
            else if(c == 4) {
                u[r][c] = 100;
            }
            else {
                u[r][c] = (u[r-1][c-1] + u[r-1][c+1]) / 2;
            }
            printf("%5.2lf ", u[r][c]);
        }
        printf("\n");
    }
    return 0;
}