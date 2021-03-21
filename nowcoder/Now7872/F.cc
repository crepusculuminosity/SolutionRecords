#include <bits/stdc++.h>
using namespace std;

inline __int128 read() {
  __int128 x = 0, f = 1;
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

inline void write(__int128 x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9)
    write(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    __int128 ans = 1;
    __int128 b = read(), m = read();
    while (m > 0) {
      if (m % 2 == 1)
        ans = ans * b % 9999999967;
      b = b * b % 9999999967;
      m = m >> 1;
    }
    write(ans % 9999999967);
    printf("\n");
  }
  return 0;
}