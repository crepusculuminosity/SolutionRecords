#include <cstdio>
#include <iostream>
using namespace std;

inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

namespace UFS { // union-find disjoint sets
constexpr int maxn = 2e5 + 10;
int fa[maxn], rnk[maxn];
inline void init(int n) {
  for (int i = 1; i <= n; i++)
    fa[i] = i, rnk[i] = 0;
}
inline int find(int x) {
  if (fa[x] == x)
    return x;
  return fa[x] = find(fa[x]);
}
inline void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  if (rnk[x] < rnk[y])
    fa[x] = y;
  else {
    fa[y] = x;
    if (rnk[x] == rnk[y])
      ++rnk[x];
  }
}
inline bool check(int x, int y) { return find(x) == find(y); }
} // namespace UFS

int main() {
  // freopen("data.in", "r",stdin);
  int n = read(), k = read();
  UFS::init(n * 3);
  int ans = 0;
  while (k--) {
    int op = read(), x = read(), y = read();

    if (x < 0 || x > n || y < 0 || y > n) {
      ++ans;
      continue;
    }
    if (op == 1) {
      if (UFS::check(x, y + n) || UFS::check(x, y + 2 * n))
        ++ans;
      else
        UFS::merge(x, y), UFS::merge(x + n, y + n),
            UFS::merge(x + 2 * n, y + 2 * n);
    } else {
      if (UFS::check(x, y) || UFS::check(x, y + 2 * n))
        ++ans;
      else
        UFS::merge(x, y + n), UFS::merge(x + n, y + 2 * n),
            UFS::merge(x + 2 * n, y);
    }
  }
  printf("%d", ans);
  return 0;
}