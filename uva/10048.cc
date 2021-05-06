#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 0x3f3f3f3f;
int d[110][100];
int n, m, q;

void floyd() {
  for (int i = 1; i <= n; i++)
    d[i][i] = 0;

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
  }
}

int main() {
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  int kse = 0;

  while (cin >> n >> m >> q && n) {
    memset(d, 0x3f, sizeof(d));

    for (int i = 1; i <= m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      d[a][b] = c, d[b][a] = c;
    }

    floyd();

    if (kse)
      cout << '\n';

    cout << "Case #" << ++kse << '\n';

    while (q--) {
      int a, b;
      cin >> a >> b;

      if (d[a][b] == MAXN)
        cout << "no path" << '\n';
      else
        cout << d[a][b] << '\n';
    }
  }

  return 0;
}
