#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
int mp[25][25];
int dir[5][5] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int mins, sx, sy;
int n, m;
const int inf = 0x3f3f3f3f;

void dfs(int x, int y, int step) {
  step++;
  if (step > 10)
    return;
  for (int i = 0; i < 4; i++) {
    int xx = x + dir[i][0], yy = y + dir[i][1];
    if (mp[xx][yy] == 1)
      continue;

    while (mp[xx][yy] == 0 || mp[xx][yy] == 2) {
      xx += dir[i][0];
      yy += dir[i][1];
    }
    if (mp[xx][yy] == -1)
      continue;

    if (mp[xx][yy] == 1) {
      mp[xx][yy] = 0;
      dfs(xx - dir[i][0], yy - dir[i][1], step);
      mp[xx][yy] = 1;
    }

    if (mp[xx][yy] == 3) {
      if (step < mins)
        mins = step;
      continue;
    }
  }
}

int main() {
  // freopen("data.in","r",stdin);

  while (~scanf("%d%d", &m, &n) && n && m) {
    mins = inf;
    memset(mp, -1, sizeof(mp));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf("%d", &mp[i][j]);
        if (mp[i][j] == 2)
          sx = i, sy = j;
      }
    }
    dfs(sx, sy, 0);
    if (mins < inf)
      printf("%d\n", mins);
    else
      printf("-1\n");
  }
  return 0;
}