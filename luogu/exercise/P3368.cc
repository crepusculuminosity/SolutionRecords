#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 10;
ll a[MAXN], b[MAXN];
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
inline ll lowbit(ll x) { return x & (-x); }

inline void init() {
  for (ll i = 1; i <= n; i++) {
    b[i] += a[i];
    ll j = i + lowbit(i);
    if (j <= n)
      b[j] += b[i];
  }
}

inline void add(ll x, ll k) {
  while (x <= n) {
    b[x] += k;
    x += lowbit(x);
  }
}

inline ll query(ll x) {
  ll ans = 0;
  while (x >= 1) {
    ans += b[x];
    x -= lowbit(x);
  }
  return ans;
}

int main() {
  // freopen("data.in","r",stdin);
  n = read(), m = read();
  int now = 0;
  for (int i = 1; i <= n; i++) {
    int x = read();
    a[i] = x - now;
    now = x;
  }
  init();
  for (int i = 1; i <= m; i++) {
    int op = read();
    if (op == 1) {
      int x = read(), y = read(), k = read();
      add(x, k);
      add(y + 1, k);
    }
  }
  return 0;
}