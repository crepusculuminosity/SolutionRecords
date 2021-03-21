#include <bits/stdc++.h>
typedef long long ll;

ll x, y, d;
ll m, n, p, q, l;

void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}

int main() {
  scanf("%lld%lld%lld%lld%lld", &m, &n, &p, &q, &l);
  exgcd(l, q - p, d, x, y);
  // printf("%ld %ld %ld",x,y,d);
  ll mod = abs(l / d);
  if ((m - n) % d || m == n) {
    printf("Impossible\n");
  }

  else {
    ll ans = ((m - n) / d * y % mod + mod) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}