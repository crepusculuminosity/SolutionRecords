#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 20000 + 10;
int vis[maxn], n, k, t[maxn];

void bfs() {
  int cur;
  int op = 1, step = 1;
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    vis[cur] = 1;
    if (cur == k) {
      cout << t[cur];
      return;
    }
    for (int i = 0; i < 2; i++) {
      if (i == 0 && op != 1 && step != 1) {
        op = 1, step = 1;
        t[cur]++;
        q.push(cur);
      } else {
        op = -op, step *= 2;
        int x = cur + op * step;
        if (x >= 1 && x <= maxn && !vis[x]) {
          q.push(x);
          t[x] = t[cur] + 1;
          vis[x] = 1;
        }
      }
    }
  }
}
int main() {
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  cin >> n >> k;
  bfs();
  return 0;
}