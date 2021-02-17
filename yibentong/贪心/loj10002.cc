#include <bits/stdc++.h>
using namespace std;
constexpr int maxn =2e4+5;
int n,l,w,x,r;
struct node {
  double x,y;
  bool operator<(const node &a) const {
    return x<a.x;
  }
}q[maxn];

int main() {
  //freopen("data.in", "r", stdin);
  int _; cin>>_;
  while(_--) {
    cin>>n>>l>>w;
    int cnt=0;
    for(int i=1;i<=n;i++) {
      cin>>x>>r;
      if(2*r<=w) continue;
      cnt++;
      q[cnt].x=x-sqrt(r*r-w*w*0.25);
      q[cnt].y=x+sqrt(r*r-w*w*0.25);
    }
    sort(q+1,q+1+cnt);
    int ans=0,i=1,f=1;
    double t=0;
    while(t<l) {
      ans++;
      double s=t;
      for(;q[i].x<=s&&i<=cnt;i++) t=max(t,q[i].y);
      if(s==t&&s<l) {
        f=0;
        break;
      }
    }
    if(f) cout<<ans<<endl;
    else cout<<-1<<endl;
  }
  return 0;
}