#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll n;
inline ll read() {
  ll x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}

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
  while (n = read()) {
    printf("%lld\n",phi(n));
  }
  return 0;
}