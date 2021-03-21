#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

double a[MAXN];
int n, m, p;

inline int read() {
  int x = 0, f = 1; //
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

int main() {
  n = read(), m = read(), p = read();
  int x, y;
  for (int i = 1; i <= n; i++) {
    x = read(), y = read();
    a[i] = x * 0.85 + y * 0.15;
  }
  sort(a + 1, a + 1 + n, greater<double>());

  int ans = max(0, (int)ceil((a[m] - p * 0.15) / 0.85));
  printf("%d\n", ans);
  return 0;
}