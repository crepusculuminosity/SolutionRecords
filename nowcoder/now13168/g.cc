#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 110;
double a[maxn], dp[maxn][maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n, greater<double>());
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
    dp[i][0] = dp[i - 1][0] * (1 - a[i] / 100);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      dp[i][j] =
          dp[i - 1][j] * (1 - a[i] / 100) + dp[i - 1][j - 1] * a[i] / 100;
  double res = 0;
  for (int i = 1; i <= n; i++) {
    double ans = 0;
    for (int j = 1; j <= i; j++)
      ans += dp[i][j] * pow(j, j * 1.0 / i);
    res = max(res, ans);
  }
  cout << fixed << setprecision(9) << res;
  return 0;
}