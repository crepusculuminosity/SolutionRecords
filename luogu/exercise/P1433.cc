#include <bits/stdc++.h>
using namespace std;
double dp[1 << 16][17], dis[17][17], x[17], y[17];
int n;

void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%lf%lf", x + i, y + i);
  x[0] = y[0] = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      dis[i][j] =
          sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
  memset(dp, 127, sizeof(dp));
}

void solve() {
  for (int i = 0; i <= n; i++)
    dp[(1 << n + 1) - 1][i] = 0;
  for (int S = (1 << n + 1) - 2; ~S; S--)
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++)
        if (!(S & 1 << j))
          dp[S][i] = min(dp[S][i], dp[S | 1 << j][j] + dis[i][j]);

  printf("%.2lf", dp[0][0]);
}

int main() {
  // freopen("data.in", "r", stdin);
  init();
  solve();
  return 0;
}