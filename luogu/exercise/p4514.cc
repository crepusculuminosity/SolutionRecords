#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2500;
int tr[4][maxn][maxn];
int n, m;
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

inline void update(int a, int b, int k) {
  for (int i = a; i <= n; i += lb(i)) {
    for (int j = b; j <= m; j += lb(j)) {
      tr[0][i][j] += k;
      tr[1][i][j] += a * k;
      tr[2][i][j] += b * k;
      tr[3][i][j] += a * b * k;
    }
  }
}

inline int getsum(int x, int y) {
  int res = 0;

  for (int i = x; i; i -= lb(i)) {
    for (int j = y; j; j -= lb(j)) {
      res += (x + 1) * (y + 1) * tr[0][i][j] - (y + 1) * tr[1][i][j] -
             (x + 1) * tr[2][i][j] + tr[3][i][j];
    }
  }
  return res;
}

inline int query(int a, int b, int c, int d) {
  return getsum(c, d) - getsum(a - 1, d) - getsum(c, b - 1) +
         getsum(a - 1, b - 1);
}

int main() {
  // freopen("data.in","r",stdin);
  // n=read(), m=read();
  scanf("X %d %d", &n, &m);
  char op[3];
  while (scanf("%s", op + 1) != EOF) {
    int a = read(), b = read(), c = read(), d = read();
    // int a=_getInt(),b=_getInt(),c=_getInt(),d=_getInt();
    // getchar();
    if (op[1] == 'L') {
      int k = read();
      update(a, b, k);
      update(c + 1, b, -k);
      update(a, d + 1, -k);
      update(c + 1, d + 1, k);
    } else
      printf("%d\n", query(a, b, c, d));
  }
  return 0;
}