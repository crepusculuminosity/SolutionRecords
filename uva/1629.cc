#include <bits/stdc++.h>
using namespace std;
int a[30][30], sum[30][30];
int dp[30][30][30][30];
int n, m, k;
constexpr int INF = 0x3f3f3f3f;

int cnt(int i, int j, int k, int l) {
  return sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1];
}
int dfs(int i, int j, int k, int l) {
  if (~dp[i][j][k][l])
    return dp[i][j][k][l];
  if (cnt(i, j, k, l) == 0)
    return dp[i][j][k][l] = INF;
  if (cnt(i, j, k, l) == 1)
    return dp[i][j][k][l] = 0;
  int &res = dp[i][j][k][l];
  int tmp = INF;
  for (int t = j; t < l; t++) {
    if (cnt(i, j, k, t) && cnt(i, t + 1, k, l))
      tmp = min(tmp, dfs(i, j, k, t) + dfs(i, t + 1, k, l) + k - i + 1);
  }
  res = tmp;
  tmp = INF;
  for (int t = i; t < k; t++)
    if (cnt(i, j, t, l) && cnt(t + 1, j, k, l))
      tmp = min(tmp, dfs(i, j, t, l) + dfs(t + 1, j, k, l) + l - j + 1);
  res = min(res, tmp);
  return res;
}
int main() {

  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int T = 0;
  while (cin >> n >> m >> k) {
    memset(dp, -1, sizeof(dp));
    memset(a, 0, sizeof(a));
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= k; i++) {
      int u, v;
      cin >> u >> v;
      a[u][v] = 1;
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    cout << "Case " << ++T << ": " << dfs(1, 1, n, m) << '\n';
  }
  return 0;
}