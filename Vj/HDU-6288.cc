#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
int a, b;
ll k;

int Log2(ll x) {
  int k = 0;
  while (1 << k < x)
    ++k;
  return k;
}

ll qsm(ll a, int b) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}

int main() {
  freopen("data.in", "r", stdin);
  int _;
  cin >> _;
  while (_--) {
    cin >> a >> b >> k;
    ll l = 1, r = k + 1;
    while (r - l > 1) {
      ll mid = r + l >> 1;
      if (qsm(mid, a) * qsm(log2(mid), b) <= k)
        l = mid;
      else
        r = mid;
    }
    cout << l << endl;
  }
  return 0;
}