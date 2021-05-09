#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll L;
ll phi(ll n) {
  ll ans = n;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0)
        n /= i;
    }
  }
  if (n > 1)
    ans = ans / n * (n - 1);
  return ans;
}

ll qsm(ll a, ll b, ll p) {
  int res = 1;
  while (b) {
    if (b & 1)
      res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}

int main() {
  // freopen("data.in", "r", stdin);
  int kse = 1;
  while (~scanf("%lld", &L) && L) {
    ll ans = 0;
    ll g = 9 * L / __gcd((ll)8, L), p = phi(g);
    // cout<<p<<endl;
    for (ll i = 1; i * i <= p; i++) {
      if (p % i == 0 && qsm(10, i, g) == 1) {
        ans = i;
        break;
      }
    }
    printf("Case %d: %lld\n", kse++, ans);
  }
  return 0;
}