#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
constexpr int mod = 1e9 + 7;
typedef long long ll;
ll dp[maxn], ans;

ll _qpow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1)
      ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans % mod;
}

int main() {
  int n;
  scanf("%d", &n);
  dp[2] = 1;
  ll ans = 1;
  for (int i = 3; i <= n; i++) {
    dp[i] = (25 * dp[i - 1] % mod + _qpow(26, i - 1) % mod -
             _qpow(25, i - 1) % mod) %
            mod;
    ans = (ans + dp[i]) % mod;
  }
  printf("%lld", ans % mod);
  return 0;
}