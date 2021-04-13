#include <bits/stdc++.h>
using namespace std;
int L, n;
int a[60];
int dp[60][60];

int dfs(int l, int r) {
  if (~dp[l][r])
    return dp[l][r];
  if (l + 1 == r)
    return dp[l][r] = 0;
  int &ans = dp[l][r] = 0x3f3f3f3f;
  for (int k = l + 1; k < r; k++)
    ans = min(ans, dfs(l, k) + dfs(k, r));
  ans += a[r] - a[l];
  return ans;
}
int main() {
  // freopen("data.in","r",stdin);
  while (cin >> L && L) {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    a[n + 1] = L;
    cout << "The minimum cutting is " << dfs(0, n + 1) << ".\n";
  }
  return 0;
}