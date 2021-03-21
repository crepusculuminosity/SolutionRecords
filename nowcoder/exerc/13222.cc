#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int a[MAXN], b[MAXN];
int m, n;
int ans = 2e9;

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

inline void out(int x) {
  if (x > 9)
    out(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  m = read();
  for (int i = 1; i <= m; i++)
    b[i] = read();
  for (int i = 1; i <= m - n + 1; i++) {
    int res = 0;
    for (int j = i; j <= i + n - 1; j++) {
      res += (a[j - i + 1] - b[j]) * (a[j - i + 1] - b[j]);
    }
    ans = min(ans, res);
  }
  out(ans);
  return 0;
}