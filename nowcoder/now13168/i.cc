#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const ll inf = 1e10;
ll n, m, t, d, g[598][598], dis[588];
bool vis[599];
vector<ll> G[598], x;
vector<ll> value[598];
void floyd() {
  for (ll k = 1; k <= n; ++k)
    for (ll i = 1; i <= n; ++i)
      for (ll j = 1; j <= n; ++j)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
void visd() {
  ll len = (ll)x.size();
  for (ll i = 0; i < len; ++i) {
    if (g[1][x[i]] <= d) {
      G[1].pb(x[i]);
      G[x[i]].pb(1);
      value[1].pb(g[1][x[i]]);
      value[x[i]].pb(g[1][x[i]]);
    }
    if (g[n][x[i]] <= d) {
      G[n].pb(x[i]);
      G[x[i]].pb(n);
      value[n].pb(g[n][x[i]]);
      value[x[i]].pb(g[n][x[i]]);
    }
    for (ll j = i + 1; j < len; ++j) {
      ll p = x[i], q = x[j];
      if (g[p][q] <= d) {
        G[p].pb(q);
        G[q].pb(p);
        value[q].pb(g[p][q]);
        value[p].pb(g[p][q]);
      }
    }
  }
}
struct cmp {
  bool operator()(ll a, ll b) { return dis[a] > dis[b]; }
};
priority_queue<ll, vector<ll>, cmp> q;
void dij() {
  for (ll i = 1; i <= n; ++i)
    dis[i] = inf;
  dis[1] = 0;
  q.push(1);
  while (!q.empty()) {
    ll id = q.top();
    q.pop();
    if (vis[id])
      continue;
    vis[id] = 1;
    ll len = (ll)G[id].size();
    for (ll i = 0; i < len; ++i) {
      ll p = G[id][i];
      if (dis[p] > dis[id] + value[id][i]) {
        dis[p] = dis[id] + value[id][i];
        if (!vis[p])
          q.push(p);
      }
    }
  }
}
void solve() {
  scanf("%lld%lld%lld%lld", &n, &m, &t, &d);
  for (ll i = 1; i <= t; ++i) {
    ll u;
    scanf("%lld", &u);
    x.pb(u);
  }
  for (ll i = 1; i <= n; ++i)
    for (ll j = 1; j <= n; ++j)
      if (i == j)
        g[i][j] = 0;
      else
        g[i][j] = inf;
  for (ll i = 1; i <= m; ++i) {
    ll u, v, p;
    scanf("%lld%lld%lld", &u, &v, &p);
    g[v][u] = g[u][v] = p;
  }
  floyd();
  if (g[1][n] <= d) {
    printf("%lld\n", g[1][n]);
    return;
  }
  visd();
  dij();
  if (dis[n] == inf)
    puts("stuck");
  else
    printf("%lld\n", dis[n]);
}
int main() {
  solve();
  return 0;
}