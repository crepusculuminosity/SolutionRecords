#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1200;
int num[maxn], prime[maxn], cnt;

void init() {
  for (int i = 2; i < maxn; i++) {
    if (!num[i])
      prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] < maxn; j++) {
      num[i * prime[j]] = 1;
      if (i % prime[j] == 0)
        break;
    }
  }
}
int dp[1200][20];
int dfs(int n, int k) {
  if (~dp[n][k])
    return dp[n][k];
  if (n < k * 2)
    return dp[n][k]=0;
  if (k == 1) {
    if (num[n])
      return dp[n][k] = 0;
    return 1;
  }

  int &res = dp[n][k] = 0;
  for (int i = 1;prime[i] < n; i++)
    res += dfs(n - prime[i], k - 1);
  return res;
}
int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);

  init();
  memset(dp, -1, sizeof(dp));
  int n, k;
  while (cin >> n >> k && n + k) {
    cout << dfs(n, k) << '\n';
  }
  return 0;
}