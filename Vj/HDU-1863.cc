#include <bits/stdc++.h>
using namespace std;
int n, m;
constexpr int maxn = 6000;
int fa[110], rnk[110];
struct edge {
  int u, v, w;
  bool operator<(const edge &x) const { return w < x.w; }
} es[maxn];
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
int kruskal() {
  int res = 0, cnt = 0;
  for (int i = 1; i <= m; i++) {
    if (merge(es[i].u, es[i].v))
      res += es[i].w, ++cnt;
  }
  if (cnt == n - 1)
    return res;
  return -1;
}
int main() {
  //freopen("data.in", "r", stdin);
  while (cin >> m >> n && m) {
    for (int i = 1; i <= n; i++)
      fa[i] = i, rnk[i] = 0;
    for (int i = 1; i <= m; i++)
      cin >> es[i].u >> es[i].v >> es[i].w;
    sort(es + 1, es + 1 + m);
    int ans = kruskal();
    if (~ans)
      cout << ans << '\n';
    else
      cout << "?\n";
  }
  return 0;
}