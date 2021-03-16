#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k, h;

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

ll solve(ll x) {
  ll t = (k - x) / h;
  return t * h + x;
}

int main() {
  // freopen("data.in", "r", stdin);
  n = read(), k = read(), h = read();
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll x = read();
    if (h == 0 || x > k)
      ans += x;
    else
      ans += solve(x);
  }
  printf("%lld", ans + h);
  return 0;
}