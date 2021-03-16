#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr ll mod = 1e9 + 7;

ll n, m;

ll powmod(ll a, ll b) {
  ll res = 1;
  for (; b; b >>= 1) {
    if (b & 1)
      res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}

ll inv(ll x) { return powmod(x, mod - 2); }

ll sum_2(ll p) { return p * (p + 1) % mod * (2 * p + 1) % mod * inv(6) % mod; }

ll sum_3(ll p) {
  return p * p % mod * (p + 1) % mod * (p + 1) % mod * inv(4) % mod;
}

int main() {
  scanf("%lld %lld", &n, &m);

  ll num1 = n * sum_2(n) % mod;
  for (ll l = 1, r; l <= n; l = r + 1) {
    r = n / (n / l);
    ll t = (sum_3(r) - sum_3(l - 1) + mod) % mod;
    t = t * (n / l) % mod;
    num1 = (num1 - t + mod) % mod;
  }

  ll num2 = m * m % mod * (1 + m) % mod * inv(2) % mod;
  for (ll l = 1, r; l <= m; l = r + 1) {
    r = m / (m / l);
    ll t = (sum_2(r) - sum_2(l - 1) + mod) % mod;
    t = t * (m / l) % mod;
    num2 = (num2 - t + mod) % mod;
  }

  printf("%lld", num1 * num2 % mod);
}