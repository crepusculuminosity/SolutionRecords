#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 50000 + 10;
int a[maxn];
struct tree {
  int l, r, sum;
} t[maxn << 2];
inline void pushup(int p) { t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum; }
inline void build(int p, int l, int r) {
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
inline void update(int p, int x, int v) {
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
inline int query(int p, int l, int r) {
  if (l <= t[p].l && r >= t[p].r)
    return t[p].sum;
  int mid = t[p].l + t[p].r >> 1;
  int ans = 0;
  if (l <= mid)
    ans += query(p << 1, l, r);
  if (r > mid)
    ans += query(p << 1 | 1, l, r);
  return ans;
}

int n, m;
int main() {

  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _, kse = 1;
  cin >> _;
  while (_--) {
    // memset(t,0,sizeof(t));
    cout << "Case " << kse++ << ":\n";
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    build(1, 1, n);
    char ch[10];
    while (cin >> ch && ch[0] != 'E') {
      int a, b;
      cin >> a >> b;
      if (ch[0] == 'Q')
        cout << query(1, a, b) << '\n';
      if (ch[0] == 'A')
        update(1, a, b);
      if (ch[0] == 'S')
        update(1, a, -b);
    }
  }
  return 0;
}
