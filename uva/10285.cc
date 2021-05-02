#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 110;
int a[maxn][maxn];
int n, m;
int dp[maxn][maxn];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int cnt = 0;

int dfs(int i, int j) {
  if (~dp[i][j])
    return dp[i][j];
  int &res = dp[i][j] = 1;
  int tmp = 0;
  int u, v;
  for (int k = 0; k < 4; k++) {
    // tmp = 0;
    int xx = i + dx[k], yy = j + dy[k];
    if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] < a[i][j] &&
        __gcd(a[xx][yy], a[i][j]) > 1) {
      tmp = max(tmp, dfs(xx, yy));
    }
  }
  res += tmp;
  return res;
}

void print(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m)
    return;
  if (cnt++ == 0)
    cout << a[x][y];
  else
    cout << ' ' << a[x][y];
  int tmp = 0, sx, sy;
  for (int k = 0; k < 4; k++) {
    int xx = x + dx[k], yy = y + dy[k];
    if (x >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] < a[x][y] &&
        __gcd(a[xx][yy], a[x][y]) > 1) {
      if (tmp < dp[xx][yy])
        tmp = dp[xx][yy], sx = xx, sy = yy;
    }
  }
  if (tmp)
    print(sx, sy);
}
int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out","w",stdout);
  ios::sync_with_stdio(false);
  cout.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  char str[20];
  while (_--) {
    cnt = 0;
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
        if (dfs(i, j) > ans)
          ans = dfs(i, j), sx = i, sy = j;
      }
    cout << str << ": " << ans << '\n';
    print(sx, sy);
    cout << '\n';
  }
  return 0;
}