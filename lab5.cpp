#include <bits/stdc++.h>
using namespace std;
const double Precision = 1e-3;
/*
    Given the differential equation dy/dx = y^2 - y/x with the initial condition
    y(1) = 1, use Euler's modefied method to obtain value of y for x = 1.6 take h = 0.2
*/

double solve(double xi, double yi, double xf, double h,
             double (*f)(double x, double y)) {
    int n = round(((xf - xi) / h));
    for (int i = 0; i < n; i++) {
        double xf = xi + h;
        double slope = f(xi, yi);
        double yii = yi + h * slope;

        while (true) {
            double yif = yi + h / 2 * (slope + f(xf, yii));
            if (abs(yif - yii) <= Precision) {
                break;
            }
            yii = yif;
        }
        double yf = yii;
        xi = xf, yi = yf;
    }
    return yi;
}

int main() {
    auto ans = solve(1, 1, 1.6, 0.2, [](double x, double y) { return y*y - y/x; });
    printf("Value of y at x = 1.6 is %lf", ans);
    return 0;
}