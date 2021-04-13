#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
int a[310][310];
int m;
struct node {
  int x, y, t;
};
int dx[] = {1, 0, -1, 0, 0};
int dy[] = {0, 1, 0, -1, 0};

int bfs() {
  queue<node> q;
  if (a[0][0])
    q.push({0, 0, 0});
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    int x = u.x, y = u.y, t = u.t;
    if (a[x][y] == INF)
      return t;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx >= 0 && yy >= 0 && t + 1 < a[xx][yy]) {
        if (a[xx][yy] != INF)
          a[xx][yy] = t + 1;
        q.push({xx, yy, t + 1});
      }
    }
  }
  return -1;
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  memset(a, 0x3f, sizeof(a));
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    for (int i = 0; i < 5; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx >= 0 && xx <= 300 && yy >= 0 && yy <= 300)
        a[xx][yy] = min(t, a[xx][yy]);
    }
  }
  cout << bfs();
  return 0;
}