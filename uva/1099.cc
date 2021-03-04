#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = (1 << 15) + 10;
int a[20];
int sum[maxn];
int vis[maxn][110];
int dp[maxn][110];

inline int cal(int x) {
  int res = 0;
  while (x)
    x -= (x & (-x)), ++res;
  return res;
}

int dfs(int S, int x) {
  if (vis[S][x])
    return dp[S][x];
  if (vis[S][sum[S] / x])
    return dp[S][sum[S] / x];
  vis[S][x] = 1;
  int &res = dp[S][x];
  if (cal(S) == 1)
    return res = 1;
  int y = sum[S] / x;
  for (int S0 = (S - 1) & S; S0; S0 = (S0 - 1) & S) {
    int S1 = S ^ S0;
    if (sum[S0] % x == 0 && dfs(S0, x) && dfs(S1, x))
      return res = 1;
    if (sum[S0] % y == 0 && dfs(S0, y) && dfs(S1, y))
      return res = 1;
  }
  return res = 0;
}

int main() {
  // freopen("data.in", "r", stdin);
  int n, x, y, kse = 0;
  while (~scanf("%d", &n) && n) {
    memset(vis, 0, sizeof(vis));
    memset(sum, 0, sizeof(sum));
    scanf("%d%d", &x, &y);
    for (int i = 0; i < n; i++)
      scanf("%d", a + i);
    for (int S = 0; S < (1 << n); S++)
      for (int i = 0; i < n; i++)
        if (S & (1 << i))
          sum[S] += a[i];
    int maxx = (1 << n) - 1, ans;
    if (sum[maxx] != x * y || sum[maxx] % x)
      ans = 0;
    else
      ans = dfs(maxx, x);
    printf("Case %d: %s\n", ++kse, ans ? "Yes" : "No");
  }
  return 0;
}