#include <iostream>
#include <vector>
#include <functional>

#include "tridiagonal.cpp"

void show (std::vector<double> &v) {
    for(auto &i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
void foo (
    const std::array<std::function <double (double)>, 4>& coeff,
    std::vector<double> x,
    double y0,
    double yn
) {
    int n = (int) x.size() - 1; // here n == 8
    // std::cout << "here n == " << n << std::endl;
    std::vector<double> a(n), b(n), c(n), d(n);

    for(int i = 1; i < n; i++) {
        // coeff of yi-1 in equation i
        if(i != 1)
        {
          a[i] = coeff[0](x[i]);
        }

        // coeff of yi in equation i
        b[i] = coeff[1](x[i]);

        // coeff of yi+1 in equation i
        if(i != n - 1)
        {
          c[i] = coeff[2](x[i]);
        }

        // constant term in equation i
        if(i == 1) {
          d[i] = -coeff[3](x[i]) - coeff[0](x[i]) * y0;
        }
        else if(i == n - 1) {
          d[i] = -coeff[3](x[i]) - coeff[2](x[i]) * yn;
        }
        else {
          d[i] = -coeff[3](x[i]);
        }
    }
    
    // show(a);
    // show(b);
    // show(c);
    // show(d);
    TriDiagonal::solve(a, b, c, d);
  

}