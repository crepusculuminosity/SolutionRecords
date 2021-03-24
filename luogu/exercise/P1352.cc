#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 6050;
int a[maxn];
vector<int> v[maxn];
int dp[maxn][2];

template <typename T, typename... Ts> inline void read(T &x, Ts &...t) {
  x = 0;
  T f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-')
      f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = x * 10 + c - 48, c = getchar();
  x *= f;
  if constexpr (sizeof...(t))
    read(t...);
}

int dfs(int u, int op) {
  if (dp[u][op] != -1)
    return dp[u][op];
  int &res = dp[u][op];
  res = 0;
  if (op == 1)
    res = a[u];
  for (int i = 0; i < v[u].size(); i++) {
    if (op == 1)
      res += dfs(v[u][i], 0);
    else
      res += max(dfs(v[u][i], 0), dfs(v[u][i], 1));
  }
  return res;
}

int main() {
  // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  // freopen("data.in", "r", stdin);
  int n;
  read(n);
  int root = n * (n + 1) / 2;
  for (int i = 1; i <= n; i++)
    read(a[i]);
  for (int i = 1; i < n; i++) {
    int x, y;
    read(x, y);
    root -= x;
    v[y].push_back(x);
  }
  memset(dp, -1, sizeof(dp));
  printf("%d", max(dfs(root, 1), dfs(root, 0)));
  return 0;
}