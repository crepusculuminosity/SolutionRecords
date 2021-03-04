#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 110;
int vis[maxn][maxn], n, sum[maxn], a[maxn], dp[maxn][maxn];

int dfs(int i, int j) {
  if (vis[i][j])
    return dp[i][j];
  vis[i][j] = 1;
  int res = 0;
  for (int k = i + 1; k <= j; k++)
    res = min(res, dfs(k, j));
  for (int k = i; k < j; k++)
    res = min(res, dfs(i, k));
  dp[i][j] = sum[j] - sum[i - 1] - res;
  return dp[i][j];
}

int main() {
  // freopen("data.in", "r", stdin);
  while (scanf("%d", &n) && n) {
    memset(sum, 0, sizeof(sum));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      sum[i] = sum[i - 1] + x;
    }
    printf("%d\n", 2 * dfs(1, n) - sum[n]);
  }
  return 0;
}