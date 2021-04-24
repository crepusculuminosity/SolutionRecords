#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 110;

int a[maxn][maxn];
int n, m;

void floyd() {
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        a[i][j] |= a[i][k] & a[k][j];
}
int main() {
  //freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    a[u][v] = 1;
  }
  floyd();
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++)
      if (a[i][j] | a[j][i])
        ++cnt;
    if (cnt == n - 1)
      ++ans;
  }
  cout << ans;
  return 0;
}