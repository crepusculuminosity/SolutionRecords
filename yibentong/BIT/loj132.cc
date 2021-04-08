
//模板 区间修改 区间查询

#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
ll m, n;
ll a[maxn], tr1[maxn], tr2[maxn];

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

inline void init() {
  for (ll i = 1; i <= n; i++) {
    tr1[i] += a[i], tr2[i] += i * a[i];

    if (i + lb(i) <= n)
      tr1[i + lb(i)] += tr1[i], tr2[i + lb(i)] += tr2[i];
  }
}

inline void update(ll x, ll k) {
  ll v = x * k;

  while (x <= n) {
    tr1[x] += k, tr2[x] += v;
    x += lb(x);
  }
}

ll query(ll x) {
  ll r = x, ans = 0;

  while (x > 0) {
    ans += (r + 1) * tr1[x] - tr2[x];
    x -= lb(x);
  }

  return ans;
}

int main() {
  // freopen("data.in","r",stdin);
  n = read(), m = read();
  ll now = 0;

  for (ll i = 1; i <= n; i++) {
    ll x = read();
    a[i] = x - now;
    now = x;
    /* ll x=read();
 update(i,x-now);
 now=x;*/
  }

  init();

  // for(int i=1;i<=n;i++) printf("%lld ",tr2[i]);
  // puts("");
  while (m--) {
    ll op = read(), l = read(), r = read();

    if (op == 1) {
      ll x = read();
      update(l, x);
      update(r + 1, -x);
    } else
      printf("%lld\n", query(r) - query(l - 1));
  }

  return 0;
}