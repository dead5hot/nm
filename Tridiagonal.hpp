#include <bits/stdc++.h>
class TriDiagonal {
   public:
    static std::vector<double> solve(std::vector<double>& a,
                                                   std::vector<double>& b,
                                                   std::vector<double>& c,
                                                   std::vector<double>& d) {
        int n = (int)a.size() - 1;
        std::vector<double> alpha(n + 1), beta(n + 1), x(n + 1);

        alpha[1] = b[1];
        for (int i = 2; i <= n; i++)
            alpha[i] = b[i] - a[i] * c[i - 1] / alpha[i - 1];

        beta[1] = d[1] / b[1];
        for (int i = 2; i <= n; i++)
            beta[i] = (d[i] - a[i] * beta[i - 1]) / alpha[i];

        x[n] = beta[n];
        for (int i = n - 1; i >= 1; i--)
            x[i] = beta[i] - c[i] * x[i + 1] / alpha[i];

        return x;
    }
};