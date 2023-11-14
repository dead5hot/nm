#include <iostream>

const double Precision = 1e-6;

double f1(double x, double y)
{
  return x * x + x * y - 10;
}
double delf1bydelx(double x, double y)
{
  return 2 * x + y;
}
double delf1bydely(double x, double y)
{
  return x;
}


double f2(double x, double y)
{
  return y + 3 * x * y * y - 57;
}
double delf2bydelx(double x, double y)
{
  return 3 * y * y;
}
double delf2bydely(double x, double y)
{
  return 1 + 6 * x * y;
}
double abs(double x)
{
  if(x < 0) return -x;
  return x;
}


int main()
{
  double xi = 1.5, yi = 3.5;


  int iteration_no = 1;
  while(true)
  {
    double f1i = f1(xi, yi);
    double f2i = f2(xi, yi);


    double delf1bydelxi = delf1bydelx(xi, yi);
    double delf1bydelyi = delf1bydely(xi, yi);


    double delf2bydelxi = delf2bydelx(xi, yi);
    double delf2bydelyi = delf2bydely(xi, yi);

    double determinant = delf1bydelxi * delf2bydelyi - delf1bydelyi * delf2bydelxi;


    double xj = xi - (f1i * delf2bydelyi - f2i * delf1bydelyi) / determinant;
    double yj = yi - (-f1i * delf2bydelxi + f2i * delf1bydelxi) / determinant;


    printf("Iteration Number : %d | x : %lf | y : %lf\n", iteration_no, xi, yi);
    if(abs(xj - xi) < Precision && abs(yj - yi) < Precision) break;

    xi = xj;
    yi = yj;
    iteration_no++;
  }
  printf("## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ##\n");
  printf("Answer: x : %lf | y : %lf\n", xi, yi);
}
