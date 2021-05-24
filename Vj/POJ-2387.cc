#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1010;
int n, m, d[maxn], vis[maxn], num[maxn];
struct node {
  int to, w;
};
vector<node> G[maxn];
inline void addedge(int u, int v, int w) { G[u].push_back(node{v, w}); }
struct Hnode {
  int d, u;
  bool operator<(const Hnode &x) const { return d > x.d; }
};
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}

void dijkstra() {
  d[1] = 0;
  priority_queue<Hnode> q;
  q.push(Hnode{0, 1});
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
}

void SPFA() {
  queue<int> q;
  q.push(1);
  vis[1] = 1, d[1] = 0, num[1] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = 0; i < G[u].size(); i++) {
      node &e = G[u][i];
      if (d[e.to] > d[u] + e.w) {
        d[e.to] = d[u] + e.w;
        if (!vis[e.to]) {
          vis[e.to] = 1;
          ++num[e.to];
          q.push(e.to);
        }
      }
    }
  }
}
int main() {
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  m = read(), n = read();
  memset(d, 0x3f, sizeof(d));
  while (m--) {
    int u = read(), v = read(), w = read();
    addedge(u, v, w);
    addedge(v, u, w);
  }
  SPFA();
  printf("%d\n", d[n]);
  return 0;
}