#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f[400][400];
int n, k;
constexpr int mod = 1e9 + 7;
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  cin >> n >> k;
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++)
      f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * (k - j + 1) % mod) % mod;
  }
  ll ans = 0;
  for (int i = 1; i <= k; i++)
    ans = (ans + f[n][i]) % mod;
  cout << ans;
  return 0;
}