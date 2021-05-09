#include <bits/stdc++.h>
using namespace std;
int st[310][310][9];
int Log2[310];
int n, m;
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _;
  Log2[1] = 0, Log2[2] = 1;
  for (int i = 3; i <= 305; i++) Log2[i] = Log2[i / 2] + 1;
  // cin >> _;
  while (cin >> n >> m) {
    memset(st, 0, sizeof(st));
    // int n, m;
    // cin >> n >> m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cin >> st[i][j][0];
    for (int k = 1; k <= 8; k++)
      for (int i = 1; i + (1 << k) - 1 <= n; i++)
        for (int j = 1; j + (1 << k) - 1 <= m; j++) {
          int a = st[i][j][k - 1];
          int b = st[i + (1 << k - 1)][j][k - 1];
          int c = st[i][j + (1 << k - 1)][k - 1];
          int d = st[i + (1 << k - 1)][j + (1 << k - 1)][k - 1];
          st[i][j][k] = max(a, max(b, max(c, d)));
        }
    // cout << "hello\n";
    int q;
    cin >> q;
    while (q--) {
      int l1, r1, l2, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      int x = max(Log2[r2 - r1 + 1], Log2[l2 - l1 + 1]);
      int a = st[l1][r1][x];
      int b = st[max(l2 - (1 << x) + 1, 1)][r1][x];
      int c = st[l1][max(r2 - (1 << x) + 1, 1)][x];
      int d = st[max(l2 - (1 << x) + 1, 1)][max(r2 - (1 << x) + 1, 1)][x];
      int ret = max(a, max(b, max(c, d)));
      cout << ret << ' ';
      if (st[l1][r1][0] == ret || st[l1][r2][0] == ret ||
          st[l2][r1][0] == ret || st[l2][r2][0] == ret)
        cout << "yes\n";
      else
        cout << "no\n";
    }
  }
  return 0;
}