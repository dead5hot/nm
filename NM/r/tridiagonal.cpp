#include <iostream>
#include <vector>
#include <iomanip>

template<typename _T>
std::ostream& operator<<(std::ostream& o, const std::vector<_T>& vector__t)
{
  for(auto _t : vector__t)
  {
    o << std::setw(2) << _t << " ";
  }

  return o;
}
// template<typename _T>
// std::ostream& operator<<(std::ostream& o, const std::vector<std::vector<_T>>& vector_vector__t)
// {
//   int precision = o.precision();
//   o << std::fixed << std::setprecision(2);
//   for(auto vector__t : std::vector<std::vector<_T>> (vector_vector__t.rbegin(), vector_vector__t.rend()))
//   {
//     o << vector__t << "\n";
//   }

//   o << std::defaultfloat << std::setprecision(precision);

//   return o;
// }

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
  [[nodiscard]] static std::vector<double> solve(const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d)
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

      std::cout << alpha << std::endl;
      std::cout << beta << std::endl;

      // for(int i = 1; i <= n; i++) std::cout << "x" << i << " = " << x[i] << std::endl;
      return x;

      // return 0;
  }

};

// int main()
// {
//   std::vector<double> a { 0.0,  0.0,  1.0,  1.0};
//   std::vector<double> b { 0.0,  2.0,  2.0,  2.0};
//   std::vector<double> c { 0.0,  3.0, -1.0,  0.0};
//   std::vector<double> d { 0.0,  8.0,  2.0,  8.0};

//   std::cout << TriDiagonal::solve(a, b, c, d) << std::endl;

//   return 0;
// }