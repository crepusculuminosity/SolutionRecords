#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 10000;
int n, m, w;

inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch))
    ch = getchar();
  while (isdigit(ch))
    x = x * 10 + ch - 48, ch = getchar();
  return x;
}

struct edge {
  int from, to, w;
} es[maxn];
int d[maxn];

inline bool bellman_ford() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m * 2 + w; j++) {
      edge e = es[j];
      if (d[e.to] > d[e.from] + e.w) {
        d[e.to] = d[e.from] + e.w;
        if (i == n)
          return 1;
      }
    }
  }
  return 0;
}

int main() {
  // freopen("data.in", "r", stdin);
  int t = read();
  while (t--) {
    // memset(es,0,sizeof(es));
    memset(d, 0, sizeof(d));
    n = read(), m = read(), w = read();
    for (int i = 1; i <= m; i++) {
      int x = read(), y = read(), z = read();
      es[i].from = x, es[i].to = y, es[i].w = z;
      es[i + m].to = x, es[i + m].from = y, es[i + m].w = z;
    }
    for (int i = 1; i <= w; i++) {
      int x = read(), y = read(), z = read();
      es[i + 2 * m].from = x, es[i + 2 * m].to = y, es[i + 2 * m].w = -z;
    }
    if (bellman_ford())
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}