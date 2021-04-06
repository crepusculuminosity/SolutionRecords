#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 110;
int a[maxn][maxn];
int n, m;
int dp[maxn][maxn];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int cnt = 0;
int path[maxn*maxn];
int dfs(int i, int j) {
  if (~dp[i][j])
    return dp[i][j];
  int &res = dp[i][j] = 1;
  int tmp = 0;
  int u,v;
  for (int k = 0; k < 4; k++) {
    // tmp = 0;
    int xx = i + dx[k], yy = j + dy[k];
    if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] < a[i][j]) {
      tmp = max(tmp, dfs(xx, yy));
      u=xx,v=yy;
    }
  }
  res += tmp;
  return res;
}

int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cout.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  char str[20];
  while (_--) {
    memset(dp, -1, sizeof(dp));
    cin >> str >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++)
        cin >> a[i][j];
    }
    int ans = -1;
    int sx, sy;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        ans = max(ans, dfs(i, j));
        sx=i,sy=j;
      }
    cout << str << ": " << ans << '\n';
  }
  return 0;
}