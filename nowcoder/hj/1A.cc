#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
long long f[maxn][3];
const int mod = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  f[1][0] = 25, f[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i][0] = f[i - 1][0] * 25 % mod;
    f[i][1] = (f[i - 1][1] * 25 + f[i - 1][0]) % mod;
    f[i][2] = (f[i - 1][1] + f[i - 1][2] * 26) % mod;
    ans = (ans + f[i][2]) % mod;
  }
  cout << ans;
  return 0;
}