#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 110;
int dp[maxn][maxn];
char str[maxn];
int n;
bool match(char a, char b) {
  return (a == '(' && b == ')') || (a == '[' && b == ']');
}

int dfs(int i, int j) {
  if (j <= i)
    return 0;
  if (~dp[i][j])
    return dp[i][j];
  int &res = dp[i][j] = 0;
  if (match(str[i], str[j]))
    res = 2 + dfs(i + 1, j - 1);
  for (int k = i; k <= j; k++)
    res = max(res, dfs(i, k) + dfs(k + 1, j));
  return res;
}

void solve1() {
  memset(dp, -1, sizeof(dp));
  cout << dfs(1, n) << '\n';
}
void solve2() {
  memset(dp, 0, sizeof(dp));
  for (int len = 1; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      if (match(str[i], str[j]))
        dp[i][j] = dp[i + 1][j - 1] + 2;
      for (int k = i; k < j; k++)
        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
    }
  }
  cout << dp[1][n] << '\n';
}
int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  while (cin >> (str + 1) && str[1] != 'e') {
    n = strlen(str + 1);
    solve1();
    // solve2();
  }
  return 0;
}