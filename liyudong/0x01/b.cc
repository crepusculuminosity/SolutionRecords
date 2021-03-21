#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ksm(ll a, ll b, ll p) {
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
  freopen("data.in", "r", stdin);
  int _;
  cin >> _;
  while (_--) {
    ll ans = 0;
    int p, n;
    cin >> p >> n;
    for (int i = 1; i <= n; i++) {
      int a, b;
      cin >> a >> b;
      ans += ksm(a, b, p);
    }
    cout << ans % p << endl;
  }
  return 0;
}