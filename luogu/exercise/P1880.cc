#include <bits/stdc++.h>
using namespace std;
int dp[2][220][220];
int sum[220], a[220];
constexpr int maxn = 0x7fffffff;

int dfs(int o, int i, int j) {
  if (dp[o][i][j])
    return dp[o][i][j];
  if (j == i)
    return 0;
  int &res = dp[o][i][j];
  if (o == 0) {
    res = maxn;
    for (int k = i; k < j; k++)
      res = min(res, dfs(o, i, k) + dfs(o, k + 1, j) + sum[j] - sum[i - 1]);
  } else {
    res = 0;
    for (int k = i; k < j; k++)
      res = max(res, dfs(o, i, k) + dfs(o, k + 1, j) + sum[j] - sum[i - 1]);
  }
  return res;
}

int main() {
  // freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i], a[i + n] = a[i];
  for (int i = 1; i <= 2 * n; i++)
    sum[i] = sum[i - 1] + a[i];
  dfs(0, 1, n * 2), dfs(1, 1, n * 2);
  int ans1 = maxn, ans2 = 0;
  for (int i = 1; i <= n; i++)
    ans1 = min(dp[0][i][n + i - 1], ans1),
    ans2 = max(dp[1][i][n + i - 1], ans2);
  cout << ans1 << endl << ans2;
  return 0;
}