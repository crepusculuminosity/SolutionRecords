#include <bits/stdc++.h>
inline int read() {
  int t = 0;
  char v = getchar();
  while (v < '0')
    v = getchar();
  while (v >= '0')
    t = (t << 3) + (t << 1) + v - 48, v = getchar();
  return t;
}
using namespace std;
int n, m, a[1000002], k, dp[100002][6], ans, t;
int main() {
  freopen("data.in", "r", stdin);
  t = read();
  while (t--) {
    n = read(), m = read(), k = read();
    ans = 0;
    for (int i = 1; i <= n; ++i)
      a[i] = read();
    for (int i = 0; i <= k; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[j][i] = dp[j - 1][i] + a[j];
        // if(i&&j!=n)
        dp[j][i] = max(dp[j][i], dp[j + 1][i - 1] + a[j]);
        if (j - 1 + i * 2 == m)
          ans = max(ans, dp[j][i]);
      }
    }
    printf("%d\n", ans);
  }
}