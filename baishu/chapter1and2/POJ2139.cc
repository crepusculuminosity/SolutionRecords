#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 310;
int dp[maxn][maxn], t[maxn];
int n, m;

void floyd() {
  for (int i = 1; i <= n; i++)
    dp[i][i] = 0;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= m; i++) {
    memset(t, 0, sizeof(t));
    int u;
    cin >> u;
    for (int j = 1; j <= u; j++)
      cin >> t[j];
    for (int k = 1; k < maxn && t[k]; k++) {
      for (int l = 1; l < maxn; l++) {
        if (k == l)
          dp[t[k]][t[l]] = dp[t[l]][t[k]] = 0;
        else
          dp[t[k]][t[l]] = dp[t[l]][t[k]] = 1;
      }
    }
  }
  floyd();
  int sum = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    int a = 0;
    for (int j = 1; j <= n; j++)
      a += dp[i][j];
    sum = min(sum, a);
  }
  cout << sum * 100 / (n - 1);
  return 0;
}