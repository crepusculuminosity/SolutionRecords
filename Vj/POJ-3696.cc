#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll L, x, y;

ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  ll d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
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
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int kse = 1;
  while (scanf("%lld", &L) && L) {
    ll d = __gcd(L, (ll)8), m = 9 * L / d, M = phi(m);
  }
  return 0;
}