#include <bits/stdc++.h>
using namespace std;
int n, m;
constexpr int maxn = 510;
bool vis[maxn][maxn];
char a[maxn][maxn];
int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool f;

void dfs(int x, int y) {
  if (a[x][y] == 'E') {
    f = 1;
    return;
  }
  for (int i = 0; i < 4; i++) {
    int xx = x + dir[i][0], yy = y + dir[i][1];
    if (a[xx][yy] != '#' && !vis[xx][yy] && xx >= 1 && xx <= n && yy >= 1 &&
        yy <= m) {
      vis[xx][yy] = 1;
      dfs(xx, yy);
    }
  }
}

int main() {
  // freopen("data.in", "r",stdin);
  while (cin >> n >> m) {
    memset(vis, 0, sizeof(vis));
    memset(a, 0, sizeof(a));
    int x, y;
    f = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'S')
          x = i, y = j;
      }
    }
    dfs(x, y);
    if (f)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}