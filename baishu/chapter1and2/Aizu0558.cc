#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int h, w, n;
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
char gh[1005][1005];
int vis[1005][1005];
int ans;

struct node {
  int x, y, step;
} s;
queue<node> que;

void bfs(node a, char end) {
  while (!que.empty())
    que.pop();

  que.push(a);
  vis[a.x][a.y] = 1;

  while (!que.empty()) {
    node now = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      node next = now;
      next.x += dir[i][0], next.y += dir[i][1], ++next.step;
      if (next.x >= 1 && next.x <= h && next.y >= 1 && next.y <= w &&
          !vis[next.x][next.y] && gh[next.x][next.y] != 'X') {
        if (gh[next.x][next.y] == end) {
          ans += next.step;
          next.step = 0;
          s = next;
          return;
        }

        else {
          que.push(next);
          vis[next.x][next.y] = 1;
        }
      }
    }
  }
}

int main() {
  // freopen("data.in","r",stdin);

  scanf("%d%d%d", &h, &w, &n);
  getchar();
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      gh[i][j] = getchar();
      if (gh[i][j] == 'S')
        s.x = i, s.y = j, s.step = 0;
    }
    getchar();
  }

  for (int i = 1; i <= n; i++) {
    memset(vis, 0, sizeof(vis));
    bfs(s, i + '0');
  }
  printf("%d\n", ans);

  return 0;
}