#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1000 + 10;
int fa[maxn], rnk[maxn];
int n, m;
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
struct edge {
  int u, v, w;
  bool operator<(const edge &x) const { return w < x.w; }
} es[20010];

int kruskal() {
  int res = 0, cnt = 0;
  for (int i = m; i >= 1; i--) {
    if (merge(es[i].u, es[i].v))
      res += es[i].w, ++cnt;
  }
  if (cnt != n - 1)
    return -1;
  return res;
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
int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);

  n = read(), m = read();
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  for (int i = 1; i <= m; i++) {
    int a = read(), b = read(), c = read();
    es[i] = edge{a, b, c};
  }
  sort(es + 1, es + 1 + m);
  printf("%d", kruskal());
  return 0;
}