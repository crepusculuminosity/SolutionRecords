#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;

int n, a[MAXN], dp[MAXN];

int main() {
  while (~scanf("%d", &n) && n) {
    memset(dp, 0, sizeof dp);
    int ans = 0;
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      dp[i] = a[i];
      for (int j = 1; j <= i; j++) {
        if (a[j] < a[i])
          dp[i] = max(dp[i], dp[j] + a[i]);
      }
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}