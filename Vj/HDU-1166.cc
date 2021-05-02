#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 10;
ll m, n;
ll a[maxn], tr[maxn];
char str[10];
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
    tr[i] += a[i];
    ll j = i + lb(i);
    if (j <= n)
      tr[j] += tr[i];
  }
}

inline void update(ll x, ll k) {
  while (x <= n) {
    tr[x] += k;
    x += lb(x);
  }
}

inline ll query(ll x) {
  ll ans = 0;
  while (x >= 1) {
    ans += tr[x];
    x -= lb(x);
  }
  return ans;
}

int main() {
  // freopen("data.in","r",stdin);
  ll Kase = read();
  for (int kase = 1; kase <= Kase; kase++) {
    printf("Case %d:\n", kase);
    memset(a, 0, sizeof(a));
    memset(tr, 0, sizeof(tr));
    n = read();
    for (int i = 1; i <= n; i++)
      a[i] = read();
    init();
    while (scanf("%s", str) && str[0] != 'E') {
      ll x = read(), y = read();
      if (str[0] == 'Q')
        printf("%lld\n", query(y) - query(x - 1));
      if (str[0] == 'A')
        update(x, y);
      if (str[0] == 'S')
        update(x, -y);
    }
  }
  return 0;
}