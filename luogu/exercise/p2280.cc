#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e3 + 10;

int a[maxn][maxn];

inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

int main() {
  // freopen("data.in", "r", stdin);
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read(), v = read();
    a[x + 1][y + 1] = v;
  }
  for (int i = 1; i < maxn; i++) {
    for (int j = 1; j < maxn; j++) {
      a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
    }
  }
  int ans = 0;
  for (int i = m; i < maxn; i++) {
    for (int j = m; j < maxn; j++) {
      ans = max(ans, a[i][j] - a[i - m][j] - a[i][j - m] + a[i - m][j - m]);
    }
  }
  printf("%d", ans);
  return 0;
}