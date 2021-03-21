#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005][1005], vis[1005][1005];

bool flag;
int dth, k;
int ans;

inline int read() {
  int x = 0, f = 1; //
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

void dfs(int x, int y) {
  if (flag == 1)
    return;
  if (x == n && y == n) {
    flag = 1;
    return;
  }
  vis[x][y] = 1; //******

  int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
  for (int i = 0; i < 4; i++) {
    int xc = x + dir[i][0], yc = y + dir[i][1];
    if (vis[xc][yc] == 0 && xc >= 1 && xc <= n && yc >= 1 && xc <= n) {
      if (a[xc][yc] < dth) {
        continue;
      }
      dfs(xc, yc);
    }
  }
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = read();
    }
  }
  int l = 0, r = 100000;

  while (l <= r) {
    memset(vis, 0, sizeof(vis));
    flag = 0;
    dth = (l + r) >> 1;
    if (dth > a[1][1] || dth > a[n][n]) {
      r = dth - 1;
      continue;
    }

    dfs(1, 1);
    if (flag) {
      l = dth + 1;
      ans = dth;
    } else
      r = dth - 1;
  }
  int q = read();
  while (q--) {
    int water = read();
    if (water > ans)
      printf("Hmmm\n");
    else
      printf("Wuhu\n");
  }
  return 0;
}