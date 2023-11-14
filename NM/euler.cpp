#include <iostream>
#include <cmath>


// double f(double x, double y)
// {
//   return x - y;
// }

double solve(double x0, double y0, double h, double xf, double (*f)(double x, double y))
{
  int n = std::round(((xf - x0) / h));
  for(int i = 0; i < n; i++)
  {
    double x1 = x0 + h;
    double y1 = y0 + h * f(x0, y0);

    std::cout << x1 << " " << y1 << "\n";
    x0 = x1, y0 = y1;
  }

  return y0;
}

int main()
{
  auto ans = solve(0, 1, 0.1, 0.4, [] (double x, double y) {
    return x - y;
  });
  return 0;
}