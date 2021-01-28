#include <bits/stdc++.h>
using namespace std;

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

inline void write(int n) {
  if (n > 9)
    write(n / 10);
  putchar(n % 10 + '0');
}

int main() {
  int n, a[1005];
  cin >> n;
  double sum = 0;
  for (int i = 0; i < n; i++)
    a[i] = read();
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    write(a[i]);
    printf(" ");
    sum += (n - i) * a[i];
  }
  printf("\n%.2lf\n", sum / n);
  return 0;
}