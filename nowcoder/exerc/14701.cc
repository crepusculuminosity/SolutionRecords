#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e3 + 10;
int dp[maxn][maxn], a[maxn], b[maxn];
int n;

inline int dfs(int l, int r) {
  if (dp[l][r])
    return dp[l][r];
  if (l == r)
    return dp[l][r] = b[n] * a[l];
  int &res = dp[l][r] = 0;
  res = max(b[n - r + l] * a[l] + dfs(l + 1, r),
            b[n - r + l] * a[r] + dfs(l, r - 1));
  return res;
}

int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
      scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
      scanf("%d", b + i);
    printf("%d\n", dfs(1, n));
  }
  return 0;
}