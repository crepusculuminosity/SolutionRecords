#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1510;
int dp[maxn][2];
int n;
vector<int> v[maxn];

int dfs(int u, int o) {
  if (~dp[u][o])
    return dp[u][o];
  int &res = dp[u][o] = 0;
  if (o == 1)
    res = 1;
  for (int i = 0; i < v[u].size(); i++) {
    if (o == 1)
      res += min(dfs(v[u][i], 0), dfs(v[u][i], 1));
    else
      res += dfs(v[u][i], 1);
  }
  return res;
}

int main() {
  // freopen("data.in", "r", stdin);
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, k;
    cin >> x >> k;
    while (k--) {
      int u;
      cin >> u;
      v[x].push_back(u);
    }
  }
  cout << min(dfs(0, 1), dfs(0, 0));
  return 0;
}