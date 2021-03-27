#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3.2e4 + 10;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = x * 10 + ch - 48, ch = getchar();
  return x;
}
vector<int> tr[maxn];
int w[maxn], v[maxn];
int dp[65][maxn];

void dfs(int u, int va) {
  if (va <= 0)
    return;
  for (int i = 0; i < tr[u].size(); i++) {
    for (int j = 0; j <= va - w[i]; j++)
      dp[tr[u][i]][j] = dp[u][j] + v[i];
    dfs(tr[u][i], va - w[i]);
    for (int j = w[i]; j <= va; j++)
      dp[u][j] = max(dp[u][j], dp[i][j - w[i]]);
  }
}

int main() {
  freopen("data.in", "r", stdin);
  memset(dp, -1, sizeof(dp));
  int n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), z = read();
    w[i] = x, v[i] = x * y;
    tr[z].push_back(i);
  }
  dfs(0, n);
  cout << dp[0][n];
  return 0;
}