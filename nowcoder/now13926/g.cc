#include <iostream>
using namespace std;
typedef long long ll;
int h, s;
ll mod = 1e9 + 7;
ll dp[101][101][5055];

int main() {
  cin >> h >> s;
  s = h * (h + 1) / 2 - s;
  dp[0][0][0] = 1;

  for (int i = 1; i <= h; i++) {
    for (int k = 0; k <= s; k++) {
      ll sum = 0;
      for (int j = 0; j <= i; j++) {
        if (j <= k)
          sum = (sum + dp[i - 1][min(j, i - 1)][k - j]) % mod;
        dp[i][j][k] = sum;
      }
    }
  }

  cout << dp[h][h][s];

  return 0;
}
