#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll a[maxn];
int n, q;
struct tree {
  int l, r;
  ll sum, add;
} t[maxn << 2];

inline void build(int p, int l, int r) {
  t[p].l = l, t[p].r = r, t[p].add = 0;
  if (l == r) {
    t[p].sum = a[l];
    return;
  }
  int mid = l + r >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}
void pushdown(int p) {
  if (t[p].add) {
    t[p << 1].sum += t[p].add * (t[p << 1].r - t[p << 1].l + 1);
    t[p << 1 | 1].sum += t[p].add * (t[p << 1 | 1].r - t[p << 1 | 1].l + 1);
    t[p << 1].add += t[p].add;
    t[p << 1 | 1].add += t[p].add;
    t[p].add = 0;
  }
}
inline void update(int p, int l, int r, int v) {
  if (l <= t[p].l && r >= t[p].r) {
    t[p].sum += (ll)v * (t[p].r - t[p].l + 1);
    t[p].add += v;
    return;
  }
  pushdown(p);
  int mid = t[p].l + t[p].r >> 1;
  if (l <= mid)
    update(p << 1, l, r, v);
  if (r > mid)
    update(p << 1 | 1, l, r, v);
  t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}
int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
}