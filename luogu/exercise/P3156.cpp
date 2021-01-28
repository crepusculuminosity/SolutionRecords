#include <bits/stdc++.h>
using namespace std;

int a[2000005];

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

inline void write(int x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9)
    write(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  int n, m;
  n = read();
  m = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  for (int i = 1; i <= m; i++)
    write(a[read()]), puts(" ");
  return 0;
}