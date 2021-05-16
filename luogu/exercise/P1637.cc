#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 3e4 + 10;
int m, n, a[maxn], s[maxn], tr[maxn];
int c[maxn], d[maxn];
inline int discrete(int v) { return lower_bound(s + 1, s + 1 + m, v) - s; }
void update(int x, int k) {
  while (x < maxn) {
    tr[x] += k;
    x += lb(x);
  }
}
int query(int x) {
  int res = 0;
  while (x) {
    res += tr[x];
    x -= lb(x);
  }
  return res;
}
struct point {
  int num, val;
  bool operator<(const point &x) const {
    if (val == x.val)
      return num < x.num;
    return val < x.val;
  }
} q[maxn];
inline int read() {
  int x = 0, f = 1;
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
int main() {
  freopen("data.in", "r", stdin);
  n = read();
  for (int i = 1; i <= n; i++)
    q[i].val = read(), q[i].num = i;
  sort(q + 1, q + 1 + n);
  for (int i = 1; i <= n; i++)
    s[q[i].num] = i;
  for (int i = 1; i <= n; i++) {
    c[i] = query(s[i]);
    update(s[i], 1);
  }
  memset(tr, 0, sizeof(tr));
  for (int i = n; i >= 1; i--) {
    d[i] = query(s[i]);
    update(s[i], 1);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += c[i] * (n - i - d[i]);
  }
  cout<<ans;
  return 0;
}