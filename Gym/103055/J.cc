#include <bits/stdc++.h>
using namespace std;
vector<int> G[3010];
int n, m, T;
int d[3010], a[3010], vis[3010], dp[3010];

void bfs() {
  d[1] = 0;
  queue<int> q;
  q.push(1);
  vis[1] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < G[u].size(); i++) {
      if (vis[G[u][i]])
        continue;
      d[G[u][i]] = d[u] + 2;
      q.push(G[u][i]);
      vis[G[u][i]] = 1;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  cin >> n >> m >> T;
  for (int i = 2; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  bfs();
  // for(int i=1;i<=n;i++) cout<<d[i]<<' ';
  for (int i = 1; i <= n; i++)
    for (int j = d[i]; j <= T; j++)
      dp[j] = max(dp[j], dp[j - d[i]] + a[i]);
  for (int i = 1; i <= T; i++)
    cout << dp[i] << ' ';
  return 0;
}