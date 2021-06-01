#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1550;
vector<int> G[maxn];
inline void add(int u, int v) { G[u].push_back(v); }
int n;
int dp[maxn][2], in[maxn];

void dfs(int u, int fa) {
  dp[u][1] = 1, dp[u][0] = 0;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa)
      continue;
    dfs(v, u);
    dp[u][0] += dp[v][1];
    dp[u][1] += min(dp[v][0], dp[v][1]);
  }
}
int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++)
      G[i].clear();
    for (int i = 0; i < n; i++) {
      int a, b;
      scanf("%d:(%d)", &a, &b);
      for (int i = 1; i <= b; i++) {
        int c;
        scanf("%d", &c);
        in[c]++;
        add(a, c);
        add(c, a);
      }
    }
    int root;
    for (int i = 0; i < n; i++)
      if (!in[i])
        root = i;
    dfs(root, -1);
    printf("%d\n", min(dp[root][0], dp[root][1]));
  }
  return 0;
}