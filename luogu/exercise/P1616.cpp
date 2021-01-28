#include <bits/stdc++.h>
using namespace std;

// const int MAXN=10005;
typedef long long ll;

ll m, n, dp[10000005], t[10005], v[10005];
int main() {
  cin >> m >> n;
  for (int i = 1; i <= n; i++)
    cin >> t[i] >> v[i];
  for (int i = 1; i <= n; i++) {
    for (int j = t[i]; j <= m; j++) {
      dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
    }
  }
  cout << dp[m] << endl;
  return 0;
}