#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2010;
int a[maxn][maxn], vis[maxn][maxn];
struct node {
  int x, y, step;
};
int n, m, k;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int sx, sy, ans = 0;
  queue<node> q;
  cin >> n >> m >> k;
  while (k--) {
    int u, v;
    cin >> u >> v;
    q.push(node{u, v, 0});
    vis[u][v] = 1;
    sx = u, sy = v;
  }
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    if (ans < u.step)
      sx = u.x, sy = u.y, ans = u.step;
    for (int i = 0; i < 4; i++) {
      int xx = u.x + dx[i], yy = u.y + dy[i];
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !vis[xx][yy]) {
        q.push(node{xx, yy, u.step + 1});
        vis[xx][yy] = 1;
      }
    }
  }
  cout << sx << ' ' << sy;
  return 0;
}