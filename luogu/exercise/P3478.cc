#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll maxn = 1e6 + 10;
vector<ll> G[maxn];
void add(ll u, ll v) { G[u].push_back(v); }
ll sz[maxn], f[maxn], d[maxn];
ll n;

void dfs(ll u, ll fa) {
  sz[u] = 1, d[u] = d[fa] + 1;
  for (ll i = 0; i < G[u].size(); i++) {
    ll v = G[u][i];
    if (v != fa) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}
void dfs2(ll u, ll fa) {
  for (ll i = 0; i < G[u].size(); i++) {
    ll v = G[u][i];
    if (v != fa) {
      f[v] = f[u] + n - 2 * sz[v];
      dfs2(v, u);
    }
  }
}
int main() {

  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  for (ll i = 1; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    add(u, v), add(v, u);
  }
  dfs(1, 0);
  ll ans = 0, p;
  for (ll i = 1; i <= n; i++)
    f[1] += d[i];
  dfs2(1, 0);
  for (ll i = 1; i <= n; i++)
    if (ans < f[i])
      ans = f[i], p = i;
  cout << p;
  return 0;
}