// solution of tridiagonal system

#include <bits/stdc++.h>
using namespace std;

// #define printVector(x) for(auto it : x) cout << it << " "; cout << endl;

int main()
{
    int n;
    cin >> n;

    // one based indexing
    vector<vector<double>> matA(n+1 , vector<double> (n+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> matA[i][j];
        }
    }

    vector<double> a(n+1), b(n+1), c(n+1), d(n+1);
    for(int i = 1; i <= n; i++) a[i] = matA[i][i-1];

    for(int i = 0; i <= n; i++) b[i] = matA[i][i];

    for(int i = 0; i <= n-1; i++) c[i] = matA[i][i+1];

    for(int i = 1; i <= n; i++) cin >> d[i];

    vector<double> alpha(n+1), beta(n+1), x(n+1);

    // Step 1
    alpha[1] = b[1];
    for(int i = 2; i <= n; i++) alpha[i] = b[i] - a[i] * c[i-1] / alpha[i-1];

    // Step 2
    beta[1] = d[1] / b[1];
    for(int i = 2; i <= n; i++) beta[i] = (d[i] - a[i] * beta[i-1]) / alpha[i];

    // Step 3
    x[n] = beta[n];
    for(int i = n-1; i >= 1; i--) x[i] = beta[i] - c[i] * x[i+1] / alpha[i];

    for(int i = 1; i <= n; i++) cout << "x" << i << " = " << x[i] << endl;

    return 0;
}