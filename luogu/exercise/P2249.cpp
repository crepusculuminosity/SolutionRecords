#include <bits/stdc++.h>
using namespace std;

int a[1000005], m, n;

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

int find(int x) {
  int l = 1, r = n;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (a[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }
  if (a[l] == x)
    return l;
  else
    return -1;
}

inline void write(int x) {
  if (x > 9)
    write(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    a[i] = read();
  // scanf("%d",&a[i]);
  for (int i = 1; i <= m; i++) {
    int q;
    scanf("%d", &q);
    printf("%d ", find(q));
  }
  return 0;
}
