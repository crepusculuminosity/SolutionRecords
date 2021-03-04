#include <bits/stdc++.h>
using namespace std;
#define lb(x) ((x) & (-x))
constexpr int maxn=1e5+10;
int tr[maxn];
int n;
typedef long long ll;

inline int read() {
  int x=0;
  char ch=getchar();
  while(ch<'0' || ch > '9') ch=getchar();
  while(ch>='0' && ch <= '9') {
    x=x*10 + ch - '0';
    ch=getchar();
  }
  return x;
}

inline void update(int x,int k) {
  while(x<=n) {
    tr[x]+=k;
    x+=lb(x);
  }
}

inline int query(int x) {
  int res=0;
  while(x) {
    res+=tr[x];
    x-=lb(x);
  }
  return res;
}

int main() {
  //freopen("data.in", "r", stdin);
  n=read();
  ll sum=0;
  for(int i=1;i<=n;i++) {
    int x=read();
    update(x,1);
    sum+=i-query(x);
  }
  int q=read();
  int ans=sum%2;
  while(q--) {
    int l=read(),r=read();
    ll t=(r-l+1)*(r-l)>>1;
    ans=(ans+(t%2))%2;
    //if(ans) ans^=1;
    if(ans) puts("dislike");
    else puts("like");
  }
  return 0;
}