#include <iostream>
#include <cmath>
#include <iomanip>



double solve(double xi, double yi, double zi, double xf, double h, double (*dy_dx)(double x, double y, double z), double (*dz_dx)(double x, double y, double z))
{
  int n = std::round(((xf - xi) / h));

  std::cout << xi << " " << yi << " " << zi << "\n";
  for(int i = 0; i < n; i++)
  {
    double k1 = h * dy_dx(xi, yi, zi);
    double l1 = h * dz_dx(xi, yi, zi);

    double k2 = h * dy_dx(xi + h / 2, yi + k1 / 2, zi + l1 / 2);
    double l2 = h * dz_dx(xi + h / 2, yi + k1 / 2, zi + l1 / 2);

    double k3 = h * dy_dx(xi + h / 2, yi + k2 / 2, zi + l2 / 2);
    double l3 = h * dz_dx(xi + h / 2, yi + k2 / 2, zi + l2 / 2);
    
    double k4 = h * dy_dx(xi + h, yi + k3, zi + l3);
    double l4 = h * dz_dx(xi + h, yi + k3, zi + l3);

    std::cout << "[" << k1 << " " << k2 << " " << k3 << " " << k4 << "]";
    std::cout << "[" << l1 << " " << l2 << " " << l3 << " " << l4 << "] ⇨  ";
    double k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    double l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;
    
    xi += h, yi += k, zi += l;
    std::cout << xi << " " << yi << " " << zi << "\n";
  }

  return yi;
}
int main()
{
  std::cout << std::setprecision(8) << std::fixed;

  solve(
    0,
    1,
    1,
    0.1,
    0.1,
    [] (double x, double y, double z) {
      return z - x;
    },
    [] (double x, double y, double z) {
      return y + x;
    }
  );
  solve(
    0,
    2,
    0.3,
    0.05,
    0.05,
    [] (double x, double y, double z) {
      return z;
    },
    [] (double x, double y, double z) {
      return 6 * std::cos(x) - y;
    }
  );

  return 0;
}

