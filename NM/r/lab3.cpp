#include <bits/stdc++.h>
using namespace std;

struct Polynomial
{
  double a;
  double b;
};
Polynomial trapezoidal_integral_calculator(vector<Polynomial> fn_values, double step_size)
{
  Polynomial tmp = { 0, 0 };
  for(int i = 1; i < (int)fn_values.size() - 1; i++)
  {
    tmp.a += fn_values[i].a;
    tmp.b += fn_values[i].b;
  }
  tmp.a = fn_values.front().a + fn_values.back().a + 2 * tmp.a;
  tmp.b = fn_values.front().b + fn_values.back().b + 2 * tmp.b;
  return { step_size * tmp.a / 2, step_size * tmp.b / 2 };
}
int main()
{
  /* let I1 = integral(x=0to1)(x^2 + y^2)dx */
  int nx = (1 - 0) / 0.5, ny = (2 - 0) / 0.5;
  vector<Polynomial> fn_x;
  double x = 0;
  for(int i = 0; i <= nx; i++, x += 0.5)
  {
    fn_x.push_back({ x * x, 1 });
  }
  Polynomial I1 = trapezoidal_integral_calculator(fn_x, 0.5);


  /* let I2 = integral(y=0to2)I1dy */
  vector<Polynomial> fn_y;
  double y = 0;
  for(int i = 0; i <= ny; i++, y += 0.5)
  {
    fn_y.push_back({ I1.a + I1.b * y * y, 0 });
  }


  Polynomial I2 = trapezoidal_integral_calculator(fn_y, 0.5);
  printf("Answer: %lf", I2.a);
}
