#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1005;
int fa[maxn], rnk[maxn];
int n,m;
void init() {
  for(int i=1;i<=n;i++) fa[i]=i, rnk[i]=0;
}
int find(int x) {
  if(x==fa[x]) return x;
  return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
  x=find(x); y=find(y);
  if(x==y) return;
  if(rnk[x]< rnk[y]) fa[x]=y;
  else {
    fa[y]=x;
    if(rnk[x]== rnk[y]) ++rnk[x];
  }
}
int main() {
  //freopen("data.in", "r", stdin);
  while(cin>>n>>m&&n) {
    set<int> s;
    init();
    for(int i=1;i<=m;i++) {
      int a,b;
      cin>>a>>b;
      merge(a, b);
    }
    int t=n;
    for(int i=1;i<=n;i++)
      if(i!=find(i)) t--;
    cout<<--t<<endl;
  }
  return 0;
}