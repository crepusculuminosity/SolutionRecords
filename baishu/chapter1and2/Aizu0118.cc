#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int m, n;
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int ans;
char gh[MAXN][MAXN];

void dfs(int x, int y) {
  char ch = gh[x][y];
  gh[x][y] = 'o';
  for (int i = 0; i < 4; i++) {
    int xx = x + dir[i][0], yy = y + dir[i][1];
    if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && gh[xx][yy] == ch)
      dfs(xx, yy);
  }
}

int main() {
  // freopen("data.in","r",stdin);

  while (scanf("%d%d", &n, &m) && n) {
    ans = 0;
    getchar();
    /* code */
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        gh[i][j] = getchar();
      }
      getchar();
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (gh[i][j] != 'o') {
          dfs(i, j);
          ans++;
        }
      }
    }
    printf("%d\n", ans);
  }
}