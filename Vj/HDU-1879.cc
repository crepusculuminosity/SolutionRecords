#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5050;
int n;
struct node {
  int u, v, w;
  bool operator<(const node &x) const { return w < x.w; }
} es[maxn];
int fa[110], rnk[110];
int cnt;
inline bool read(int &x) {
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return 1;
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
int kruskal() {
  int res = 0;
  for (int i = 1; i <= cnt; i++) {
    if (merge(es[i].u, es[i].v))
      res += es[i].w;
  }
  return res;
}
int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  while (read(n) && n) {
    for (int i = 1; i <= n; i++)
      fa[i] = i, rnk[i] = 0;
    cnt = 0;
    for (int i = 1; i <= n * (n - 1) / 2; i++) {
      int a, b, c, d;
      read(a),read(b),read(c),read(d);
      if (d)
        merge(a, b);
      else {
        es[++cnt] = node{a, b, c};
      }
    }
    sort(es + 1, es + 1 + cnt);
   // cout <<  << '\n';
   printf("%d\n",kruskal());
  }
  return 0;
}