#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
int n, m;
using namespace std;
const int maxn = 30000 + 10;
const int INF = 0x3f3f3f3f;
struct node {
  int to, w;
};
struct Hnode {
  int d, u;
  bool operator<(const Hnode &x) const { return d > x.d; }
};
vector<node> G[maxn];
inline void add(int u, int v, int w) { G[u].push_back(node{v, w}); }
int d[maxn], vis[maxn], num[maxn];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}
int dijkstra(int s) {
  memset(d, 0x3f, sizeof(d));
  d[s] = 0;
  priority_queue<Hnode> q;
  q.push(Hnode{0, s});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u])
      continue;
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); i++) {
      node &e = G[u][i];
      if (d[e.to] > d[u] + e.w) {
        d[e.to] = d[u] + e.w;
        q.push(Hnode{d[e.to], e.to});
      }
    }
  }
  return d[n];
}

int main() {

  // freopen("data.in", "r", stdin);
  // reopen("data.out", "w", stdout);
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    a = read(), b = read(), c = read();
    add(a, b, c);
  }

  printf("%d", dijkstra(1));
  return 0;
}