#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fun(ll n) {
  ll ans = 1;
  for (ll i = 2; i * i <= n; i++) {
    int c = 0;
    if (n % i == 0) {
      c = 1;
      n /= i;
      while (n % i == 0) {
        c++;
        n /= i;
      }
    }
    if (c)
      ans *= (c + 1);
  }
  if (n != 1)
    ans *= 2;
  if (ans == 1 && n == 1)
    ans = 1;
  return ans;
}

inline ll read() {
  ll x = 0, f = 1; //
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
  // freopen("data.in","r",stdin);
  ll _ = read();
  while (_--) {
    ll a = read(), b = read();
    ll ans = fun(a * b);
    printf("%lld\n", ans);
  }

  return 0;
}