#include <bits/stdc++.h>
using namespace std;

struct poi {
  int x, y, xl, yl;
} pos[10005];

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

int n;

int main() {
  int ans = -1;
  n = read();
  for (int i = 1; i <= n; i++) {
    pos[i].x = read(), pos[i].y = read(), pos[i].xl = read(),
    pos[i].yl = read();
  }
  int x = read(), y = read();
  for (int i = n; i >= 1; i--) {
    if (pos[i].x <= x && (pos[i].x + pos[i].xl) >= x && pos[i].y <= y &&
        (pos[i].y + pos[i].yl) >= y) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}