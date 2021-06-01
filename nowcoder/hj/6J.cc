#include <bits/stdc++.h>
using namespace std;
int sx, sy, xe, ye;
struct node {
  int x, y, step;
};
const int maxn = 110;
char g[maxn][maxn];
int vis[maxn][maxn];
int n, m;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int main() {
  cin >> n >> m >> sx >> sy >> xe >> ye;
  for (int i = 1; i <= n; i++)
    cin >> (g[i] + 1);
  queue<node> q;
  q.push(node{sx, sy, 0});
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    if (u.x == xe && u.y == ye) {
      cout << 100 * u.step;
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int xx = u.x + dx[i], yy = u.y + dy[i];
      if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !vis[xx][yy] &&
          g[xx][yy] != '#') {
        q.push(node{xx, yy, u.step + 1});
        vis[xx][yy] = 1;
      }
    }
  }
  cout << "-1";
  return 0;
}