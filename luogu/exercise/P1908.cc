#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 5e5 + 10;
ll tr[maxn], ran[maxn], n;
ll ans;

inline ll read() {
  ll x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-')
      f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

struct point {
  ll num, val;
  bool operator<(const point &x) const {
    if (val == x.val)
      return num < x.num;
    return val < x.val;
  }
} q[maxn];

inline void update(ll x, ll k) {
  while (x <= n) {
    tr[x] += k;
    x += lb(x);
  }
}

inline ll query(ll x) {
  ll res = 0;
  while (x >= 1) {
    res += tr[x];
    x -= lb(x);
  }
  return res;
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++)
    q[i].val = read(), q[i].num = i;
  sort(q + 1, q + 1 + n);
  for (int i = 1; i <= n; i++)
    ran[q[i].num] = i;
  for (int i = 1; i <= n; i++) {
    update(ran[i], 1);
    ans += i - query(ran[i]);
  }
  printf("%lld", ans);
  return 0;
}