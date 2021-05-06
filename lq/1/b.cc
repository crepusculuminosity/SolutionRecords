#include <bits/stdc++.h>
using namespace std;
int dp[15];

int dfs(int x) {
  if (~dp[x])
    return dp[x];
  if (x == 0)
    return dp[0] = 1;
  if (x == 1)
    return dp[1] = 1;
  if (x == 2)
    return dp[2] = 2;
  if (x == 3)
    return dp[3] = 4;
  if (x == 5 || x == 7)
    return dp[x] = 0;
  int &res = dp[x] = 0;
  res = dfs(x - 1) + dfs(x - 2) + dfs(x - 3) + dfs(x - 4);
  return res;
}
int main() {
  memset(dp, -1, sizeof(dp));
  cout << dfs(10);
  return 0;
}
