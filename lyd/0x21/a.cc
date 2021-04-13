#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e4 + 10;
using ll = long long;
int a[maxn], n, m, in[maxn];
vector<int> G[maxn];
bitset<maxn> f[maxn];
void bfs() {
  int cnt = 0;
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (in[i] == 0)
      q.push(i);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    a[++cnt] = x;
    for (auto u : G[x]) {
      if (--in[u] == 0)
        q.push(u);
    }
  }
}

int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    ++in[v];
  }
  bfs();
  for (int i = n; i >= 1; i--) {
    int u = a[i];
    f[u][u] = 1;
    for (auto v : G[u]) {
      f[u] |= f[v];
    }
  }
  for (int i = 1; i <= n; i++)
    cout << f[i].count() << '\n';
  return 0;
}