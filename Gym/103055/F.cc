#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll g(ll m, ll x) { return m / (m / x); }
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    if (m % n == 0) {
      printf("0\n");
    } else if (n > m) {
      printf("%lld\n", n - m);
    } else {
      ll res = 1e9;
      for (ll l = 1, r; l <= n; l = r + 1) {
        r = min(n, g(m - 1, l));
        if (l <= n)
          res = min(res, (m - 1) / l * l);
        // printf("%lld %lld\n", l, res);
      }
      printf("%lld\n", n - m + res);
    }
  }
  return 0;
}