#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110][110];

void floyd() {
  for (int i = 0; i < n; i++)
    a[i][i] = 0;
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> n >> m) {
    memset(a, 0x3f, sizeof(a));
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      a[u][v] = a[v][u] = 1;
    }
    floyd();
    bool f = 1;
    for (int i = 0; i < n && f; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] > 7) {
          f = 0;
          break;
        }
      }
    }
    if (f)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}