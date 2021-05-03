#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
inline int read() {
  int x=0; char ch=getchar();
  while(ch< '0' || ch > '9') ch=getchar();
  while(ch>='0' && ch <= '9') x=(x << 1) + (x << 3)+ch-48, ch = getchar();
  return x;
}
int n,m;
const int maxn=2010;
int fa[maxn*2],rnk[maxn*2];
int find(int x) {
  if(x==fa[x]) return x;
  return fa[x]=find(fa[x]);
}
bool merge(int x, int y) {
  x=find(x), y = find(y);
  if(x==y) return 0;
  if(rnk[x]<rnk[y]) fa[x]=y;
  else {
    fa[y]=x;
    if(rnk[x] == rnk[y]) ++rnk[x];
  }
  return 1;
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int _=read(),kse=1;
  while(_--) {
    bool f=0;
    n=read(),m=read();
    for(int i=1;i<=2*n;i++) fa[i]=i,rnk[i]=0;
    while(m--) {
      int u=read(), v = read();
      if(f) continue;
      if(find(u)==find(v)) f=1;
      else merge(u,v+n); merge(u+n,v);
    }
    printf("Scenario #%d:\n",kse++);
    if(!f) puts("No suspicious bugs found!");
    else puts("Suspicious bugs found!");
    puts("");
  }
  return 0;
}