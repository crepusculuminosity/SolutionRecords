#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1510;
vector<int> G[maxn];
int n;
char ch[100];
int dp[maxn][maxn];
int dfs(int u, int o) {
  if (~dp[u][o])
    return dp[u][o];
  int &res = dp[u][o] = 0;
  if (o == 0) {
    for (int i = 0; i < G[u].size(); i++)
  }
}
int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  while (scanf("%d", &n) != EOF) {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < maxn; i++)
      G[i].clear();
    int a, b, c;
    for (int i = 1; i <= n; i++) {
      scanf("%d:(%d)", &a, &b);
      ++a;
      for (int j = 1; j <= b; j++) {
        scanf("%d", &c);
        G[a].push_back(c);
      }
    }
  }
  return 0;
}