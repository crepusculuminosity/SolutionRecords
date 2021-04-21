#include <bits/stdc++.h>
using namespace std;
int n, m;
constexpr int maxn = 110;
struct Hnode {
  int d, u;
  bool operator<(const Hnode &x) const { return d > x.d; }
};
struct node {
  int to, cst;
};
vector<node> G[maxn];
int d[maxn], vis[maxn];

void dijkstra() {
  memset(d, 0x3f, sizeof(d));
  d[1] = 0;
  priority_queue<Hnode> q;
  q.push(Hnode{0, 1});
  while (!q.empty()) {
    int x = q.top().u;
    q.pop();
    if (vis[x])
      continue;
    vis[x] = 1;

    for (int i = 0; i < G[x].size(); i++) {
      node &e = G[x][i];
      if (d[e.to] > d[x] + e.cst) {
        d[e.to] = d[x] + e.cst;
        q.push(Hnode{d[e.to], e.to});
      }
    }
  }
}

int main() {
  // freopen("data.in", "r",stdin);
  // freopen("data.out", "w",stdout);
  while (cin >> n >> m && n) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
      G[i].clear();
    for (int i = 1; i <= m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      G[u].push_back(node{v, w});
      G[v].push_back(node{u, w});
    }
    dijkstra();
    cout << d[n] << '\n';
  }
  return 0;
}