#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 21;
typedef long long ll;
ll f[maxn][maxn][maxn];

ll dfs(int k, int i, int j) {
  if (~f[k][i][j])
    return f[k][i][j];
  if (i + j > k + 1 || (i * j == 0))
    return f[k][i][j] = 0;
  ll &res = f[k][i][j] = 0;

  res = dfs(k - 1, i - 1, j) + dfs(k - 1, i, j - 1);
  if (k > 2)
    res += (k - 2) * dfs(k - 1, i, j);

  return res;
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  // init();
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  memset(f, -1, sizeof(f));
  f[1][1][1] = 1, f[2][1][2] = f[2][2][1] = 1;
  while (_--) {
    int k, i, j;
    cin >> k >> i >> j;
    cout << dfs(k, i, j) << '\n';
  }
  return 0;
}