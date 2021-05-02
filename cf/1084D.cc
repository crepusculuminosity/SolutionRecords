#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e5 + 10;
int a[maxn], dp[maxn];
struct node {
  int to, w;
};
vector<node> G[maxn];

int dfs(int u) {
  if (~dp[u])
    return dp[u];
  int &res = dp[u] = a[u];
  int tmp = 0;
  for (int i = 0; i < G[u].size(); i++) {
    node &e = G[u][i];
    int a = dfs(G[u][i].to) - e.w;
    if (a < 0)
      continue;
    tmp = max(tmp, a);
  }
  return res += tmp;
}

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  memset(dp, -1, sizeof(dp));
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].push_back(node{v, w});
    G[v].push_back(node{u, w});
  }
  int ans = -1;
  for (int i = 1; i <= n; i++)
    ans = max(ans, dfs(i));
  cout << ans;
  return 0;
}