#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 100003;
ll n, m, ans;

ll _qpow(ll a, ll b) {
  int ans = 1;
  while (b) {
    if (b & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}

int main() {
  cin >> m >> n;
  ll p = _qpow(m, n);
  ll q = (m * _qpow(m - 1, n - 1)) % mod;
  cout << (p - q + mod) % mod << endl;
  return 0;
}