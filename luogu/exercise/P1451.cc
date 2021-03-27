#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int ans;
int a[110][110];

struct node {
  int x, y;
};

void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy]) {
      a[xx][yy] = 0;
      dfs(xx, yy);
    }
  }
}

void bfs(int x, int y) {
  ++ans;
  a[x][y] = 0;
  queue<node> q;
  q.push(node{x, y});
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    int sx = u.x, sy = u.y;
    for (int i = 0; i < 4; i++) {
      int xx = sx + dx[i], yy = sy + dy[i];
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy]) {
        a[xx][yy] = 0;
        q.push(node{xx, yy});
      }
    }
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      a[i][j] = c - 48;
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        //++ans;
        // dfs(i,j);
        bfs(i, j);
      }
    }
  }
  cout << ans;
  return 0;
}