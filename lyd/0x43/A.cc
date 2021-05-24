#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 500000 + 10;
int a[maxn];
struct Tree {
  int l, r, sum, ls, rs, ans;
} t[maxn << 2];
void pushup(int p) {
  t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
  t[p].ls = max(t[p << 1].ls, t[p << 1].sum + t[p << 1 | 1].ls);
  t[p].rs = max(t[p << 1 | 1].rs, t[p << 1 | 1].sum + t[p << 1].ls);
  t[p].ans = max(max(t[p << 1].ans, t[p << 1 | 1].ans),
                 t[p << 1].rs + t[p << 1 | 1].ls);
}
void build(int p, int l, int r) {
  t[p].l = l, t[p].r = r;
  if (l == r) {
    t[p].sum = t[p].ls = t[p].rs = t[p].ans = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
void update(int p, int x, int y) {
  if (t[p].l == t[p].r) {
    t[p].sum = t[p].ls = t[p].rs = t[p].ans = y;
    return;
  }
  int mid = t[p].l + t[p].r >> 1;
  if (x <= mid)
    update(p << 1, x, y);
  else
    update(p << 1 | 1, x, y);
  pushup(p);
}
Tree query(int p, int l, int r) {
  if (l <= t[p].l && r >= t[p].r) {
    return t[p];
  }
}

int main() {}