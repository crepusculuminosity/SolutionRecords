#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll maxn = 1010;
ll n;
ll h, r;

struct node {
  ll x, y, z;
} q[maxn];

ll fa[maxn];
ll f1[maxn], f2[maxn], rnk[maxn];
void init() {
  for (ll i = 1; i <= n; i++)
    fa[i] = i, rnk[i] = 0;
  memset(f1, 0, sizeof(f1));
  memset(f2, 0, sizeof(f2));
}

ll find(ll x) {
  if (fa[x] == x)
    return x;
  return fa[x] = find(fa[x]);
}

void merge(ll x, ll y) {
  x = find(x);
  y = find(y);
  if (rnk[x] > rnk[y])
    fa[y] = x;
  else {
    fa[x] = y;
    if (rnk[x] == rnk[y])
      ++rnk[y];
  }
}

ull dis(const node &a, const node &b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
         (a.z - b.z) * (a.z - b.z);
} // UOJ 上最后一个点会爆long long

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int _;
  scanf("%d", &_);
  while (_--) {

    scanf("%lld%lld%lld", &n, &h, &r);
    init();
    ll tot1 = 0, tot2 = 0;
    for (ll i = 1; i <= n; i++) {
      scanf("%lld%lld%lld", &q[i].x, &q[i].y, &q[i].z);
      if (q[i].z + r >= h)
        ++tot1, f1[tot1] = i;
      if (q[i].z - r <= 0)
        ++tot2, f2[tot2] = i;

      for (ll j = 1; j < i; j++) {
        if (dis(q[i], q[j]) > (ull)4 * r * r)
          continue;
        ll a1 = find(i), a2 = find(j);
        if (a1 != a2)
          merge(a1, a2);
      }
    }
    int f = 0;
    for (ll i = 1; i <= tot1; i++) {
      for (ll j = 1; j <= tot2; j++) {
        if (find(f1[i]) == find(f2[j])) {
          f = 1;
          break;
        }
      }
      if (f == 1)
        break;
    }

    if (f)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}