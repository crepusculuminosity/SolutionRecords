#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll n;
ll phi(ll n) {
  ll res = n;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      res = res - res / i;
      while (n % i == 0)
        n /= i;
    }
  }
  if (n > 1)
    res = res - res / n;
  return res;
}
int main() {
  while (~scanf("%lld",&n)) {
    printf("%lld\n",phi(n-1));
  }
  return 0;
}