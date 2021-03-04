#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e4 + 10;
int d[2][maxn][20];
int n, q;

inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

inline void stinit() {
  for (int i = 1; i <= n; i++)
    d[0][i][0] = read(), d[1][i][0] = d[0][i][0];
  for (int j = 1; j <= 19; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      d[0][i][j] = min(d[0][i][j - 1], d[0][i + (1 << (j - 1))][j - 1]);
      d[1][i][j] = max(d[1][i][j - 1], d[1][i + (1 << (j - 1))][j - 1]);
    }
  }
}

inline int query(int l, int r) {
  int k = 0;
  while (1 << (k + 1) <= r - l + 1)
    k++;
  int minx = min(d[0][l][k], d[0][r - (1 << k) + 1][k]);
  int maxx = max(d[1][l][k], d[1][r - (1 << k) + 1][k]);
  return maxx - minx;
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  n = read(), q = read();
  stinit();
  while (q--) {
    int l = read(), r = read();
    printf("%d\n", query(l, r));
  }
  return 0;
}