#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=5010;
struct A {
  int k,s;
  bool operator<(const A & x) const {
    if(s==x.s) return k<x.k;
    return s>x.s;
  }
}q[maxn];
int n,m;
int main() {
  //freopen("data.in", "r",stdin);
  cin>>n>>m;
  for(int i=1;i<=n;i++) cin>>q[i].k>>q[i].s;
  sort(q+1,q+ 1 + n);
  int od=3*m/2;
  int res=q[od].s;int cn;
  for(cn=od;cn<=n&&q[cn].s==res;cn++);
  cout<<res<<" "<<--cn<<endl;
  for(int i=1;i<=cn;i++) 
    cout<<q[i].k<<" "<<q[i].s<<endl;
  return 0;
}