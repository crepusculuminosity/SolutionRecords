#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 105;
int g[maxn][maxn];
int dp[210][210];
int a[210], L;
constexpr int INF = 0x3f3f3f3f;
int main() {

  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    int n, m;
    cin >> n >> m;
    while (m--) {
      int u, v;
      cin >> u >> v;
      g[u][v] = g[v][u] = 1;
    }
    // int L;
    cin >> L;
    for (int i = 1; i <= L; i++)
      cin >> a[i];
    for (int i = 1; i <= L; i++)
      for (int j = 1; j <= n; j++) {
        dp[i][j] = INF;
        for (int k = 1; k <= n; k++) {
          if (j == k || g[j][k]) {
            if (j == a[i])
              dp[i][j] = min(dp[i][j], dp[i - 1][k]);
            else
              dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
          }
        }
      }
    int ans = INF;
    for (int i = 1; i <= n; i++)
      ans = min(dp[L][i], ans);
    cout << ans << '\n';
  }
  return 0;
}