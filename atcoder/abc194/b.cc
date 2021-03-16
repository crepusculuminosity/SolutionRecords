#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e5 + 10;
int a[maxn];
using ll = long long;
inline ll read() {
  ll x = 0, f = 1;
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
  // freopen("data.in", "r", stdin);
  ll n = read();
  ll x = 0, y = 0;
  for (ll i = 1; i <= n; ++i) {
    ll t = read();
    x += t, y += t * t;
  }
  ll ans = n * y - x * x;
  printf("%lld", ans);
  return 0;
}