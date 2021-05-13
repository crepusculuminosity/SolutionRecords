#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 1000 + 10;
const int INF = 0x3f3f3f3f;
int n, m, d[maxn], vis[maxn], num[maxn];
struct node {
  int to, w;
};
vector<node> G[maxn];
inline void addedge(int u, int v, int w) { G[u].push_back(node{v, w}); }
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}
bool SPFA(int s) {
  for (int i = 1; i <= n; i++)
    vis[i] = 0, num[i] = 0, d[i] = -INF;
  d[s] = 0, vis[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = 0; i < G[u].size(); i++) {
      node &e = G[u][i];
      if (d[e.to] < d[u] + e.w) {
        d[e.to] = d[u] + e.w;
        if (!vis[e.to]) {
          vis[e.to] = 1;
          q.push(e.to);
          if (++num[e.to] == n + 1)
            return 0;
        }
      }
    }
  }
  return 1;
}
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  while (~scanf("%d%d", &n, &m)) {
    bool f = 1;
    for (int i = 0; i <= n; i++)
      G[i].clear();
    char ch[5];
    while (m--) {
      scanf("%s", ch);
      if (ch[0] == 'P') {
        int a = read(), b = read(), c = read();
        if (a == b && c)
          f = 0;
        // cout << a << ' ' << b << ' ' << c << endl;
        addedge(b, a, c);
        addedge(a, b, -c);
      } else {
        int a = read(), b = read();
        if (a == b)
          f = 0;
        // cout << a << ' ' << b << endl;
        addedge(b, a, 1);
      }
    }
    for (int i = 1; i <= n; i++)
      addedge(0, i, 0);
    if (f && SPFA(0))
      puts("Reliable");
    else
      puts("Unreliable");
  }
  return 0;
}