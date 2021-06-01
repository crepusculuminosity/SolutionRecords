#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 40;
using ll = long long;
ll f[maxn][maxn], g[maxn][maxn];
char a[maxn], b[maxn];
int main() {

  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _, T = 0;
  cin >> _;
  while (_--) {
    // if(T++) cout<<'\n';
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    cin >> (a + 1) >> (b + 1);
    int n = strlen(a + 1), m = strlen(b + 1);
    //g[0][0] = 1;
    for (int i = 0; i <= n; i++)
      f[i][0] = i, g[i][0] = 1;
    for (int i = 0; i <= m; i++)
      f[0][i] = i, g[0][i] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (a[i] == b[j])
          f[i][j] = 1 + f[i - 1][j - 1], g[i][j] = g[i - 1][j - 1];
        else if (f[i - 1][j] < f[i][j - 1])
          f[i][j] = 1 + f[i - 1][j], g[i][j] = g[i - 1][j];
        else if (f[i - 1][j] > f[i][j - 1])
          f[i][j] = 1 + f[i][j - 1], g[i][j] = g[i][j - 1];
        else
          f[i][j] = 1 + f[i - 1][j], g[i][j] = g[i - 1][j] + g[i][j - 1];
      }
    cout << "Case #" << ++T << ": " << f[n][m] << ' ' << g[n][m] << '\n';
  }
  return 0;
}