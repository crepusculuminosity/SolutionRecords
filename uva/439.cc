#include <bits/stdc++.h>
using namespace std;
int vis[10][10];
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {-1, 1, 1, -1, -2, 2, 2, -2};
struct node {
  int x, y;
  int step;
};
int sx, sy;

int bfs(node &x) {
  x.step = 0;
  queue<node> q;
  q.push(x);
  vis[x.x][x.y] = 1;
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    int x = u.x, y = u.y, s = u.step;
    if (x == sx && y == sy)
      return s;
    for (int i = 0; i < 8; i++) {
      // int x=u.x, y=u.y;
      int xx = x + dx[i], yy = y + dy[i];
      if (xx >= 1 && xx <= 8 && yy >= 1 && yy <= 8 && !vis[xx][yy]) {
        q.push(node{xx, yy, s + 1});
        vis[xx][yy] = 1;
      }
    }
  }
  return -1;
}
int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  char s1[5], s2[5];
  while (~scanf("%s%s", s1, s2)) {
    memset(vis, 0, sizeof(vis));
    node n1 = node{s1[0] - 'a' + 1, (int)s1[1] - '0'};
    sx = s2[0] - 'a' + 1, sy = (int)s2[1] - '0';
    // cout << bfs(n1) << '\n';
    printf("To get from %s to %s takes %d knight moves.\n", s1, s2, bfs(n1));
  }
  return 0;
}