#include <iostream>
#include <array>
#include <functional>


#include "fin.cpp"


template<double h>
[[nodiscard]] constexpr const std::array<std::function<double (double)>, 4> ququ(const std::array<std::function<double (double)>, 4>& coeff)
{
  static_assert(h > 0, "");
  return std::array<std::function<double (double)>, 4> {
    [&] (double x) -> double {
      return coeff[0](x) / (h * h) - coeff[1](x) / (2 * h);
    },
    [&] (double x) -> double {
      return coeff[2](x) - 2 * coeff[0](x) / (h * h);
    },
    [&] (double x) -> double {
      return coeff[0](x) / (h * h) + coeff[1](x) / (2 * h);
    },
     [&] (double x) -> double {
      return coeff[3](x);
    }
  };
}

int main()
{
  std::array<std::function<double (double)>, 4> coeff {
    [] (double x) { return 1 + x * x; },
    [] (double x) { return -2 * x; },
    [] (double x) { return x * x; },
    [] (double x) { return -x * x; }
  };

  foo(ququ<0.5>(coeff), {0, 0.5, 1.0, 1.5, 2.0, 2.5, 3, 3.5, 4}, 5, 2);

  return 0;
}