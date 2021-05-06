#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    ll n, k;
    cin >> n >> k;
    ll ans = ((((n + 1) * (n + 2) / 2) % mod) * (k + 1)) % mod;
    cout << ans << '\n';
  }
  return 0;
}