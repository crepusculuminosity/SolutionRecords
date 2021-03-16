#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll mod = 1e9 + 7;

ll ksm(ll a, ll b) {
  int res = 1;
  while (b) {
    if (b & 1)
      res *= a % mod;
    a *= a % mod;
    b >>= 1;
  }
  return res;
}

int main() {
  ll n, m = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    m |= x;
  }
  printf("%lld", ksm(2, n - 1) * m % mod);
}