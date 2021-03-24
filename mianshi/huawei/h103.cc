#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e4;
int a[maxn];
int dp[maxn];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = x * 10 + ch - 48, ch = getchar();
  return x;
}
int main() {
  int n;
  // freopen("data.in", "r", stdin);
  while (~scanf("%d", &n)) {
    int ans = -1;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
      a[i] = read();
    for (int i = 1; i <= n; i++) {
      dp[i] = 1;
      for (int j = 1; j < i; j++)
        if (a[j] < a[i])
          dp[i] = max(dp[i], dp[j] + 1);
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}