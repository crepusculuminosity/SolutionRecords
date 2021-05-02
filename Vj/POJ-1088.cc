#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, m;
int a[110][110];
int dp[110][110];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int dfs(int x, int y) {
  if (dp[x][y])
    return dp[x][y];
  dp[x][y] = 1;
  int tmp = 0;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] < a[x][y])
      tmp = max(tmp, dfs(xx, yy));
  }
  return dp[x][y] += tmp;
}

int main() {
 //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> a[i][j];
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      ans = max(ans, dfs(i, j));
  cout << ans;
  return 0;
}