#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 200000 + 10;
int n, m;
struct Tree {
  int l, r, maxv;
} t[maxn << 2];
int a[maxn];
void pushup(int p) { t[p].maxv = max(t[p << 1].maxv, t[p << 1 | 1].maxv); }
void build(int p, int l, int r) {
  t[p].l = l, t[p].r = r;
  if (l == r) {
    t[p].maxv = a[l];
    return;
  }
  int mid = l + r >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
void update(int p, int x, int v) {
  if (t[p].l == t[p].r) {
    t[p].maxv = v;
    return;
  }
  int mid = t[p].l + t[p].r >> 1;
  if (x <= mid)
    update(p << 1, x, v);
  else
    update(p << 1 | 1, x, v);
  pushup(p);
}

int query(int p, int l, int r) {
  if (l <= t[p].l && r >= t[p].r)
    return t[p].maxv;
  int mid = t[p].l + t[p].r >> 1;
  int val = -0x3f3f3f3f;
  if (l <= mid)
    val = max(val, query(p << 1, l, r));
  if (r > mid)
    val = max(val, query(p << 1 | 1, l, r));
  return val;
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> n >> m) {
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    build(1, 1, n);
    char ch[10];
    int a, b;
    for (int i = 1; i <= m; i++) {
      cin >> ch >> a >> b;
      if (ch[0] == 'Q')
        cout << query(1, a, b) << '\n';
      else
        update(1, a, b);
    }
  }
  return 0;
}