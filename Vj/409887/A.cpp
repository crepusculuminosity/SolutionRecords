#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 25;
char gh[MAXN][MAXN];
int vis[MAXN][MAXN];
int m, n, sx, sy, ans;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void dfs(int x, int y) {
  ans++;
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int xx = x + dir[i][0];
    int yy = y + dir[i][1];
    if (xx >= 0 && xx < n && yy < m && yy >= 0 && !vis[xx][yy] &&
        gh[xx][yy] == '.')
      dfs(xx, yy);
  }
}

int main() {
  while (scanf("%d%d", &m, &n) && m && n) {
    memset(vis, 0, sizeof(vis));
    getchar();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        gh[i][j] = getchar();
        if (gh[i][j] == '@')
          sx = i, sy = j;
      }
      getchar();
    }
    ans = 0;
    dfs(sx, sy);
    printf("%d\n", ans);
    /* code */
  }
  return 0;
}