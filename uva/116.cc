#include <bits/stdc++.h>
using namespace std;
int a[20][110], dp[20][110];
int n, m;
int d[] = {-1, 0, 1};
void print(int i, int j) {
  if (j > m)
    return;
  cout << i << ' ';
  int x, y;
  x = 0x3f3f3f3f;
  for (int k = 0; k < 3; k++) {
    int tmp;
    int s = i + d[k];
    if (s < 1)
      s = n;
    if (s == n + 1)
      s = 1;
    if (dp[s][j + 1] - a[s][j + 1] == dp[i][j])
      tmp = s;
    x = min(x, tmp);
  }
  print(x, j + 1);
}
int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  // cin >> n >> m;
  while (cin >> n >> m) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cin >> a[i][j];
    for (int i = 1; i <= n; i++)
      dp[i][1] = a[i][1];
    for (int j = 2; j <= m; j++)
      for (int i = 1; i <= n; i++)
        dp[i][j] = a[i][j] + min(dp[i - 1 == 0 ? n : i - 1][j - 1],
                                 min(dp[i][j - 1],
                                     dp[i + 1 == n + 1 ? 1 : i + 1][j - 1]));
    int ans = 0x3f3f3f3f, tmp = ans;
    int sy;
    for (int i = 1; i <= n; i++) {
      if (tmp > dp[1][i])
        sy = i, tmp = dp[1][i];
    }
    print(sy, 1);
    cout << '\n';
    for (int i = 1; i <= n; i++)
      ans = min(ans, dp[i][m]);
    cout << ans << '\n';
  }
  return 0;
}