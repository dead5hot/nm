#include <iostream>
#include <cmath>
#include <iomanip>


// #define XYZ 

const double Precision = 1e-8;

double solve(double xi, double yi, double h, double xf, double (*f)(double x, double y))
{
  int n = std::round(((xf - xi) / h));
#ifdef XYZ
  std::cout << " ⇨  \x1b[1;31m" << xi << " " << yi << "\x1b[m\n";
#endif
  for(int i = 0; i < n; i++)
  {
    double xf = xi + h;
    double slope = f(xi, yi);

    // first solution using euler's method!
    double yii = yi + h * slope;
  #ifdef XYZ
    std::cout << "[" << xf << " " << yii << "]";
  #endif
    while(true)
    {
      double yif = yi + h / 2 * (slope + f(xf, yii));

      if(std::abs(yif - yii) <= Precision)
      {
        break;
      }

      yii = yif;
    #ifdef XYZ
      std::cout << "[" << xf << " " << yii << "]";
    #endif
    }
    double yf = yii;
    // double yf = std::round(100 * yii) / 100;
    
    xi = xf, yi = yf;
  #ifdef XYZ
    std::cout << " ⇨  \x1b[1;31m" << xi << " " << yi << "\x1b[m\n";
  #endif
  }

  return yi;
}

int main()
{
  auto ans = solve(0, 1, 1e-8, 0.4, [] (double x, double y) {
    return x - y;
  });

  std::cout << std::setprecision(8) << ans << std::endl;
  return 0;
}