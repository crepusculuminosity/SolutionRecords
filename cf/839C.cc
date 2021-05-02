#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 + 10;
vector<int> G[maxn];
int d[maxn];
double dp[maxn];
int vis[maxn];

void dfs(int u, int fa) {
  for (int i = 0; i < G[u].size(); i++) {
    if (G[u][i] != fa) {
      dfs(G[u][i], u);
      dp[u] += (dp[G[u][i]] + 1.0) / d[u];
    }
  }
}

int main() {
  // memset(d, 0x43, sizeof(d));
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
    ++d[u], ++d[v];
  }
  for (int i = 2; i <= n; i++)
    --d[i];
  dfs(1, 0);
  cout << fixed << setprecision(15) << dp[1];
  return 0;
}