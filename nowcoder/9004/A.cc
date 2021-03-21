#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

ll _qpow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1)
      ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}

long long tree4(long long n) {
  // write code here
  ll ans = 0;
  for (ll i = 1; i <= 30; i++) {
    ll a = _qpow(2, i - 1);
    ll b = _qpow(2, i) - 1;
    if (a > n)
      break;
    b = min(b, n);
    ans = (ans + (a + b) * (b - a + 1) / 2 % mod * i) % mod;
  }
  return ans;
}

int main() {
  clock_t s, e;
  s = clock();
  for (int i = 1; i <= 100000; i++)
    tree4(i);
  e = clock();
  cout << (double)(e - s) / CLOCKS_PER_SEC << endl;
  return 0;
}