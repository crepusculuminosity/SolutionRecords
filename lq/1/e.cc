#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
#define ll long long
const ll mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  long long k;
  // cin>>n>>k;
  n = 1000, k = 500;
  long long ans = 2 * n * (n - 1) % mod;

  for (long long x = 1; x <= n - 1; x++) {
    for (long long y = 1; y <= n - 1; y++) {
      if (__gcd(x, y) == 1 && x * x + y * y <= k * k) {
        ans = (2 * (n - x) * (n - y) % mod + ans) % mod;
      }
    }
  }

  cout << ans;
  return 0;
}
