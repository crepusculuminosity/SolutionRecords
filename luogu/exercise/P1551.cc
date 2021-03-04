#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=5010;
int rnk[maxn],fa[maxn];

inline int read() {
  int x=0;
  char ch=getchar();
  while(ch < '0' || ch > '9') ch=getchar();
  while(ch>='0' && ch <= '9') {
    x=x * 10 + ch - '0';
    ch=getchar();
  }
  return x;
}

inline void init(int n) {
  for(int i=1;i<=n;i++) fa[i]=i,rnk[i]=0;
}

inline int find(int x) {
  if(x==fa[x]) return x;
  return fa[x]=find(fa[x]);
}

inline void merge(int x, int y) {
  x=find(x),y=find(y);
  if(x==y) return;

  if(rnk[x]<rnk[y]) fa[x]=y;
  else {
    fa[y]=x;
    if(rnk[x]==rnk[y]) ++rnk[x];
  }
}

inline bool issame(int x, int y) {
  return find(x)==find(y);
}

int main() {
  //freopen("data.in","r",stdin);
  int n=read(),m=read(),q=read();
  init(n);
  while(m--) {
    int a=read(),b=read();
    merge(a,b);
  }
  while(q--) {
    int a=read(),b=read();
    if(issame(a,b)) puts("Yes");
    else puts("No");
  }
  return 0;
}