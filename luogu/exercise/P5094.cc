#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e4 + 10;
typedef long long ll;
ll tr[2][maxn];
ll n;

struct cow {
  ll v, pos;
  bool operator<(const cow &x) const { return v < x.v; }
} q[maxn];

inline ll query(int op, ll x) {
  ll res = 0;
  while (x) {
    res += tr[op][x];
    x -= lb(x);
  }
  return res;
}

inline void update(int op, ll x, ll k) {
  while (x <= maxn) {
    tr[op][x] += k;
    x += lb(x);
  }
}

inline ll read() {
  ll x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

int main() {
  freopen("data.in", "r", stdin);
  n = read();
  for (ll i = 1; i <= n; i++)
    q[i].v = read(), q[i].pos = read();
  sort(q + 1, q + 1 + n);
  ll ans = 0, now = 0;
  for (ll i = 1; i <= n; i++) {
    ll n1 = query(0, q[i].pos);
    ll sum = query(1, q[i].pos);

    ans += (n1 * q[i].pos - sum) * q[i].v;
    ans += ((now - sum) - (i - 1 - n1) * q[i].pos) * q[i].v;
    update(0, q[i].pos, 1);
    update(1, q[i].pos, q[i].pos);
    now += q[i].pos;
  }
  printf("%lld", ans);
  return 0;
}