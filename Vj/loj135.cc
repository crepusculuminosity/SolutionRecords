#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 2500;
ll tr[4][maxn][maxn];
ll n, m;

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
    for (ll j = b; j <= m; j += lb(j)) {
      tr[0][i][j] += k;
      tr[1][i][j] += a * k;
      tr[2][i][j] += b * k;
      tr[3][i][j] += a * b * k;
    }
  }
}

inline ll getsum(ll x, ll y) {
  ll res = 0;

  for (ll i = x; i; i -= lb(i)) {
    for (ll j = y; j; j -= lb(j)) {
      res += (x + 1) * (y + 1) * tr[0][i][j] - (y + 1) * tr[1][i][j] -
             (x + 1) * tr[2][i][j] + tr[3][i][j];
    }
  }
  return res;
}

inline ll query(ll a, ll b, ll c, ll d) {
  return getsum(c, d) - getsum(a - 1, d) - getsum(c, b - 1) +
         getsum(a - 1, b - 1);
}

int main() {
  // freopen("data.in","r",stdin);
  n = read(), m = read();
  char op = getchar();
  while (op != EOF) {
    ll a = read(), b = read(), c = read(), d = read();
    if (op == '1') {
      ll k = read();
      update(a, b, k);
      update(c + 1, b, -k);
      update(a, d + 1, -k);
      update(c + 1, d + 1, k);
    } else
      printf("%lld\n", query(a, b, c, d));
    op = getchar();
  }
  return 0;
}