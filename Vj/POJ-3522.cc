#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 210;
struct edge {
  int u, v, w;
  bool operator<(const edge &x) const { return w < x.w; }
} es[20010];
int n, m;
int fa[210], rnk[210];
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
inline void init() {
  for (int i = 1; i <= 200; i++)
    fa[i] = i, rnk[i] = 0;
}
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}
int kruskal(int l) {
  init();
  int now = 0;
  for (int r = l; r <= m; r++) {
    if (merge(es[r].u, es[r].v))
      if (++now == n - 1)
        return es[r].w - es[l].w;
  }
  return 0x3f3f3f3f;
}
int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  while (~scanf("%d%d", &n, &m) && n + m) {
    for (int i = 1; i <= m; i++)
      es[i].u = read(), es[i].v = read(), es[i].w = read();
    sort(es + 1, es + 1 + m);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++)
      ans = min(ans, kruskal(i));
    if (ans < 0x3f3f3f3f)
      printf("%d\n", ans);
    else
      puts("-1");
  }
  return 0;
}