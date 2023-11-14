#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>

const double Precision = 1e-4;

template<typename _T>
std::ostream& operator<<(std::ostream& o, const std::vector<_T>& vector__t)
{
  for(auto _t : vector__t)
  {
    o << std::setw(6) << _t << " ";
  }

  return o;
}
template<typename _T>
std::ostream& operator<<(std::ostream& o, const std::vector<std::vector<_T>>& vector_vector__t)
{
  int precision = o.precision();
  o << std::fixed << std::setprecision(2);
  for(auto vector__t : std::vector<std::vector<_T>> (vector_vector__t.rbegin(), vector_vector__t.rend()))
  {
    o << vector__t << "\n";
  }

  o << std::defaultfloat << std::setprecision(precision);

  return o;
}

void solve(std::vector<std::vector<double>>& grid)
{
  int m = grid.size(), n = grid.at(0).size();
  
  int cnt = 0;
  while(true)
  {
    bool flag = true;

    for(int i = 1; i < m - 1; i++)
    {
      for(int j = 1; j < n - 1; j++)
      {
        auto initial_value = grid.at(i).at(j);
        grid.at(i).at(j) = (grid.at(i - 1).at(j) + grid.at(i + 1).at(j) +
        grid.at(i).at(j - 1) + grid.at(i).at(j + 1)) / 4;
        
        if(std::abs(grid.at(i).at(j) - initial_value) > Precision)
        {
          flag = false;
        }
      }
    }

    cnt++;

    if(flag)
    {
      break;
    }
  }
  // std::cout << "n_iterations: " << cnt << std::endl;
  // std::cout << grid << std::endl;
}



void initialize(std::vector<std::vector<double>>& grid)
{
  auto five_point = [&] (int i, int j, int h = 1)
  {
    grid.at(i).at(j) = (grid.at(i - h).at(j) + grid.at(i + h).at(j) +
    grid.at(i).at(j - h) + grid.at(i).at(j + h)) / 4;
  };
  five_point(2, 2, 2);

  auto five_point_diagonal = [&] (int i, int j)
  {
    grid.at(i).at(j) = (grid.at(i + 1).at(j + 1) + grid.at(i - 1).at(j - 1) +
    grid.at(i - 1).at(j + 1) + grid.at(i + 1).at(j - 1)) / 4;
  };

  five_point_diagonal(1, 1), five_point_diagonal(3, 1);
  five_point_diagonal(1, 3), five_point_diagonal(3, 3);

  five_point(1, 2), five_point(2, 3), five_point(2, 1), five_point(3, 2);

  // std::cout << grid << std::endl;

}
int main()
{
  std::vector<std::vector<double>> grid(5, std::vector<double>(5, 0));
  for(int i = 0; i <= 4; i++)
  {
    int y = 2 * i;
    grid.at(0).at(i) = y * y;
    grid.at(4).at(i) = 10 * y + 8;
  }
  for(int j = 0; j <= 4; j++)
  {
    int x = 2 * j;
    grid.at(j).at(0) = x;
    grid.at(j).at(4) = 3 * x + 64;
  }

  // std::cout << grid << std::endl;

  // {
  //   auto g = grid;
  //   solve(g);
  // }

  // {
  //   auto g = grid;
  //   initialize(g), solve(g);
  // }
  initialize(grid);
  solve(grid);

  std::cout << grid << std::endl;

  return 0;
}