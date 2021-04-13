#include <bits/stdc++.h>
using namespace std;
int n, m;
bool a[15][10010];

void conv(int S) {
  for (int i = 0; i <= 10; i++) {
    if ((1 << i) & S) {
      for (int j = 0; j < m; j++)
        a[i][j] ^= 1;
    }
  }
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (cin >> n >> m && n) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> a[i][j];
    int res = 0;
    for (int S = 0; S < (1 << n + 1); S++) {
      int ans = 0;
      conv(S);
      for (int j = 0; j < m; j++) {
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
          if (a[i][j] == 0)
            ++x;
          if (a[i][j] == 1)
            ++y;
        }
        ans += max(x, y);
      }
      conv(S); //记得把原数组翻回去
      res = max(ans, res);
    }
    cout << res << '\n';
  }
  return 0;
}