#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 5e4 + 10;
int fa[maxn], rnk[maxn];

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
int n, m;
inline bool read(int &x) {
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return 1;
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int kse = 1;
  while (read(n) && read(m) && m + n) {
    int tot = n;
    for (int i = 1; i <= n; i++)
      fa[i] = i, rnk[i] = 0;
    for (int i = 1; i <= m; i++) {
      int u, v;
      read(u), read(v);
      if (merge(u, v))
        --tot;
    }
    printf("Case %d: %d\n", kse++, tot);
  }
  return 0;
}