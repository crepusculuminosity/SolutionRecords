#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[550][5];

inline void init() {
  a[3][0] = 1, a[3][1] = a[3][2] = 3, a[3][3] = 1;
  for (int i = 4; i <= 502; i++)
    for (int j = 0; j <= 4; j++) {
      a[i][j] = a[i - 1][j];
      if (j)
        a[i][j] += a[i - 1][j - 1];
    }
}

int main() {
  // freopen("data.in", "r", stdin);
  init();
  int n, kse = 1;
  while (~scanf("%d", &n) && n) {
    if (n < 3 || n & 1)
      printf("Case %d: 0\n", kse++);
    else {
      int x = n / 2 + 2;
      printf("Case %d: %lld\n", kse++, a[x][4] + a[x - 1][4]);
    }
  }
  return 0;
}