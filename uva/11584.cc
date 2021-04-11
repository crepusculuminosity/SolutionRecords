#include <bits/stdc++.h>
using namespace std;
char ch[1010];
int a[1010][1010];
int dp[1010];

int dfs(int l, int r) {
  if (~a[l][r])
    return a[l][r];

  if (l == r)
    return a[l][r] = 1;

  if (l + 1 == r && ch[l] == ch[r])
    return a[l][r] = 1;

  int &res = a[l][r] = 0;

  if (ch[l] == ch[r] && dfs(l + 1, r - 1) == 1)
    res = 1;

  return res;
}

int main() {
  int n;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // freopen("data.in","r",stdin);
  cin >> n;

  while (n--) {
    memset(a, -1, sizeof(a));
    // memset(dp,0x3f,sizeof(dp));
    cin >> (ch + 1);
    int len = strlen(ch + 1);

    for (int i = 1; i <= len; i++)
      for (int j = i; j <= len; j++)
        dfs(i, j);

    for (int i = 0; i <= len; i++)
      dp[i] = i;

    for (int i = 1; i <= len; i++) {
      for (int j = 0; j < i; j++) {
        if (a[j + 1][i])
          dp[i] = min(dp[i], 1 + dp[j]);
      }
    }

    cout << dp[len] << '\n';
  }

  return 0;
}
