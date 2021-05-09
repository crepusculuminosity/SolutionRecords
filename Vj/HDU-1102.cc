#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 110;
int n;
struct edge {
  int u, v, w;
  bool operator<(const edge &x) const { return w < x.w; }
} es[5050];
int cnt, fa[maxn], rnk[maxn], m[maxn][maxn];
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
  int res = 0;
  for (int i = 1; i <= n * n; i++) {
    if (merge(es[i].u, es[i].v))
      res += es[i].w;
  }
  return res;
}
int main() {

  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> n) {
    for (int i = 1; i <= n; i++)
      fa[i] = i;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        cin >> m[i][j];
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
      int a, b;
      cin >> a >> b;
      m[a][b] = 0;
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        es[++cnt] = {i, j, m[i][j]};
    sort(es + 1, es + 1 + n * n);
    cout << kruskal() << '\n';
  }
  return 0;
}