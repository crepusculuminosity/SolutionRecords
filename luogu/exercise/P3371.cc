#include <bits/stdc++.h>
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int maxn = 5e5 + 10;
constexpr int maxd = 1e4 + 10;
int n, m, s;

struct edge {
  int from, to, w;
} es[maxn];
int d[maxd];

inline void bellman_ford() {
  while (1) {
    bool f = 0;
    for (int i = 1; i <= m; i++) {
      edge e = es[i];
      if (d[e.from] != inf && d[e.to] > d[e.from] + e.w) {
        d[e.to] = d[e.from] + e.w;
        f = 1;
      }
    }
    if (!f)
      break;
  }
}

int main() {
  // freopen("data.in","r",stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++)
    cin >> es[i].from >> es[i].to >> es[i].w;
  fill(d + 1, d + n + 1, inf);
  d[s] = 0;
  bellman_ford();
  for (int i = 1; i <= n; i++)
    cout << d[i] << ' ';
  return 0;
}