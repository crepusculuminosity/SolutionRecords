#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1250;
char a[maxn], b[maxn];
int dp[maxn][maxn];

int main() {
  while (cin >> (a + 1)) {
    memset(dp, -1, sizeof(dp));
    int n = strlen(a + 1);
    for (int i = n; i >= 1; i--)
      b[n - i + 1] = a[i];
    int ans = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        else if (a[i] == b[j])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = 0;
        ans = max(ans, dp[i][j]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}