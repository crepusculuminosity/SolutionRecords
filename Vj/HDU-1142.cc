#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1010;
int d[maxn], vis[maxn], dis[maxn];
int n, m;
struct node {
  int to, w;
};
vector<node> G[maxn];
inline void addedge(int u, int v, int w) { G[u].push_back(node{v, w}); }
struct Hnode {
  int d, u;
  bool operator<(const Hnode &x) const { return d > x.d; }
};
void dijkstra(int x) {
  priority_queue<Hnode> q;
  d[x] = 0;
  q.push({0, x});
  while (!q.empty()) {
    Hnode s = q.top();
    q.pop();
    int u = s.u;
    if (vis[u])
      continue;
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); i++) {
      node e = G[u][i];
      if (d[e.to] > d[u] + e.w) {
        d[e.to] = d[u] + e.w;
        q.push(Hnode{d[e.to], e.to});
      }
    }
  }
}
void dfs(int u, int fa) {
  if (dis[u])
    return;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].to;
    if (d[v] < d[u] && v != fa) {
      dfs(v, u);
      dis[u] += dis[v];
    }
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  while (cin >> n >> m && n) {
    for (int i = 0; i <= n; i++)
      G[i].clear();
    memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    for (int i = 1; i <= m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      addedge(u, v, w);
      addedge(v, u, w);
    }
    dijkstra(2);
    dis[2] = 1;
    dfs(1, 0);
    cout << dis[1] << '\n';
    // cout << endl;
  }
  return 0;
}