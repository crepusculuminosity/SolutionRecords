#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll qsm(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = res * a % n;
    a = a * a % n;
    b >>= 1;
  }
  return res;
}
bool check(ll x) {
  for (ll i = 2; i * i <= x; i++)
    if (x % i == 0)
      return 1;
  return 0;
}

int main() {
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  while (~scanf("%lld", &n) && n) {
    if (check(n)) {
      bool f = 1;
      for (int x = 2; x < n; x++) {
        f &= (qsm(x, n) == x);
        if (!f)
          break;
      }
      if (f)
        printf("The number %d is a Carmichael number.\n", n);
      else
        printf("%d is normal.\n", n);
    } else
      printf("%d is normal.\n", n);
  }
  return 0;
}