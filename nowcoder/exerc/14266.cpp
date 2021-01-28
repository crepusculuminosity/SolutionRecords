#include <bits/stdc++.h>
using namespace std;

int n;

struct laptop {
  int m, s;
  bool operator<(const laptop &x) { return m > x.m; }
} q[100005];

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
  n = read();
  for (int i = 1; i <= n; i++) {
    q[i].m = read(), q[i].s = read();
  }
  sort(q + 1, q + 1 + n);
  int mx = q[1].s, ans = 0;

  for (int i = 2; i <= n; i++) {
    if (q[i].s <= mx)
      ans++;
    else
      mx = q[i].s;
  }
  printf("%d\n", ans);
}