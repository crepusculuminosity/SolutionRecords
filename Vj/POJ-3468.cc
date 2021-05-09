#include <cstdio>
#include <cstring>
#include <iostream>
#define lb(x) ((x) & (-x))
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll tr[2][maxn], a[maxn];
int n, q;
void init() {
  for (int i = 1; i <= n; i++) {
    tr[0][i] += a[i], tr[1][i] += i * a[i];
    if (i + lb(i) <= n)
      tr[0][i + lb(i)] += tr[0][i], tr[1][i + lb(i)] += tr[1][i];
  }
}
void update(ll x, ll k) {
  ll u = x * k;
  while (x <= n) {
    tr[0][x] += k, tr[1][x] += u;
    x += lb(x);
  }
}
ll query(ll x) {
  ll r = x, ans = 0;
  while (x) {
    ans += (r + 1) * tr[0][x] - tr[1][x];
    x -= lb(x);
  }
  return ans;
}

int main() {
  // freopen("data.in","r",stdin);
  scanf("%d%d", &n, &q);
  ll now = 0, x;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &x);
    a[i] = x - now;
    now = x;
  }
  init();
  while (q--) {
    char ch[2];
    int l, r;
    scanf("%s%d%d", ch, &l, &r);
    if (ch[0] == 'Q')
      printf("%lld\n", query(r) - query(l - 1));
    else {
      int k;
      scanf("%d", &k);
      update(r + 1, -k);
      update(l, k);
    }
  }
  return 0;
}