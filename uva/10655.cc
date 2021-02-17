#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, p, q;

ll fun(ll n, ll p, ll q) {
  if (n == 1)
    return p;
  if (n == 0)
    return 2;
  else
    return p * fun(n - 1, p, q) - q * fun(n - 2, p, q);
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
  // freopen("data.in", "r", stdin);
  while (1) {
    p = read(), q = read();
    if (!p && !q)
      break;
    n = read();
    printf("%lld\n", fun(n, p, q));
  }
  return 0;
}
