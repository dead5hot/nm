#include <bits/stdc++.h>
using namespace std;
double f(double x, double y) {
    return 2*x + y;
}
double runge_kutta(double h, double x0, double y0, double x, int n) {
    double y = y0, k1, k2, k3, k4;
    for(int i = 1; i <= n; i++) {
        k1 = h * f(x0, y);
        k2 = h * f(x0 + 0.5*h, y + 0.5*k1);
        k3 = h * f(x0 + 0.5*h, y + 0.5*k2);
        k4 = h * f(x0 + h, y + k3);
        // Update next value of y
        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);
        // Update next value of x
        x0 = x0 + h;
    }
    return y;
}
int main() {
    /* dy/dx = 2x + y .Given y(1) = 2 to find y(1.2) */
    printf("The value of y at x = 1.2 is %lf", 
    runge_kutta(0.1, 1, 2, 1.2, 2));
}

/*
    The value of y at x = 1.2 is 2.928415
*/