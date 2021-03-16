#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll G(ll x) {
  ll ans = 0;
  for (ll l = 1, r; l <= x; l = r + 1) {
    r = x / (x / l);
    ans += (l + r) * (r - l + 1) / 2 * (x / l);
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  cout << G(G(n));
  return 0;
}