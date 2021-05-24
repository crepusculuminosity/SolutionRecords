#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
using ll = long long;
int a[maxn];
ll d[maxn][30], f[maxn][30];
vector<int> G[maxn];
void add(int u, int v) { G[u].push_back(v); }
int n, k;

void dfs(int u, int fa) {
  // d[u][0] = a[u];
  for (int i = 0; i <= k; i++)
    d[u][i] = a[u];
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != fa) {
      dfs(v, u);
      for (int i = 1; i <= k; i++) {
        d[u][i] += d[v][i - 1];
        // d[u][i] += d[u][0];
      }
    }
  }
}
void dfs2(int u, int fa) {
  // f[u][0] = a[u];
  // f[u][1] = d[u][1] + d[fa][0];
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != fa) {
      f[v][1] += d[u][0];
      for (int j = 2; j <= k; j++)
        f[v][j] += f[u][j - 1] - d[v][j - 2];
      dfs2(v, u);
    }
  }
}
int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  // memset(f, -1, sizeof(f));
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v), add(v, u);
  }
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  dfs(1, 0);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++)
      f[i][j] = d[i][j];
  dfs2(1, 0);
  for (int i = 1; i <= n; i++)
    cout << f[i][k] << '\n';
  return 0;
}