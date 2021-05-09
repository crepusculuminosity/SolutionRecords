#include <bits/stdc++.h>
using namespace std;
char ch[110];
int dp[110][110];
constexpr int M = 0x3f3f3f3f;
int n;

bool match(char a, char b) {
  return (a == '(' && b == ')') || (a == '[' && b == ']');
}

int dfs(int l, int r) {
  if (dp[l][r] < M)
    return dp[l][r];

  if (l == r)
    return dp[l][r] = 1;

  // if(l+1==r) return dp[l][r]=1;
  int &res = dp[l][r] = n;

  if (match(ch[l], ch[r]))
    res = min(res, dfs(l + 1, r - 1));

  for (int k = l; k < r; k++)
    res = min(res, dfs(l, k) + dfs(k + 1, r));

  return res;
}

void solve() {
  for (int i = 1; i <= n; i++) {
    dp[i][i] = 1;
    dp[i - 1][i] = 0;
  }

  for (int i = n - 1; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      dp[i][j] = n;

      if (match(ch[i], ch[j]))
        dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);

      for (int k = i; k < j; k++)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
    }
  }
}

void print(int i, int j) {
  if (i > j)
    return;

  if (i == j) {
    if (ch[i] == '(' || ch[i] == ')')
      cout << "()";
    else
      cout << "[]";

    return;
  }

  int res = dp[i][j];

  if (match(ch[i], ch[j]) && res == dp[i + 1][j - 1]) {
    cout << ch[i];
    print(i + 1, j - 1);
    cout << ch[j];
    return;
  }

  for (int k = i; k < j; k++) {
    if (res == dp[i][k] + dp[k + 1][j])
      print(i, k);

    print(k + 1, j);
    return;
  }
}

int main() {
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  int _;
  cin >> _;
  int f = 1;
  getchar();
  while (_--) {
    // cin>>(ch+1);
    // getchar();
    cin.getline(ch + 1, 120);
    cin.getline(ch + 1, 120);
    memset(dp, 0x3f, sizeof(dp));
    n = strlen(ch + 1);
    if (n == 0) {
      puts("\n");
      continue;
    }
    // solve();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        dfs(i, j);
    }
    print(1, n);
    cout << '\n';
    if (_)
      cout << '\n';
  }
  return 0;
}
