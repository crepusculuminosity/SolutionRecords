#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 110;
double dp[maxn][maxn];
int a, b, n;
double p;

int solve() {
  p = a * 1.0 / b;
  dp[0][0] = 1.0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; b * j <= a * i; j++) {
      dp[i][j] = (1 - p) * dp[i - 1][j];
      if (j)
        dp[i][j] += p * dp[i - 1][j - 1];
    }
  }
  double res = 0;
  for (int j = 0; b * j <= a * n; j++)
    res += dp[n][j];
  return 1.0 / res;
}

int main() {
  // freopen("data.in", "r", stdin);
  int _, kse = 1;
  scanf("%d", &_);
  while (_--) {
    memset(dp, 0, sizeof(dp));
    scanf("%d/%d%d", &a, &b, &n);
    printf("Case #%d: %d\n", kse++, solve());
  }
}