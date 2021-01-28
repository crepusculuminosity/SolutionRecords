#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 5010;
ll m, n;
ll tr[maxn][maxn];

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

inline void update(ll a, ll b, ll k) {
  for (ll i = a; i <= n; i += lb(i)) {
    for (ll j = b; j <= m; j += lb(j))
      tr[i][j] += k;
  }
}

inline ll query(ll x, ll y) {
  ll res = 0;
  for (ll i = x; i; i -= lb(i))
    for (ll j = y; j; j -= lb(j))
      res += tr[i][j];
  return res;
}

int main() {
  n = read(), m = read();
  ll op, a, b;
  while (scanf("%lld%lld%lld", &op, &a, &b) == 3) {
    if (op == 1) {
      ll c = read(), d = read(), k = read();
      update(a, b, k);
      update(c + 1, d + 1, k);
      update(a, d + 1, -k);
      update(c + 1, b, -k);
    } else
      printf("%lld\n", query(a, b));
  }

  return 0;
}