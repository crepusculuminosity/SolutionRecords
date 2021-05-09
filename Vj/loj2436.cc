#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}
int n, m;
constexpr int maxn = 1e6 + 10;
struct node {
  int to, w;
};
vector<node> G[maxn];
int d[maxn], num[maxn], vis[maxn];
inline void addedge(int u, int v, int w) { G[u].push_back(node{v, w}); }

bool SPFA(int s) {
  memset(d, 0x3f, sizeof(d));
  d[s] = 0;
  vis[s] = 1;
  num[s]++;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = 0; i < G[u].size(); i++) {
      node &e = G[u][i];
      if (d[e.to] > d[u] + e.w) {
        d[e.to] = d[u] + e.w;
        if (!vis[e.to]) {
          q.push(e.to);
          vis[e.to] = 1;
          ++num[e.to];
          if (num[e.to] == n + 1)
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
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), a = read(), b = read();
    if (x == 1) {
      addedge(a, b, 0);
      addedge(b, a, 0);
    } else if (x == 2) {
      if (a == b) {
        puts("-1");
        return 0;
      }
      addedge(a, b, -1);
    } else if (x == 3)
      addedge(b, a, 0);
    else if (x == 4) {
      if (a == b) {
        puts("-1");
        return 0;
      }
      addedge(b, a, -1);
    } else
      addedge(a, b, 0);
  }
  for (int i = 1; i <= n; i++)
    addedge(0, i, -1);
  long long ans = 0;
  if (SPFA(0))
    for (int i = 1; i <= n; i++)
      ans -= d[i];
  else
    ans = -1;
  printf("%lld", ans);
  return 0;
}