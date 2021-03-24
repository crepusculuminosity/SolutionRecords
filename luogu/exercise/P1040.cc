#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 35;
int a[maxn];
ll dp[35][35];
int cnt = 0;
int ans[maxn];
int b[maxn][maxn];
ll dfs(int l, int r) {
  // if(dp[l][r]) return dp[l][r];
  if (l == r) {
    b[l][r] = l;
    return dp[l][r] = a[l];
  }
  if (l > r)
    return dp[l][r] = 1;
  if (dp[l][r])
    return dp[l][r];
  ll &res = dp[l][r];
  res = 0;
  int root;
  for (int i = l; i <= r; i++) {
    ll t = a[i] + dfs(l, i - 1) * dfs(i + 1, r);
    if (t > res)
      res = t, root = i;
  }
  b[l][r] = root;
  return res;
}

void print(int l, int r) {
  if (l > r)
    return;
  cout << b[l][r] << ' ';
  print(l, b[l][r] - 1);
  print(b[l][r] + 1, r);
}

int main() {
  // freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  cout << dfs(1, n) << endl;
  print(1, n);
  return 0;
}