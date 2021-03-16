#include <bits/stdc++.h>
using namespace std;
char gh[110][110];
int n, m, vis[110][110];

void dfs(int x, int y) {
  if (x > n || x < 1 || y > m || y < 1)
    return;
  if (vis[x][y] || gh[x][y] != '@')
    return;
  vis[x][y] = 1;
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      if (dy == 0 && dx == 0)
        continue;
      int xx = x + dx, yy = y + dy;
      dfs(xx, yy);
    }
  }
}

int main() {
  // freopen("data.in", "r", stdin);
  while (scanf("%d%d", &n, &m) == 2 && n && m) {
    getchar();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        gh[i][j] = getchar();
      }
      getchar();
    }

    int ans = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (vis[i][j] == 0 && gh[i][j] == '@')
          ++ans, dfs(i, j);
      }
    }
    printf("%d\n", ans);
  }
}