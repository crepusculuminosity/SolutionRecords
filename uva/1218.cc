#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e4 + 10;
vector<int> G[maxn];
int p[maxn];
inline void addedge(int u, int v) { G[u].push_back(v); }
int n;
long long dp[maxn][3];

void dfs(int u, int fa) {
  dp[u][0] = 1, dp[u][1] = 0, dp[u][2] = 0x3f3f3f3f;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != fa) {
      dfs(v, u);
      dp[u][0] += min(dp[v][0], dp[v][1]);
      dp[u][1] += dp[v][2];
    }
  }
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != fa)
      dp[u][2] = min(dp[u][2], dp[u][1] - dp[v][2] + dp[v][0]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  while (cin >> n && ~n) {
    if (n == 0)
      continue;
    for (int i = 1; i <= n; i++)
      G[i].clear();
    for (int i = 1; i <= n - 1; i++) {
      int u, v;
      cin >> u >> v;
      addedge(u, v);
      addedge(v, u);
    }
    dfs(1, -1);
    cout << min(dp[1][0], dp[1][2]) << '\n';
  }
  return 0;
}