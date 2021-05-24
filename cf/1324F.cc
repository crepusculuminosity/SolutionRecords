#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 10;
int a[maxn], dp[maxn], ans[maxn], pre[maxn];
vector<int> G[maxn];
inline void add(int u, int v) { G[u].push_back(v); }
int n;

void dfs(int u, int fa) {
  dp[u] = a[u];
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != fa) {
      dfs(v, u);
      dp[u] += max(0, dp[v]);
    }
  }
}

void DFS(int u, int fa) {
  ans[u] = dp[u] + pre[u];
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != fa) {
      pre[v] = max(0, ans[u] - max(dp[v], 0));
      DFS(v, u);
    }
  }
}
int main() {

  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = 2 * x - 1;
  }
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v), add(v, u);
  }
  dfs(1, -1);
  DFS(1, -1);
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  return 0;
}