#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1010;
char a[maxn], b[maxn];
int dp[maxn][maxn];

void print(int i, int j) {
  if (i == 0 || j == 0)
    return;
  if (a[i] == b[j]) {
    print(i - 1, j - 1);
    cout << a[i];
  } else {
    if (dp[i][j - 1] >= dp[i - 1][j])
      print(i, j - 1);
    else
      print(i - 1, j);
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  cin >> (a + 1) >> (b + 1);
  int n = strlen(a + 1), m = strlen(b + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  // cout << dp[n][m] << endl;
  print(n, m);
  return 0;
}