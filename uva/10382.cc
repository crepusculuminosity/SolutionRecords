#include <bits/stdc++.h>
using namespace std;
constexpr int maxn =1e4+5;
int n,l,w;
double x,r;
//sb UVA 题面说的是整数实际要用浮点数


struct node {
  double x,y;
  bool operator<(const node &a) const {
    return x<a.x;
  }
}q[maxn];

int main() {
  //freopen("data.in", "r", stdin);
  //int _; cin>>_;
  while(~scanf("%d%d%d", &n,&l,&w)) {

    int cnt=0;
    for(int i=1;i<=n;i++) {
      //cin>>x>>r;
      scanf("%lf%lf", &x,&r);
      if(2*r<=w) continue;

      q[++cnt].x=x-sqrt(r*r-w*w*0.25);
      q[cnt].y=x+sqrt(r*r-w*w*0.25);
    }

    sort(q+1,q+1+cnt);
    int ans=0,i=1,f=1;
    double t=0;
    while(t<l) {
      ++ans;
      double lst=t;
      while(q[i].x<=lst&&i<=cnt) t=max(t,q[i++].y);
      if(lst==t&&lst<l) {
        ans=-1;
        break;
      }
    }
    //cout<<ans<<endl;
    printf("%d\n",ans);
  }
  return 0;
}