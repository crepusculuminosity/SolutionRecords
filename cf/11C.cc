#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
double p[20][20], dp[1 << 20];
int n;

int main() {

  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> p[i][j];
  dp[(1 << n) - 1] = 1;
  for (int i = (1 << n) - 1; i; i--) {
    int c = __builtin_popcount(i);
    for (int j = 1; j <= n; j++) {
      if (i & (1 << j - 1))
        continue;
      for (int k = 1; k <= n; k++) {
        if (!(i & (1 << k - 1)))
          continue;
        dp[i] += dp[i | 1 << j - 1] * p[k][j] * 2.0 / c / (1 + c);
      }
    }
  }
  for (int i = 0; i < n; i++)
    cout << fixed << setprecision(6) << dp[1 << i] << ' ';
  return 0;
}