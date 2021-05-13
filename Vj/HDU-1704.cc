#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 510;
int a[maxn][maxn];
int n, m;

void floyd() {
  for (int i = 1; i <= n; i++)
    a[i][i] = 1;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      if (a[i][k])
        for (int j = 1; j <= n; j++)
          if (a[k][j])
            a[i][j] = 1;
}

int main() {

  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    memset(a, 0, sizeof(a));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      a[u][v] = 1;
    }
    floyd();
    int ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        if (a[i][j] + a[j][i] == 0)
          ++ans;
    cout << ans << '\n';
  }
  return 0;
}