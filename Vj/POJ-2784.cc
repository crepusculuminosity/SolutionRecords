#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define nullptr 0
#define constexpr const
constexpr int maxn = 1010;

int n, q;
int fa[maxn], rnk[maxn];
void init() {
  for (int i = 0; i <= n; i++)
    fa[i] = i, rnk[i] = 0;
}
struct edge {
  int u, v, w;
  bool operator<(const edge &x) const { return w < x.w; }
} es[maxn * maxn / 2];
int x[maxn], y[maxn];
int dis(int i, int j) {
  return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}
vector<int> bonus[10];
int bs[10];
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
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int cnt = 0;
  n = read(), q = read();
  for (int i = 1; i <= q; i++) {
    int t;
    t = read(), bs[cnt] = read();
    for (int i = 0; i < t; i++) {
      int x = read();
      bonus[cnt].push_back(x);
    }
    cnt++;
  }
  for (int i = 1; i <= n; i++)
    x[i] = read(), y[i] = read();
  int tot = 0;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      es[++tot] = edge{i, j, dis(i, j)};
    }
  }
  sort(es + 1, es + 1 + tot);
  int ans = 0x3f3f3f3f;
  for (int S = 0; S < (1 << q); S++) {
    init();
    int res = 0;
    for (int j = 0; j < q; j++) {
      if ((1 << j) & S) {
        res += bs[j];
        for (int k = 0; k < bonus[j].size() - 1; k++) {
          for (int t = k + 1; t < bonus[j].size(); t++)
            merge(bonus[j][k], bonus[j][t]);
        }
      }
    }
    for (int i = 1; i <= tot; i++) {
      if (merge(es[i].u, es[i].v))
        res += es[i].w;
    }
    ans = min(ans, res);
  }
  printf("%d", ans);
  return 0;
}