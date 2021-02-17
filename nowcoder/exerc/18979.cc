#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
typedef long long ll;

ll tr[maxn], a[maxn];
ll n, q;

inline ll read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  return x * f;
}

inline void init() {
  for (ll i = 1; i <= n; i++) {
    tr[i] += a[i];
    if (i + lb(i) <= n)
      tr[i + lb(i)] += a[i];
  }
}

inline ll getsum(ll x) {
  ll res = 0;
  while (x) {
    res += tr[x];
    x -= lb(x);
  }
  return res;
}

inline ll query(ll l, ll r) { return getsum(r) - getsum(l - 1); }