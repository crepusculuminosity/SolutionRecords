#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll m, n, tr[1000008], r, l, mid, tmp;

inline ll read() {
  ll x = 0;
  int f = 1;
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
  m = read();
  for (int i = 1; i <= n; i++) {
    tr[i] = read();
    r = max(tr[i], r);
  }
  while (l <= r) {
    mid = (r + l) / 2;
    tmp = 0;
    for (int i = 1; i <= n; i++) {
      if (tr[i] > mid)
        tmp += tr[i] - mid;
    }
    if (tmp < m)
      r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%lld\n", l - 1);
  return 0;
}
