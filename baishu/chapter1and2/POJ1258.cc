#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 110;
int cnt,n;
int a[maxn][maxn];
struct edge {
  int from, to, w;
  bool operator<(const edge &x) const { return w < x.w; }
} es[10010];
int fa[maxn], rnk[maxn];

int find(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = find(fa[x]);
}
inline bool merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return 0;
  if (rnk[x] < rnk[y])
    fa[x] = y;
  else {
    fa[y] = x;
    if (rnk[x] == rnk[y]) ++rnk[x];
  }
  return 1;
}

int kruskal() {
  int res = 0;
  sort(es + 1, es + 1 + cnt);
  for(int i=1;i<=n;i++) fa[i]=i,rnk[i]=0;
  for(int i=1;i<=cnt;i++) {
    edge& e=es[i];
    if(merge(e.from,e.to)) res+=e.w;
  }
  return res;
}


int main() {
  //int n;
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  while (~scanf("%d", &n)) {
    cnt = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        int x; scanf("%d", &x);
        if (i < j)
          es[++cnt] = edge{i, j, x};
      }
    printf("%d\n", kruskal());
  }
  return 0;
}