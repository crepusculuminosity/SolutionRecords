#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 200000 + 10;
int d[maxn], vis[maxn], num[maxn];
int n, m;
struct node {
  int to, w;
};
vector<node> G[maxn];
void add(int u, int v, int w) { G[u].push_back(node{v, w}); }
int SPFA() {
  memset(d, 0x3f, sizeof(d));
  d[0] = 0, vis[0] = 1, num[0] = 1;
  deque<int> q;
  q.push_back(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    vis[u] = 0;
    for (int i = 0; i < G[u].size(); i++) {
      node &e = G[u][i];
      if (d[e.to] > d[u] + e.w) {
        d[e.to] = d[u] + e.w;
        if (!vis[e.to]) {
          vis[e.to] = 1;
          num[e.to]++;
          if (num[e.to] * num[e.to] > n + 1)
            return -1;
          if (!q.empty() && d[e.to] < d[q.front()])
            q.push_front(e.to);
          else
            q.push_back(e.to);
        }
      }
    }
  }
  return d[n];
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int main() {
  n = read(), m = read();
  while (m--) {
    int u = read(), v = read();
    add(u - 1, v, 1), add(v, u - 1, -1);
  }
  for (int i = 1; i <= n; i++)
    add(i, i - 1, 0), add(i - 1, i, 1);
  printf("%d", SPFA());
  return 0;
}