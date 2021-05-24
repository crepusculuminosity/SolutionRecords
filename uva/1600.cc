#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 30;
int a[maxn][maxn], m, n, k, vis[maxn][maxn][maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int ans;
struct node {
  int x, y, k, step;
};
int bfs() {
  queue<node> q;
  q.push(node{1, 1, 0, 0});
  vis[1][1][0] = 1;
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    if (u.x == n && u.y == m)
      return u.step;
    for (int i = 0; i < 4; i++) {
      int xx = u.x + dx[i], yy = u.y + dy[i];
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
        if (!a[xx][yy] && !vis[xx][yy][0]) {
          q.push(node{xx, yy, 0, u.step + 1});
          vis[xx][yy][u.k] = 1;
        } else if (a[xx][yy] && u.k < k && !vis[xx][yy][u.k + 1]) {
          q.push(node{xx, yy, u.k + 1, u.step + 1});
          vis[xx][yy][u.k + 1] = 1;
        }
      }
    }
  }
  return -1;
}
int main() {

  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    memset(vis, 0, sizeof(vis));
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cin >> a[i][j];
    cout << bfs() << '\n';
  }
  return 0;
}