#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 50000 + 10;
int a[maxn], st[maxn][20][2];

inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = x * 10 + ch - 48, ch = getchar();
  return x;
}
inline void pre() {
  a[1] = 0, a[2] = 1;
  for (int i = 3; i < maxn; i++)
    a[i] = a[i / 2] + 1;
}
int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  pre();
  int n = read(), q = read();
  for (int i = 1; i <= n; i++)
    st[i][0][0] = read(), st[i][0][1] = st[i][0][0];
  for (int j = 1; j <= 19; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      st[i][j][0] = max(st[i][j - 1][0], st[i + (1 << j - 1)][j - 1][0]);
      st[i][j][1] = min(st[i][j - 1][1], st[i + (1 << j - 1)][j - 1][1]);
    }

  while (q--) {
    int l = read(), r = read();
    int k = a[r- l + 1];
    int maxx = max(st[l][k][0], st[r - (1 << k) + 1][k][0]);
    int minn = min(st[l][k][1], st[r - (1 << k) + 1][k][1]);
    printf("%d\n", maxx - minn);
  }
  return 0;
}