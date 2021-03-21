#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ksc(ll a, ll b, ll mod) {
  ll base = a, ans = 0;
  while (b) {
    if (b & 1)
      ans = (ans + a) % mod;
    a = (a + a) % mod;
    b >>= 1;
  }
  return ans % mod;
}

ll qsm(ll a, ll b, ll mod) {
  ll base = a, ans = 1;
  while (b) {
    if (b & 1)
      ans = ksc(ans, a, mod);
    a = ksc(a, a, mod);
    b >>= 1;
  }
  return ans % mod;
}

int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    ll a, b, p;
    cin >> a >> b >> p;
    cout << qsm(a, b, p) << '\n';
  }
  return 0;
}