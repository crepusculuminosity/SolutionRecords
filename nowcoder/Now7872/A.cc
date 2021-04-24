#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll x, y;
constexpr ll mod = 1e9 + 7;

ll qsm(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    cin >> x >> y;
    ll a = 1, b = 1;
    ll x=min(x,y),y=x+y
    for (int i = 1; i <= x; i++)
      a = a * (a + 1) % mod;
    for (int i = 1; i <= y; i++)
      b = b * (b + 1) % mod;
    cout << max(a, b) * qsm(min(a, b), mod - 2) % mod << '\n';
  }
  return 0;
}