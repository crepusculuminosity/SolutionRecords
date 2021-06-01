#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998344353;
constexpr int maxn = 1e6 + 10;
int in[maxn], dep[maxn];
int n;
vector<int> G[maxn];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}
void add(int u, int v) { G[u].push_back(v); }

void dfs(int u, int fa, int d) {
  dep[d]++;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != fa) {
      dfs(v, u, d + 1);
    }
  }
}
int main() {

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr), cout.tie(nullptr);
  n = read();
  for (int i = 1; i < n; i++) {
    int u, v;
    u = read(), v = read();
    add(u, v), add(v, u);
  }
  dfs(1, -1, 1);
  int ans = 1;
  for (int i = 1; dep[i]; i++)
    ans = 1LL * ans * dep[i] % mod;
  // cout << ans;
  printf("%d", ans);
  return 0;
}