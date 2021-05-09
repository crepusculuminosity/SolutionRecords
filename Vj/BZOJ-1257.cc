#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k, ans, l, r;

int main() {
  cin >> n >> k;
  ans = n * k;
  for (l = 1; l <= n; l = r + 1) {
    r = k / l ? min(k / (k / l), n) : n;
    ans -= (l + r) * (r - l + 1) * (k / l) / 2;
  }
  cout << ans;
  return 0;
}