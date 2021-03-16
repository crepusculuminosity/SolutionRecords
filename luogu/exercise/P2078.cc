#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 10010;
int fa[2][maxn];
int rnk[2][maxn];
int n, m, p, q;

inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

int find(int o, int x) {
  if (x == fa[o][x])
    return x;
  return fa[o][x] = find(o, fa[o][x]);
}

void merge(int o, int x, int y) {
  x = find(o, x);
  y = find(o, y);

  if (rnk[o][x] < rnk[o][y])
    fa[o][x] = y;
  else {
    fa[o][y] = x;
    if (rnk[o][x] == rnk[o][y])
      ++rnk[o][x];
  }
}

inline void init() {
  for (int i = 1; i <= n; i++)
    fa[0][i] = i, rnk[0][i] = 1;
  for (int i = 1; i <= m; i++)
    fa[1][i] = i, rnk[1][i] = 1;
}

int main() {
  // freopen("data.in","r",stdin);
  n = read(), m = read(), p = read(), q = read();
  init();
  int r1 = 0, r2 = 0;
  while (p--) {
    int a = read(), b = read();
    merge(0, min(a, b), max(a, b));
  }
  while (q--) {
    int a = read(), b = read();
    merge(1, min(-a, -b), max(-a, -b));
  }
  for (int i = 1; i <= n; i++)
    if (find(0, i) == 1)
      ++r1;
  for (int i = 1; i <= m; i++)
    if (find(1, i) == 1)
      ++r2;
  printf("%d", min(r1, r2));
  return 0;
}