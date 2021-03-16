#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
int n, m;
vector<int> G[maxn];
int vis[maxn];
queue<int> que;

void dfs(int x, int cur) {
  vis[x] = 1;
  cout << x << ' ';
  if (cur == n)
    return;
  for (int i = 0; i < G[x].size(); i++)
    if (!vis[G[x][i]])
      dfs(G[x][i], cur + 1);
}

void bfs(int x) {
  memset(vis, 0, sizeof(vis));
  vis[x] = 1;
  que.push(x);
  while (!que.empty()) {
    int p = que.front();
    que.pop();
    cout << p << ' ';
    for (int i = 0; i < G[p].size(); i++) {
      if (!vis[G[p][i]]) {
        vis[G[p][i]] = 1;
        que.push(G[p][i]);
      }
    }
  }
}

int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
  }
  for (int i = 1; i <= n; i++)
    sort(G[i].begin(), G[i].end());
  dfs(1, 0);
  cout << '\n';
  bfs(1);
  return 0;
}