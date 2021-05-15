#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2000 + 10;
int fa[maxn], rnk[maxn];
inline int read() {
  int x=0; char ch=getchar();
  while(ch< '0' || ch > '9' ) ch=getchar();
  while(ch>='0' && ch <= '9') x=(x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}
int find(int x) {
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
struct edge {
  int u, v,w;
  bool operator<(const edge &x) const { return w < x.w; }
} es[10010];

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int n=read(),m=read();
  for(int i=1;i<=m;i++) {
    es[i].u=read(), es[i].v = read(), es[i].w=read();
  }
  for(int i=1;i<=n;i++) fa[i]=i;
  sort(es+1, es + 1 + m);
  int ans=0;
  for(int i=1;i<=m;i++) 
    if(merge(es[i].u, es[i].v)) ans=max(ans,es[i].w);
  printf("%d",ans);
  return 0;
}