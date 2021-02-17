
//模板 单点修改 区域查询

#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 5010;
ll tr[maxn][maxn];
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

inline void update(ll x, ll y, ll k) {
  for (ll i = x; i <= n; i += lb(i)) {
    for (ll j = y; j <= m; j += lb(j)) {
      tr[i][j] += k;
    }
  }
}

inline ll query(ll x, ll y) {
  ll res = 0;

  for (ll i = x; i; i -= lb(i)) {
    for (ll j = y; j; j -= lb(j))
      res += tr[i][j];
  }

  return res;
}

int main() {
  // freopen("data.in","r",stdin);
  n = read(), m = read();
  ll op, a, b, c;

  while (scanf("%lld%lld%lld%lld", &op, &a, &b, &c) == 4) {
    if (op == 1)
      update(a, b, c);

    if (op == 2) {
      ll d = read();
      printf("%lld\n", query(c, d) - query(c, b - 1) - query(a - 1, d) +
                           query(a - 1, b - 1));
    }
  }

  return 0;
}