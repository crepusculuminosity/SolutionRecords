#include <bits/stdc++.h>
#define lb(x) ((x) & (-x))
using namespace std;

using ll = long long;
constexpr ll maxn = 500000 + 10;
ll a[maxn], tr[maxn];
struct tree {
  ll l, r;
  ll g;
} t[maxn << 2];
ll n, m;
void pushup(ll p) { t[p].g = __gcd(t[p << 1].g, t[p << 1 | 1].g); }
inline void build(ll p, ll l, ll r) {
  t[p].l = l, t[p].r = r;
  if (l == r) {
    t[p].g = a[l];
    return;
  }
  ll mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
inline void update(ll p, ll x, ll v) {
  if (t[p].l == t[p].r) {
    t[p].g += v;
    return;
  }
  ll mid = t[p].l + t[p].r >> 1;
  if (x <= mid)
    update(p << 1, x, v);
  else
    update(p << 1 | 1, x, v);
  pushup(p);
}
inline ll query(ll p, ll l, ll r) {
  if (l <= t[p].l && r >= t[p].r)
    return t[p].g;
  ll mid = t[p].l + t[p].r >> 1;
  ll g = 0;
  if (r <= mid)
    g = __gcd(g, query(p << 1, l, mid));
  else if (l > mid)
    g = __gcd(g, query(p << 1 | 1, mid + 1, r));
  return g;
}
void init() {
  for (ll i = 1; i <= n; i++) {
    tr[i] += a[i];
    ll j = i + lb(i);
    if (j <= n)
      tr[j] += tr[i];
  }
}
void add(ll x, ll v) {
  while (x <= n) {
    tr[x] += v;
    x += lb(x);
  }
}
ll getv(ll x) {
  ll res = 0;
  while (x) {
    res += tr[x];
    x -= lb(x);
  }
  return res;
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> m;
  ll now = 0;
  for (ll i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    a[i] = x - now;
    now = x;
  }
  init();
  build(1, 1, n);
  while (m--) {
    char ch;
    ll a, b;
    cin >> ch >> a >> b;
    if (ch == 'Q') {
      cout << __gcd(getv(a), query(1, a + 1, b)) << '\n';
    } else {
      ll c;
      cin >> c;
      update(1, a, c);
      update(1, b + 1, -c);
      add(a, c);
      add(b + 1, -c);
    }
  }
  return 0;
}