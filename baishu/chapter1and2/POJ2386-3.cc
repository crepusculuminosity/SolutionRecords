#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 110;
int n, m;
char gh[maxn][maxn];
int ans;
struct node {
  int x, y;
};

void bfs(int a, int b) {
  ++ans;
  queue<node> q;
  q.push(node{a, b});
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    int sx = u.x, sy = u.y;
    // gh[sx][sy]='.';//如果把修改放在这里，那么会造成结点重复入队，如果W太多就会TLE/MLE
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (dx == 0 && dy == 0)
          continue;
        int xx = sx + dx, yy = sy + dy;
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && gh[xx][yy] == 'W') {
          q.push(node{xx, yy});
          gh[xx][yy] = '.'; //避免重复入队
        }
      }
    }
  }
}

void dfs(int a, int b) {
  ++ans;
  stack<node> s;
  s.push(node{a, b});
  while (!s.empty()) {
    node u = s.top();
    s.pop();
    int sx = u.x, sy = u.y;
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        int xx = sx + dx, yy = sy + dy;
        if (dx == 0 && dy == 0)
          continue;
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && gh[xx][yy] == 'W') {
          s.push(node{xx, yy});
          gh[xx][yy] = '.';
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;
  getchar();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      gh[i][j] = getchar();
    getchar();
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (gh[i][j] == 'W')
        dfs(i, j);
  cout << ans;
  return 0;
}