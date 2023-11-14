#include <iostream>
#include <vector>

#include "tridiagonal.hpp"
// #include "helper.hpp"
template<typename _T>
std::ostream& operator<<(std::ostream& o, const std::vector<_T>& vector__t)
{
  for(auto _t : vector__t)
  {
    o << std::setw(6) << _t << " ";
  }

  return o;
}
template<typename _T>
std::ostream& operator<<(std::ostream& o, const std::vector<std::vector<_T>>& vector_vector__t)
{
  int precision = o.precision();
  o << std::fixed << std::setprecision(2);
  for(auto vector__t : std::vector<std::vector<_T>> (vector_vector__t.rbegin(), vector_vector__t.rend()))
  {
    o << vector__t << "\n";
  }

  o << std::defaultfloat << std::setprecision(precision);

  return o;
}

void solve(std::vector<std::vector<double>>& grid, double h, double k, double c_square)
{
  int n = grid.at(0).size();
  int n_iterations = grid.size();

  int n_variables = n - 2;

  double alpha = k * c_square / (h * h);
  for(int iter = 1; iter < n_iterations; iter++)
  {
    std::vector<double> a(n_variables + 1), b(n_variables + 1), c(n_variables + 1), d(n_variables + 1);
    
    for(int i = 1; i <= n_variables; i++)
    {
      a.at(i) = -alpha;
      b.at(i) = 2 + 2 * alpha;
      c.at(i) = -alpha;
      
      d.at(i) = alpha * grid.at(iter - 1).at(i - 1) +
      (2 - 2 * alpha) * grid.at(iter - 1).at(i) + 
      alpha * grid.at(iter - 1).at(i + 1);

      // printf("(%lf, %lf, %lf)", alpha * grid.at(iter - 1).at(i - 1), (2 - 2 * alpha) * grid.at(iter - 1).at(i), alpha * grid.at(iter - 1).at(i + 1));

      if(i == 1)
      {
        a.at(i) = 0;
        d.at(i) -= -alpha * grid.at(iter).at(i - 1);
      }
      else if(i == n_variables)
      {
        c.at(i) = 0;
        // std::cout << "$$" << -alpha * grid.at(iter).at(i + 1) << "]";
        d.at(i) -= -alpha * grid.at(iter).at(i + 1);
      }
    }
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << c << std::endl;
    // std::cout << d << std::endl;

    std::vector<double> x = TriDiagonal::solve(a, b, c, d);
    for(int i = 1; i <= n_variables; i++)
    {
      grid.at(iter).at(i) = x.at(i);
    }
  }

  // std::cout << grid << std::endl;
}

int main()
{
  // freopen("output.txt", "w", stdout);
  std::vector<std::vector<double>> grid(2, std::vector<double> (5));
  for(int i = 0; i < 2; i++)
  {
    grid.at(i).at(0) = 0;
    grid.at(i).at(4) = 100;
  }
  grid.at(0) = {0, 50, 150, 200, 100};
  // for(int i = 0; i < 9; i++)
  // {
  //   grid.at(0).at(i) = 4 * i - i * i / 2.0;
  // }
  
  // std::cout << grid << std::endl;
  solve(grid, 1, 1, 1 / 2.0);

  std::cout << grid << std::endl;

  return 0;
}