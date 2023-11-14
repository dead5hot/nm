#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main()
{
  const double a = 2.0;
  const double dx = 2;
  const double dt = 1;
  const double L = 10.0;
  const int Nx = static_cast<int>(L / dx);
  const int Nt = 5; // Number of time steps

  std::vector<std::vector<double>> y(Nx, std::vector<double>(Nt, 0));

  // Initial condition
  for(int i = 0; i < Nx; i++)
  {
    y[i][0] = (i * dx * (L - i * dx)) / 100.0;
  }

  for(int j = 0; j < Nt - 1; j++)
  {
    for(int i = 1; i < Nx - 1; i++)
    {
      y[i][j + 1] = y[i][j] + (a * a * dt / (dx * dx)) * (y[i + 1][j] - 2 * y[i][j] + y[i - 1][j]);
    }
  }

  // Print the solution at the final time step
  std::cout << std::fixed << std::setprecision(2);
  for(int s = 1; s <= Nt; s++)
  {
    for(int i = 0; i < Nx; i++)
    {
      std::cout << std::setw(4) << y[i][s - 1] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
