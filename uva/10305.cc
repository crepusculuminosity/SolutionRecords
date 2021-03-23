#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 110;

vector<int> G[maxn];
int in[maxn];
int n, m;
int t;
int topo[maxn], c[maxn];

void bfs() {
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (!in[i])
      q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    cout << u << ' ';
    for (int i = 0; i < G[u].size(); i++) {
      --in[G[u][i]];
      if (!in[G[u][i]])
        q.push(G[u][i]);
    }
  }
}

bool dfs(int u) {
  c[u] = -1;
  cout << u << ' ';
  for (int i = 0; i < G[u].size(); i++) {
    if (c[G[u][i]] == -1)
      return 0;
    else if (c[G[u][i]] == 0)
      dfs(G[u][i]);
  }
  c[u] = 1, topo[--t] = u;
  return 1;
}

bool tsort() {
  t = n;
  memset(c, 0, sizeof(c));
  memset(topo, 0, sizeof(topo));
  for (int i = 1; i <= n; i++) {
    if (c[i] == 0)
      if (!dfs(i))
        return 0;
  }
  return 1;
}

int main() {
  freopen("data.in", "r", stdin);
  while (cin >> n >> m && n) {
    for (int i = 1; i <= n; i++)
      G[i].clear();
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      //++in[v];
    }
    // cout<<'\n';
    if (!tsort())
      cout << -1;
    cout << '\n';
    for (int i = 0; i < n; i++)
      cout << topo[i] << ' ';

    // bfs();
    cout << '\n';
  }
  return 0;
}