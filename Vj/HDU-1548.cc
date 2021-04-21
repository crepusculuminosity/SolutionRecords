#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int d[210];
vector<int> G[210];
int vis[210];
struct Hnode {
  int d, u;
  bool operator<(const Hnode &x) const { return d > x.d; }
};

void dijkstra(int s) {
  memset(d, 0x3f, sizeof(d));
  d[s] = 0;
  priority_queue<Hnode> q;
  q.push(Hnode{0, s});
  while (!q.empty()) {
    Hnode a = q.top();
    q.pop();
    int u = a.u;
    if (vis[u])
      continue;
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); i++) {
      if (d[G[u][i]] > d[u] + 1) {
        d[G[u][i]] = d[u] + 1;
        q.push(Hnode{d[G[u][i]], G[u][i]});
      }
    }
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  while (cin >> n >> a >> b && n) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= 205; i++)
      G[i].clear();
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (i - x >= 1)
        G[i].push_back(i - x);
      if (i + x <= n)
        G[i].push_back(i + x);
    }
    dijkstra(a);
    if (d[b] == 0x3f3f3f3f)
      cout << "-1\n";
    else
      cout << d[b] << '\n';
  }
  return 0;
}