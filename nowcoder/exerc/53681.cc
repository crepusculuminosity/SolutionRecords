#include <bits/stdc++.h>
using namespace std;

bool f = 1;

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

struct stone {
  int a, b;
  bool operator<(const stone &x) const {
    if (b >= a && x.b >= x.a)
      return a < x.a;
    if (b >= a)
      return 1;
    if (x.b > x.a)
      return 0;
    return b > x.b;
  }
} q[500005];

int main() {
  int t = read();
  while (t--) {
    int n = read(), m = read();
    for (int i = 1; i <= n; i++) {
      q[i].a = read();
      q[i].b = read();
    }
    sort(q + 1, q + 1 + n);
    for (int i = 1; i <= n; i++) {
      if (m < q[i].a) {
        f = 0;
        break;
      }
      m += (q[i].b - q[i].a);
    }
    if (f)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}