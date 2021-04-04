#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll qsm(ll a, ll b, ll p) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res % p;
}

int main() {
  int _;
  cin >> _;
  while (_--) {
    int p, h;
    cin >> p >> h;
    ll ans = 0;
    for (int i = 1; i <= h; i++) {
      ll a, b;
      cin >> a >> b;
      ans += qsm(a, b, p);
    }
    cout << ans % p << '\n';
  }
  return 0;
}