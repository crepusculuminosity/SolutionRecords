#include <cstring>
#include <iostream>
using namespace std;
int dp[400][400], a[400][400];
int n;
int dfs(int i, int j) {
  if (~dp[i][j])
    return dp[i][j];
  if (i == n)
    return dp[i][j] = a[n][j];
  int &res = dp[i][j] = a[i][j];
  res += max(dfs(i + 1, j), dfs(i + 1, j + 1));
  return res;
}
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  cin >> n;
  // memset(dp,-1,sizeof(dp));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) {
      cin >> a[i][j];
      if (n == i)
        dp[n][j] = a[n][j];
    }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= i; j++)
      dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
  }
  // cout << dfs(1, 1);
  cout << dp[1][1];
  return 0;
}