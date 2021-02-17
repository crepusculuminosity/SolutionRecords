#define RF freopen("data.in", "r", stdin);
#define WF freopen("data.out", "w", stdout);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[1000100][5];
constexpr int mod = 1e9 + 7;
int n;
ll ans;

int main() {
  scanf("%d", &n);
  f[1][0] = 25;
  f[1][1] = 1;
  f[1][2] = 0;
  for (int i = 2; i <= n; i++) {
    f[i][0] = (25 * f[i - 1][0]);
    f[i][1] = (25 * f[i - 1][1] + f[i - 1][0]);
    f[i][2] = (f[i - 1][1] + f[i - 1][2] * 26);
    // ans=(ans+f[i][2])%mod;
  }
  printf("%lld", f[n][2]);
  return 0;
}