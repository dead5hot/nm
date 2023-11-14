#include <bits/stdc++.h>
using namespace std;
/*
    Solution of Laplace equtation in 2D
    standard 5-point formula
    ui,j = (ui-1,j+1 + ui+1,j-1 + ui+1,j+1 + ui-1,j-1) / 4;
*/
const double Precision = 1e-3;
void show(vector<vector<double>>& grid) {
    int m = grid.size(), n = grid.at(0).size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6.3lf ", grid[i][j]);
        }
        printf("\n");
    }
}
void solve(vector<vector<double>>& grid) {
    int m = grid.size(), n = grid[0].size();

    int cnt = 0;
    while (true) {
        bool flag = true;

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                auto initial_value = grid.at(i).at(j);
                grid.at(i).at(j) =
                    (grid.at(i - 1).at(j) + grid.at(i + 1).at(j) +
                     grid.at(i).at(j - 1) + grid.at(i).at(j + 1)) /
                    4;

                if (abs(grid.at(i).at(j) - initial_value) > Precision) {
                    flag = false;
                }
            }
        }
        cnt++;
        if (flag) break;
    }
    cout << "n_iterations: " << cnt << endl;
    show(grid);
}

void initialize(vector<vector<double>>& grid) {
    auto five_point = [&](int i, int j, int h = 1) {
        grid.at(i).at(j) = (grid.at(i - h).at(j) + grid.at(i + h).at(j) +
                            grid.at(i).at(j - h) + grid.at(i).at(j + h)) /
                           4;
    };
    five_point(2, 2, 2);

    auto five_point_diagonal = [&](int i, int j) {
        grid.at(i).at(j) =
            (grid.at(i + 1).at(j + 1) + grid.at(i - 1).at(j - 1) +
             grid.at(i - 1).at(j + 1) + grid.at(i + 1).at(j - 1)) /
            4;
    };

    five_point_diagonal(1, 1), five_point_diagonal(3, 1);
    five_point_diagonal(1, 3), five_point_diagonal(3, 3);

    five_point(1, 2), five_point(2, 3), five_point(2, 1), five_point(3, 2);
}
int main() {
    vector<vector<double>> grid(5, vector<double>(5, 0));
    for (int i = 0; i <= 4; i++) {
        grid.at(i).at(0) = 0;
        grid.at(i).at(4) = 8 + 2 * i;
    }
    for (int j = 0; j <= 4; j++) {
        grid.at(0).at(j) = j * j / 2.0;
        grid.at(4).at(j) = j * j;
    }
    initialize(grid);
    solve(grid);

    return 0;
}