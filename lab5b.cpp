#include <bits/stdc++.h>

#include "Tridiagonal.hpp"
using namespace std;
/*
    xy'' + 3y' + (1+x)y = 1 + x^2
    y(0) = 1, y(4) = 0 find y at x = 1, 2, 3
    using Finite difference method (dirchlit's condition)
    put y' = (yi+1 - yi-1) / 2h
    y'' = (yi+1 -2yi + yi-1) / h^2
*/
void show(vector<double>& v) {
    for (auto& i : v) {
        cout << i << " ";
    }
    cout << endl;
}
void build_and_solve_linear_eqs(const array<function<double(double)>, 4>& coeff,
                                vector<double> x, double y0, double yn) {
    int n = (int)x.size() - 1;
    vector<double> a(n), b(n), c(n), d(n);

    for (int i = 1; i < n; i++) {
        if (i != 1) {  // coeff of yi-1 in equation i
            a[i] = coeff[0](x[i]);
        }

        b[i] = coeff[1](x[i]);  // coeff of yi in equation i

        if (i != n - 1) {  // coeff of yi+1 in equation i
            c[i] = coeff[2](x[i]);
        }

        if (i == 1) {  // constant term in equation i
            d[i] = -coeff[3](x[i]) - coeff[0](x[i]) * y0;
        } else if (i == n - 1) {
            d[i] = -coeff[3](x[i]) - coeff[2](x[i]) * yn;
        } else {
            d[i] = -coeff[3](x[i]);
        }
    }
    b[1] += 4;
    d[1] += 167;
    // show(a), show(b), show(c), show(d);
    auto ans = TriDiagonal::solve(a, b, c, d);
    show(ans);
}

template <double h>
[[nodiscard]] constexpr const array<function<double(double)>, 4> helper(
    const array<function<double(double)>, 4>& coeff) {
    static_assert(h > 0, "");
    return array<function<double(double)>, 4>{
        [&](double x) -> double {
            return coeff[0](x) / (h * h) - coeff[1](x) / (2 * h);
        },
        [&](double x) -> double {
            return coeff[2](x) - 2 * coeff[0](x) / (h * h);
        },
        [&](double x) -> double {
            return coeff[0](x) / (h * h) + coeff[1](x) / (2 * h);
        },
        [&](double x) -> double { return coeff[3](x); }};
}

int main() {
    array<function<double(double)>, 4> coeff{
        // coeff of [x]y'' + [3]y' + [1+x]y +[-1-x^2] = 0
        [](double x) { return x; }, [](double x) { return 3; },
        [](double x) { return 1 + x; }, [](double x) { return -1 - x * x; }};

    build_and_solve_linear_eqs(helper<1.0>(coeff), {0, 1, 2, 3, 4}, 1, 0);

    return 0;
}
