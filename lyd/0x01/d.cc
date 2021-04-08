#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 0x3f3f3f3f;
int dp[(1 << 20) + 10][25];
int a[30][30];
int n;

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  memset(dp, 0x3f, sizeof(dp));
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  dp[1][0] = 0;
  for (int S = 1; S < (1 << n); S++) {
    for (int i = 0; i < n; i++) {
      if (S & (1 << i)) {
        for (int j = 0; j < n; j++) {
          if (i != j) {
            dp[S][i] = min(dp[S][i], dp[S ^ (1 << i)][j] + a[i][j]);
          }
        }
      }
    }
  }
  cout << dp[(1 << n) - 1][n - 1];
  return 0;
}
