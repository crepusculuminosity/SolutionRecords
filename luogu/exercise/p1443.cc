#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair
int a[410][410];
bool vis[410][410];
int n, m, x, y;

const int dx[] = {2, 1, -2, -1, -2, -1, 2, 1};
const int dy[] = {1, 2, 1, 2, -1, -2, -1, -2};

queue<pair<int, int>> q;

int main() {
  // freopen("data.out", "w",stdout);
  memset(a, -1, sizeof(a));
  scanf("%d%d%d%d", &n, &m, &x, &y);
  a[x][y] = 0, vis[x][y] = 1, q.push(mkp(x, y));
  while (!q.empty()) {
    int xx = q.front().first, yy = q.front().second;
    q.pop();
    for (int i = 0; i < 8; i++) {
      int uu = xx + dx[i], vv = yy + dy[i];
      if (uu < 1 || uu > n || vv < 1 || vv > m || vis[uu][vv])
        continue;
      vis[uu][vv] = 1;
      q.push(mkp(uu, vv));
      a[uu][vv] = a[xx][yy] + 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%-5d", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
