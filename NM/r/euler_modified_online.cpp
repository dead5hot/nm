#include <iostream>
#include <cmath>


double solve(double x0, double y0, double h, double xf, double (*f)(double x, double y))
{
  int n = std::round(((xf - x0) / h));
  for(int i = 0; i < n; i++)
  {
    double x1 = x0 + h / 2;
    double y1 = y0 + (h / 2) * f(x0, y0);

    double slope = f(x1, y1);

    double x2 = x0 + h;
    double y2 = y0 + h * slope;

    std::cout << x2 << " " << y2 << "\n";
    x0 = x2, y0 = y2;
  }

  return y0;
}

int main()
{
  auto ans = solve(0, 1, 0.2, 0.4, [] (double x, double y) {
    return x - y;
  });
  return 0;
}