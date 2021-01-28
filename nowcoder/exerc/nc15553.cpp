#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000005];

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
  int n, k;
  int _;
  _ = read();
  while (_--) {
    n = read();
    k = read();
    for (int i = 1; i <= n; i++) {
      int x = read();
      a[i] = a[i - 1] + x;
    }
    ll ma = -1e18, ans = -1e18;
    for (int i = k; i <= n - k; i++) {
      ma = max(ma, a[i] - a[i - k]);
      ans = max(ans, ma + a[i + k] - a[i]);
    }
    printf("%lld\n", ans);
  }

  return 0;
}