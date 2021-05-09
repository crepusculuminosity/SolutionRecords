#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 4010;
int a[maxn], b[maxn], c[maxn], d[maxn];
int tmp[maxn * maxn];
int n;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x * f;
}
int main() {
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  // scanf("%d", &n);
  int _ = read();
  while (_--) {
    n = read();
    for (int i = 0; i < n; i++)
      // scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
      a[i] = read(), b[i] = read(), c[i] = read(), d[i] = read();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        tmp[i * n + j] = c[i] + d[j];
    sort(tmp, tmp + n * n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        int tg = -(a[i] + b[j]);
        ans += upper_bound(tmp, tmp + n * n, tg) -
               lower_bound(tmp, tmp + n * n, tg);
      }
    printf("%lld\n", ans);
    if (_)
      puts("");
  }
  return 0;
}