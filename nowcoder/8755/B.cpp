#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

set<ll> a;

inline ll read() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

inline ll _qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = (res * a) % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res % mod;
}
inline ll work(int n, int m) {
  ll s = 1, c = 1;
  for (int i = 1; i <= m; ++i)
    s = (s * i) % mod;
  for (int i = n - m + 1; i <= n; ++i)
    c = (c * i) % mod;
  return (c * _qpow(s, mod - 2)) % mod;
}

int main() {
  ll n = read(), k = read();
  ll x;
  /*for(int i=1;i<=n;++i) {
    x=read();
    a.insert(x);
}*/

  ll ans = work(n, k);
  printf("%lld\n", ans);
  return 0;
}