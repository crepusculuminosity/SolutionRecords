#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[110][110], dp[110][110];
int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, -1};
int dfs(int i, int j) {
  if (~dp[i][j])
    return dp[i][j];
  int &res = dp[i][j] = a[i][j];
  int tmp = 0;
  for (int t = 1; t <= k; t++) {
    for (int i = 0; i < 4; i++) {
      int xx = i + t * dx[i], yy = j + t * dy[i];
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && a[xx][yy] > a[i][j]) {
        tmp = max(tmp, dfs(xx, yy));
      }
    }
  }
  res += tmp;
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  while (cin >> n >> k && ~n && ~k) {
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        cin >> a[i][j];
    int ans = -1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        cout << dfs(i, j) << ' ';
      cout << endl;
    }

    // cout << dp[1][1] << '\n';
    // cout << ans << '\n';
  }
  return 0;
}