#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int a[MAXN];
int l, r, n, m;

inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    // x=x*10+ch-'0';
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}

inline bool check(int x) {
  int tot = 0, num = 0;
  for (int i = 1; i <= n; i++) {
    if (tot + a[i] <= x)
      tot += a[i];
    else
      tot = a[i], num++;
  }
  return num >= m;
}

int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    l = max(a[i], l);
    r += a[i];
  }
  while (l < r) {
    int mid = (r + l) >> 1;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%d\n", l);

  return 0;
}