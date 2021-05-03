#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;

int main() {
  while(~scanf("%lld%lld",&a,&b)) {
    printf("%lld %lld\n",__gcd(a,b),a/__gcd(a,b)*b);
  }
  return 0;
}