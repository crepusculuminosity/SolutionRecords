#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 5050;
int sum[maxn][maxn];
int n, r;
int main() {
  cin >> n >> r;
  int x, y, v;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y >> v;
    sum[x + 1][y + 1] = v;
  }
  for (int i = 1; i <= 5001; i++)
    for (int j = 1; j <= 5001; j++)
      sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
  int res = 0;
  for (int i = r; i <= 5001; i++)
    for (int j = r; j <= 5001; j++)
      res = max(res,
                sum[i][j] - sum[i - r][j] - sum[i][j - r] + sum[i - r][j - r]);
  cout << res;
  return 0;
}