#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e5 + 10;
typedef long long ll;
ll a[maxn];
struct tree {
  int l, r;
  ll sum;
} t[maxn << 2];
int n, m;
void pushup(int p) { t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum; }
void build(int p, int l, int r) {
  t[p].l = l, t[p].r = r;
  if (l == r) {
    t[p].sum = a[l];
    return;
  }
  int mid = l + r >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
void update(int p, int x, ll v) {
  if (t[p].l == t[p].r) {
    t[p].sum += v;
    return;
  }
  int mid = t[p].l + t[p].r >> 1;
  if (x <= mid)
    update(p << 1, x, v);
  else
    update(p << 1 | 1, x, v);
  pushup(p);
}
ll query(int p, int l, int r) {
  if (l <= t[p].l && r >= t[p].r)
    return t[p].sum;
  ll ans = 0;
  int mid = t[p].l + t[p].r >> 1;
  if (l <= mid)
    ans += query(p << 1, l, r);
  if (r > mid)
    ans += query(p << 1 | 1, l, r);
  return ans;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }

  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x * f;
}
int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  n = read(), m = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int a = read(), b = read(), c = read();
    // cin >> a >> b >> c;
    if (a == 1)
      update(1, b, c);
    else
      printf("%lld\n", query(1, b, c));
  }
  return 0;
}