#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1010;
constexpr int INF = 0x3f3f3f3f;
int n, m;
char a[maxn][maxn];
int vis[maxn][maxn], t[maxn][maxn];
int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, -1};

struct node {
  int x, y, t;
  node(int x, int y, int t) : x(x), y(y), t(t) {}
};

int main() {
  /// freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  // int _;
  // scanf("%d", &_);
  // while (_--) {
  memset(vis, 0, sizeof(vis));
  memset(t, 0x3f, sizeof(t));
  scanf("%d%d", &n, &m);
  int sx, sy;
  queue<node> q;
  for (int i = 1; i <= n; i++)
    scanf("%s", a[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 'J')
        sx = i, sy = j;
      if (a[i][j] == 'F') {
        q.push(node{i, j, 0});
        t[i][j] = 0;
      }
    }

  while (!q.empty()) {
    node u = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int xx = u.x + dx[i], yy = u.y + dy[i];
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] != '#' &&
          t[xx][yy] == INF) {
        q.push(node{xx, yy, 0});
        t[xx][yy] = t[u.x][u.y] + 1;
      }
    }
  }
  bool f = 0;
  q.push(node{sx, sy, 0});
  vis[sx][sy] = 1;
  while (!q.empty()) {
    node u = q.front();
    // cout<<u.x<<' '<<u.y<<' '<<u.t<<endl;
    q.pop();
    if (u.x == 1 || u.x == n || u.y == 1 || u.y == m) {
      printf("%d\n", u.t + 1);
      f = 1;
      break;
    }
    for (int i = 0; i < 4; i++) {
      int xx = u.x + dx[i], yy = u.y + dy[i];
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] != '#' &&
          !vis[xx][yy] && t[xx][yy] > u.t + 1) {
        q.push(node{xx, yy, u.t + 1});
        vis[xx][yy] = 1;
      }
    }
  }
  if (!f)
    printf("IMPOSSIBLE\n");
  //}
  return 0;
}