#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5e4 + 10;
int N, M, R;
struct edge {
  int from, to, cost;
  bool operator<(const edge &x) const { return cost < x.cost; }
} es[maxn];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = x * 10 + ch - 48, ch = getchar();
  return x;
}
int fa[maxn], rnk[maxn];
int find(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
  x = find(x), y = find(y);
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
int kruskal() {
  for (int i = 0; i <= N + M; i++)
    fa[i] = i, rnk[i] = 0;
  sort(es + 1, es + 1 + R);
  int res = 0;
  for (int i = 1; i <= R; i++) {
    edge &e = es[i];
    if (find(e.from) != find(e.to)) {
      merge(e.from, e.to);
      res += e.cost;
    }
  }
  return res;
}

int main() {

  // freopen("data.in","r",stdin);
  int _ = read();
  // cin>>_;
  while (_--) {
    // cin>>N>>M>>R;
    N = read(), M = read(), R = read();
    for (int i = 1; i <= R; i++) {
      int u = read(), v = read(), w = read();
      //es[i].from = u, es[i].to = v + N, es[i].cost = -w;
      es[i]=edge{u,v+N,-w};
    }
    // cout<<10000*(N+M)+kruskal()<<'\n';
    printf("%d\n", 10000 * (N + M) + kruskal());
  }
  return 0;
}