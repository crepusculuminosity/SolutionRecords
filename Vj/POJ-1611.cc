#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 3e4 + 10;
int fa[maxn], rnk[maxn];
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
inline int find(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = find(fa[x]);
}
inline bool merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y)
    return 0;
  if (rnk[x] < rnk[y]) {
    fa[x] = y;
    // rnk[y] += rnk[x];
  } else {
    fa[y] = x;
    if (rnk[x] == rnk[y])
      ++rnk[x];
  }
  return 1;
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  while (read(n) && read(m) && m + n) {
    for (int i = 0; i < n; i++)
      fa[i] = i, rnk[i] = 0;
    int ans = 1;
    for (int i = 1; i <= m; i++) {
      int k, a;
      read(k), read(a);
      --k;
      while (k--) {
        int u;
        read(u);
        merge(u, a);
        a = u;
      }
    }
    int x = find(0);
    for (int i = 1; i < n; i++)
      if (find(i) == x)
        ++ans;
    printf("%d\n",ans);
  }
  return 0;
}