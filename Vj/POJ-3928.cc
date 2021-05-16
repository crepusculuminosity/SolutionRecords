#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}
const int maxn = 1e5 + 10;
int n;
int a[maxn];
int c[20010], d[20010];
int tr[maxn];
typedef long long ll;
void update(int x) {
  while (x < maxn) {
    tr[x] += 1;
    x += x & (-x);
  }
}
int query(int x) {
  int res = 0;
  while (x) {
    res += tr[x];
    x -= x & (-x);
  }
  return res;
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int _ = read();
  while (_--) {
    int n = read();
    for (int i = 1; i <= n; i++)
      a[i] = read();
    memset(tr, 0, sizeof(tr));
    for (int i = 1; i <= n; i++) {
      c[i] = query(a[i] - 1);
      update(a[i]);
    }
    memset(tr, 0, sizeof(tr));
    for (int i = n; i >= 1; i--) {
      d[i] = query(a[i] - 1);
      update(a[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += (ll)c[i] * (n - i - d[i]) + (ll)d[i] * (i - 1 - c[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
