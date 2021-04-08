#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 50;
ll dp[maxn][3];

int main() {
  dp[1][0] = dp[1][1] = dp[1][2] = 1;
  for (int i = 2; i <= 40; i++) {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
    dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
    dp[i][2] = dp[i][0];
  }
  int n;
  while (cin >> n) {
    cout << dp[n][0] + dp[n][1] + dp[n][2] << '\n';
  }
  return 0;
}