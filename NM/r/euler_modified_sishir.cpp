#include <iostream>
#include <cmath>
#include <iomanip>

// using namespace std;

const double Precision = 1e-3;

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
  std::cout << "yi: " << yi << std::endl;
  return yi;
}

// double solve(double xi, double yi, double xf, double h,
//              double (*f)(double x, double y)) {
//     int n = round(((xf - xi) / h));
//     for (int i = 0; i < n; i++) {
//         double xf = xi + h;
//         double slope = f(xi, yi);
//         double yii = yi + h * slope;


//         while (true) {
//             double yif = yi + h / 2 * (slope + f(xf, yii));
//             if (std::abs(yif - yii) <= Precision) {
//                 break;
//             }
//             yii = yif;
//         }
//         double yf = yii;
//         xi = xf, yi = yf;
//     }
//     return yi;
// }

// int main()
// {
//   auto ans = solve(0, 1, 1e-8, 0.4, [] (double x, double y) {
//     return x - y;
//   });

//   std::cout << std::setprecision(8) << ans << std::endl;
//   return 0;
// }
int main()
{
  double ans = solve(1, 1, 0.2, 1.6, [] (double x, double y) {
    return y * y - y / x;
  });

  // printf("Value of y at x = 1.6 is %lf", ans);
  std::cout << "Value of y at x = 1.6 is " << ans << std::endl;
  return 0;
}
