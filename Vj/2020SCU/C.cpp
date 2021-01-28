#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[200005];

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
  n = read(), k = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  sort(a + 1, a + n + 1);
  if (a[k] == a[k + 1])
    printf("-1\n");
  else
    printf("%d\n", a[k]);
  return 0;
}