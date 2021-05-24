#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
using ll = long long;
ll a[maxn], sz[maxn], d[maxn], f[maxn], sum;
int n;
struct node {
  int to, w;
};
vector<node> G[maxn];
void add(int u, int v, int w) { G[u].push_back(node{v, w}); }

void dfs(int u, int fa) {
  d[u] = 0;
  sz[u] = a[u];
  for (int i = 0; i < G[u].size(); i++) {
    node &e = G[u][i];
    if (e.to != fa) {
      dfs(e.to, u);
      sz[u] += sz[e.to];
      d[u] += d[e.to] + sz[e.to] * e.w;
    }
  }
}

void dfs2(int u, int fa) {

  for (int i = 0; i < G[u].size(); i++) {
    node &e = G[u][i];
    if (e.to != fa) {
      f[e.to] = f[u] - sz[e.to] * e.w + (sum - sz[e.to]) * e.w;
      dfs2(e.to, u);
    }
  }
}
int main() {

  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 1; i < n; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
    add(v, u, w);
  }
  dfs(1, 0);
  f[1] = d[1];
  dfs2(1, 0);
  ll ans = 0x7f7f7f7f7f7f7f7f;
  for (int i = 1; i <= n; i++)
    ans = min(ans, f[i]);
  cout << ans;
  return 0;
}