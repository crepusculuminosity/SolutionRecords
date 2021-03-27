#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 510, mod = 1e6 + 7;
int c[maxn][maxn];
int m, n, k, x, y, cnt;

void init() {
  c[0][0] = 1;
  for (int i = 1; i <= 500; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  }
}

int main() {
  // freopen("data.in", "r", stdin);
  int T;
  init();
  scanf("%d", &T);
  int kase = 1;
  while (T--) {
    scanf("%d%d%d", &m, &n, &k);
    int ans = 0;
    for (int S = 0; S < (1 << 4); S++) {
      x = n, y = m, cnt = 0;
      if (S & 1)
        ++cnt, --x;
      if (S & 2)
        ++cnt, --x;
      if (S & 4)
        ++cnt, --y;
      if (S & 8)
        ++cnt, --y;
      if (cnt & 1)
        ans = (ans + mod - c[x * y][k]) % mod;
      else
        ans = (ans + c[x * y][k]) % mod;
    }
    printf("Case %d: %d\n", kase++, ans);
  }
  return 0;
}