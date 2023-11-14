#include <iostream>
#include <vector>

#include "helper.hpp"

class TriDiagonal
{
public:

/*
  static std::vector<double> solve(const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d)
  {
    size_t n = a.size() - 1;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    std::vector<double> alpha(n + 1), beta(n + 1), x(n + 1);

    // Step 1
    alpha[1] = b[1];
    std::cout << "[" << alpha[1] << "]";
    for(size_t i = 2; i <= n; i++)
    {
      // printf("(%lf, %lf, %lf)", b[i], a[i], c[i - 1]);
      alpha[i] = b[i] - a[i] * c[i - 1] / alpha[i - 1];
      // std::cout << "[" << alpha[i] << "]";
    }

    // Step 2
    beta[1] = d[1] / b[1];
    for(size_t i = 2; i <= n; i++) 
    {
      beta[i] = (d[i] - a[i] * beta[i - 1]) / alpha[i];
      
    }

    // Step 3
    x[n] = beta[n];
    for(size_t i = n - 1; i >= 1; i--)
    {
      x[i] = beta[i] - c[i] * x[i + 1] / alpha[i];
    }

    std::cout << alpha << std::endl;
    std::cout << beta << std::endl;
    std::cout << x << std::endl;

    return x;
  }

*/
[[nodiscard]] static std::vector<double> solve(std::vector<double>& a, std::vector<double>& b, std::vector<double>& c, std::vector<double>& d)
{
    // int n;
    // cin >> n;
    int n = (int)a.size() - 1;

    // one based indexing
    // vector<vector<double>> matA(n+1 , vector<double> (n+1));
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cin >> matA[i][j];
    //     }
    // }

    // std::vector<double> a(n+1), b(n+1), c(n+1), d(n+1);
    // for(int i = 1; i <= n; i++) a[i] = matA[i][i-1];

    // for(int i = 0; i <= n; i++) b[i] = matA[i][i];

    // for(int i = 0; i <= n-1; i++) c[i] = matA[i][i+1];

    // for(int i = 1; i <= n; i++) cin >> d[i];
    
    // std::
    std::vector<double> alpha(n+1), beta(n+1), x(n+1);

    // Step 1
    alpha[1] = b[1];
    for(int i = 2; i <= n; i++) alpha[i] = b[i] - a[i] * c[i-1] / alpha[i-1];

    // Step 2
    beta[1] = d[1] / b[1];
    for(int i = 2; i <= n; i++) beta[i] = (d[i] - a[i] * beta[i-1]) / alpha[i];

    // Step 3
    x[n] = beta[n];
    for(int i = n-1; i >= 1; i--) x[i] = beta[i] - c[i] * x[i+1] / alpha[i];

    // for(int i = 1; i <= n; i++) std::cout << "x" << i << " = " << x[i] << std::endl;
    return x;

    // return 0;
}

};
