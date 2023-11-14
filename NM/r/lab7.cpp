#include <stdio.h>
#define DIM 5

float f(float x, float y) { return -10 * (x + y); }
float mid_point(float u[DIM][DIM], size_t row, size_t col)
{
  return (u[row + 1][col] + u[row - 1][col] +
    u[row][col + 1] + u[row][col - 1]) / 4;
}

void solve(float u[DIM][DIM], float h, size_t n)
{
  size_t row, col, i;
  for(i = 0; i < n; ++i)
  {
    for(row = 1; row < DIM - 1; ++row)
    {
      for(col = 1; col < DIM - 1; ++col)
      {
        u[row][col] = mid_point(u, row, col) - h * h * f(row, col) / 4;
      }
    }
  }
}
int main()
{
  size_t row, col;
  float u[DIM][DIM] = {
    {200, 200, 200, 200, 200},
    {100,   0,   0,   0,  50},
    {100,   0,   0,   0,  60},
    {100,   0,   0,   0,  70},
    {  0,   0,   0,   0,   0}
  };

  solve(u, 1, 2);
  for(row = 0; row < DIM; ++row)
  {
    for(col = 0; col < DIM; ++col)
    {
      printf("%f ", u[row][col]);
    }
    printf("\n");
  }
  return 0;
}
