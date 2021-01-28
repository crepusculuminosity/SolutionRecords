#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 25;
char gh[MAXN][MAXN];
int vis[MAXN][MAXN];
int m, n, ans, sx, sy;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void dfs(int x, int y) {
  ans++;
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int xx = x + dir[i][0], yy = y + dir[i][1];
    if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !vis[xx][yy] &&
        gh[xx][yy] == '.')
      dfs(xx, yy);
  }
}

int main() {
  freopen("data.in", "r", stdin);

  while (scanf("%d%d", &m, &n) && m) {
    /* code */
    ans = 0;
    memset(vis, 0, sizeof(vis));
    getchar();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        gh[i][j] = getchar();
        if (gh[i][j] == '@')
          sx = i, sy = j;
      }
      getchar();
    }
    dfs(sx, sy);
    printf("%d\n", ans);
  }
  return 0;
}