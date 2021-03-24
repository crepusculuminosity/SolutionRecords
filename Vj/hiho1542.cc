#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1010;
vector<int> G[maxn];
int n, k;
int ans[maxn];

void dfs(int u, int fa) {
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != fa) {
      ans[v] = u;
      dfs(v, u);
    }
  }
}

int main() {
  // freopen("data.in", "r", stdin);
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(k, 0);
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  return 0;
}