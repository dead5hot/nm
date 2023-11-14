#include <iostream>
#include <cmath>

// class MyClass
// {
// public:
//   int member;
//   MyClass(int n) : member(n) { }
// };

// long double operator ""_w(long double);
// std::string operator ""_w(const char16_t*, size_t);
// unsigned    operator ""_w(const char*);
 
// int main()
// {
//     1.2_w;    // calls operator ""_w(1.2L)
//     u"one"_w; // calls operator ""_w(u"one", 3)
//     12_w;     // calls operator ""_w("12")
//     // "two"_w;  // error: no applicable literal operator
// }

double solve(double xi, double yi, double xf, double h, double (*f)(double x, double y))
{
  int n = std::round(((xf - xi) / h));

  std::cout << xi << " " << yi << "\n";
  for(int i = 0; i < n; i++)
  {
    double k1 = h * f(xi, yi);
    double k2 = h * f(xi + h / 2, yi + k1 / 2);
    double k3 = h * f(xi + h / 2, yi + k2 / 2);
    double k4 = h * f(xi + h, yi + k3);

    std::cout << "[" << k1 << " " << k2 << " " << k3 << " " << k4 << "] ⇨  ";
    double k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    
    xi = xi + h;
    yi = yi + k;
    std::cout << xi << " " << yi << "\n";
  }

  return yi;
}
int main()
{
  solve(0, 1, 0.2, 0.2, [] (double x, double y) {
    return x + y;
  });

  return 0;
}

