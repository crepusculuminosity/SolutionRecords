#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 1e4;
int prime[M], id = 0, w[N];
vector<int> g[N];
map<int, vector<int>> s;
bool vis[N];
int dfs(int u, int num) {
  if (w[u] % num != 0)
    return 0;
  vis[u] = true;
  int res = 1;
  for (int x : g[u])
    if (!vis[x])
      res += dfs(x, num);
  return res;
}

int main() {
  freopen("data.in", "r", stdin);
  int m = 4e4;
  for (int i = 2; i <= m; i++) {
    bool ok = true;
    for (int j = 2; j <= i / j; j++) {
      if (i % j == 0)
        ok = false;
    }
    if (ok)
      prime[++id] = i;
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    int x = w[i];
    for (int j = 1; j <= id; j++) {
      if (x == 1)
        break;
      if (x % prime[j] == 0) {
        s[prime[j]].push_back(i);
        while (x % prime[j] == 0)
          x /= prime[j];
      }
    }
    if (x > 1)
      prime[++id] = x, s[x].push_back(i);
  }
  int ans = -1;
  for (int i = 1; i <= id; i++) {
    for (int j : s[prime[i]])
      if (!vis[j])
        ans = max(ans, dfs(j, prime[i]));
    for (int j : s[prime[i]])
      vis[j] = false;
  }
  printf("%d\n", ans);
  return 0;
}