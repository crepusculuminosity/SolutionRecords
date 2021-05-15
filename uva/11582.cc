#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int maxn = 1e6 + 10;
ll f[maxn];
ll a, b, n;
ll ksm(ll a, ll b, ll p) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}

int main() {
  //freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    cin >> a >> b >> n;
    ll p = 0;
    f[0] = 0, f[1] = f[2] = 1 % n;
    for (int i = 3; i < maxn; i++) {
      f[i] = (f[i - 1] + f[i - 2]) % n;
      if (f[i] == f[2] && f[i - 1] == f[1]) {
        p = i - 2;
        break;
      }
    }
    ll x = ksm(a % p, b,p);
    cout << f[x] << '\n';
  }
  return 0;
}