#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>
#include <iomanip>

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

#endif