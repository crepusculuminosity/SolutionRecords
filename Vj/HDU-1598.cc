#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 210;
int n, m;
struct edge {
  int u, v, w;
  bool operator<(const edge &x) const { return w < x.w; }
} es[21000];
int fa[maxn], rnk[maxn];
void init() {
  for (int i = 1; i <= n; i++)
    fa[i] = i, rnk[i] = 0;
}
int find(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = find(fa[x]);
}
bool merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y)
    return 0;
  if (rnk[x] < rnk[y])
    fa[x] = y;
  else {
    fa[y] = x;
    if (rnk[x] == rnk[y])
      ++rnk[x];
  }
  return 1;
}
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  while (cin >> n >> m) {
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      es[++cnt] = edge{a, b, c};
    }
    sort(es + 1, es + 1 + cnt);
    int q;
    cin >> q;
    while (q--) {
      int u, v;
      cin >> u >> v;
      int ans = 0x3f3f3f3f;
      for (int i = 1; i <= m; i++) {
        init();
        for (int j = i; j <= m; j++) {
          merge(es[j].u, es[j].v);
          if (find(u) == find(v)) {
            ans = min(ans, es[j].w - es[i].w);
            break;
          }
        }
      }
      if (ans == 0x3f3f3f3f)
        cout << "-1\n";
      else
        cout << ans << '\n';
    }
  }
  return 0;
}