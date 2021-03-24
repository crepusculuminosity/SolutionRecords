#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e4 + 10;
constexpr int inf = 0x7fffffff;
int d[maxn];
int n, m, cnt;

struct edge {
  int from, to, w;
} es[maxn];

inline bool bellman_ford() {
  d[1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= cnt - 1; j++) {
      edge e = es[j];
      if (d[e.from] != inf && d[e.to] > d[e.from] + e.w) {
        d[e.to] = d[e.from] + e.w;
        if (i == n)
          return 1;
      }
    }
  }
  return 0;
}

int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    cin >> n >> m;
    // memset(d, 0, sizeof(d));
    fill(d + 1, d + n + 1, inf);
    cnt = 1;
    for (int i = 1; i <= m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      if (w >= 0) {
        es[cnt].from = u, es[cnt].to = v, es[cnt++].w = w;
        es[cnt].from = v, es[cnt].to = u, es[cnt++].w = w;
      } else
        es[cnt].from = u, es[cnt].to = v, es[cnt++].w = w;
    }
    if (bellman_ford())
      cout << "YES";
    else
      cout << "NO";
    cout << '\n';
  }
}