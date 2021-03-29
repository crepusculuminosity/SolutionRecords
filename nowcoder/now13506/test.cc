#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5 + 10;
int dp[maxn];
vector<int> G[maxn];
int n, m;

int dfs(int u) {
  if (dp[u] > 1)
    return dp[u];
  int &res = dp[u];
  for (int i = 0; i < G[u].size(); i++) {
    if (G[G[u][i]].size() > G[u].size()) {
      int t = dfs(G[u][i]);
      res = max(t + 1, res);
    }
  }
  return res;
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  fill(dp, dp + n, 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int ans = -1;
  for (int i = 0; i < n; i++)
    ans = max(ans, dfs(i));
  cout << ans;
  return 0;
}