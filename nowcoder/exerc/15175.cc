#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5 + 10;
typedef long long ll;
ll a[MAXN], tr1[MAXN], tr2[MAXN];
int n, q;

inline void init() {
  for (int i = 1; i <= n; i++) {
    tr1[i] += a[i], tr2[i] += i * a[i];
    if (i + lb(i) <= n)
      tr1[i + lb(i)] += tr1[i], tr2[i + lb(i)] += tr2[i];
  }
}

inline void add(ll x, ll k) {
  ll v = x * k;
  while (x <= n) {
    tr1[x] += k, tr2[x] += v;
    x += lb(x);
  }
}

inline ll getsum(ll x) {
  ll r = x, ans = 0;
  while (x) {
    ans += (r + 1) * tr1[x] - tr2[x];
    x -= lb(x);
  }
  return ans;
}

inline ll query(ll l, ll r) { return getsum(r) - getsum(l - 1); }

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
  // freopen("data.in","r",stdin);
  n = read(), q = read();
  ll now = 0;
  for (int i = 1; i <= n; i++) {
    ll x = read();
    add(i, x - now);
    // a[i]=x-now;
    now = x;
  }
  // init();
  while (q--) {
    char ch = getchar();
    ll a = read(), b = read();
    if (ch == 'Q')
      printf("%lld\n", query(a, b));
    if (ch == 'C') {
      ll x = read();
      add(a, x);
      add(b + 1, -x);
    }
  }
  return 0;
}