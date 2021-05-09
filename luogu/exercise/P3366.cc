#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5000 + 10;
int n, m;
struct edge {
  int from, to, w;
  bool operator<(const edge &x) const { return w < x.w; }
} e[maxn];
int fa[maxn], rnk[maxn];
int find(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = find(fa[x]);
}
bool merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return false;
  if (rnk[x] < rnk[y])
    fa[x] = y;
  else {
    fa[y] = x;
    if (rnk[x] == rnk[y])
      ++rnk[x];
  }
  return true;
}
int kruskal() {
  int res = 0;
  for (int i = 1; i <= m; i++) {
    if (merge(e[i].from, e[i].to))
      res += e[i].w;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  for (int i = 1; i <= m; i++)
    cin >> e[i].from >> e[i].to >> e[i].w;
  sort(e + 1, e + 1 + n);
  cout << kruskal();
  return 0;
}