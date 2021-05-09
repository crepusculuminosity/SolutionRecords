#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 210;
struct node {
  int to, w;
};
vector<node> G[maxn];
int n, m, a, b;
int d[maxn], vis[maxn];
struct Hnode {
  int d, u;
  bool operator<(const Hnode &x) const { return d > x.d; }
};
void SPFA() {
  d[a] = 0;
  queue<int> q;
  q.push(a);
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
        }
      }
    }
  }
}

void dijkstra() {
  d[a] = 0;
  priority_queue<Hnode> q;
  q.push(Hnode{0, a});

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
        //vis[e.to] = 1;
      }
    }
  }
}
int main() {

  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> n >> m) {
    memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
      G[i].clear();
    for (int i = 1; i <= m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      G[u].push_back(node{v, w});
      G[v].push_back(node{u, w});
    }
    cin >> a >> b;
    dijkstra();
    if (d[b] == 0x3f3f3f3f)
      cout << "-1\n";
    else
      cout << d[b] << '\n';
  }
  return 0;
}