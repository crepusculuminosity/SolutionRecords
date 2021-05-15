#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1010;
int fa[maxn], rnk[maxn], vis[maxn];
struct node {
  int x, y;
  friend int dis(const node &a, const node &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  }
} q[maxn];
inline int find(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = find(fa[x]);
}
inline bool merge(int x, int y) {
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
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int n = read(), d = read();
  for (int i = 1; i <= n; i++) {
    q[i].x = read(), q[i].y = read();
    fa[i] = i;
  }
  char ch[5];
  while (~scanf("%s", ch)) {
    if (ch[0] == 'O') {
      int k = read();
      vis[k] = 1;
      for (int i = 1; i <= n; i++) {
        if (vis[i] && dis(q[i], q[k]) <= d * d && i != k)
          merge(i, k);
      }
    } else {
      int u = read(), v = read();
      if (find(u) == find(v))
        puts("SUCCESS");
      else
        puts("FAIL");
    }
  }
  return 0;
}