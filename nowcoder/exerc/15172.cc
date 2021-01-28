#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int sum[1005][1005], a[1005][1005];

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

inline void update(int x, int y, int k) {
  for (int i = x; i <= n; i += lb(i)) {
    for (int j = y; j <= n; j += lb(j))
      sum[i][j] += k;
  }
}

inline int getsum(int x, int y) {
  int ans = 0;
  for (int i = x; i > 0; i -= lb(i)) {
    for (int j = y; j > 0; j -= lb(j))
      ans += sum[i][j];
  }
  return ans;
}

int main() {
  // freopen("data.in","r",stdin);
  n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = read();
      if (a[i][j])
        update(i, j, 1);
    }
  }
  while (m--) {
    int op = read(), x = read(), y = read();
    if (op == 1) {
      if (a[x][y])
        update(x, y, -1), a[x][y] = 0;
      else
        update(x, y, 1), a[x][y] = 1;
    }
    if (op == 2) {
      int a = read(), b = read();
      printf("%d\n", getsum(a, b) - getsum(x - 1, b) - getsum(a, y - 1) +
                         getsum(x - 1, y - 1));
    }
  }
  return 0;
}