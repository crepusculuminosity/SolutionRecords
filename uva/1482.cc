#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll SG(ll n) {
  return n%2?SG(n/2):n/2;
}

int main() {
  int _; scanf("%d",&_);
  while(_--) {
    int n; scanf("%d",&n);
    ll a,v=0;
    for(int i=1;i<=n;i++) {
      scanf("%lld",&a);
      v^=SG(a);
    }
    if(v) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}