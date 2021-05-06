#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int f[15][15][15][15];

int main() {
  int n;
  cin >> n;
  int u, v, w;
  while (cin >> u >> v >> w && u && v && w)
    a[u][v] = w;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        for (int l = 1; l <= n; l++) {
          f[i][j][k][l] =
              max(f[i - 1][j][k - 1][l],
                  max(f[i][j - 1][k - 1][l],
                      max(f[i - 1][j][k][l - 1], f[i][j - 1][k][l - 1]))) +
              a[i][j] + a[k][l];
          if (i == k && j == l)
            f[i][j][k][l] -= a[i][j];
        }
  cout << f[n][n][n][n];
  return 0;
}