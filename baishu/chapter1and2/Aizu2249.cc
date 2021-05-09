#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 10000 + 10;
int d[maxn], sum[maxn], n, m, vis[maxn];
struct edge {
  int to, w, cost;
};
vector<edge> G[maxn];
struct Hnode {
  int d, u;
  bool operator<(const Hnode &x) const { return d > x.d; }
};

void dijkstra() {
  memset(d, 0x3f, sizeof(d));
  memset(vis, 0, sizeof(vis));
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
      edge &e = G[x][i];
      if (d[e.to] >= d[x] + e.w) {
        if (d[e.to] == d[x] + e.w)
          sum[e.to] = min(sum[e.to], e.cost);
        else
          sum[e.to] = e.cost;
        d[e.to] = d[x] + e.w;
        q.push(Hnode{d[e.to], e.to});
      }
    }
  }
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  while (~scanf("%d%d", &n, &m) && n) {
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++)
      G[i].clear();
    for (int i = 1; i <= m; i++) {
      int u, v, d, c;
      scanf("%d%d%d%d", &u, &v, &d, &c);
      G[u].push_back(edge{v, d, c});
      G[v].push_back(edge{u, d, c});
    }
    dijkstra();
    int ans = 0;
    for (int i = 1; i <= n; i++)
      ans += sum[i];
    // cout<<endl;
    printf("%d\n", ans);
  }
  return 0;
}