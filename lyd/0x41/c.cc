#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 20010;
struct {
  int l, r, ans;
} q[10010];
int n, m, t;
int a[maxn], fa[maxn], d[maxn];
void read() {
  cin >> n >> m;
  char ch[5];
  for (int i = 1; i <= m; i++) {
    cin >> q[i].l >> q[i].r >> ch;
    q[i].ans = (ch[0] == 'o' ? 1 : 0);
    a[++t] = q[i].l - 1, a[++t] = q[i].r;
  }
  sort(a + 1, a + 1 + t);
  n = unique(a + 1, a + 1 + t) - a - 1;
}
int find(int x) {
  if (x == fa[x])
    return x;
  int root = find(fa[x]);
  d[x] ^= d[fa[x]];
  return fa[x] = root;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  read();
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  for (int i = 1; i <= m; i++) {
    int x = lower_bound(a + 1, a + 1 + n, q[i].l - 1) - a;
    int y = lower_bound(a + 1, a + 1 + n, q[i].r) - a;
    int a = find(x), b = find(y);
    if (a == b) {
      if ((d[x] ^ d[y]) != q[i].ans) {
        cout << i - 1 << '\n';
        return 0;
      }
    } else {
      fa[a] = b;
      d[a] = d[x] ^ d[y] ^ q[i].ans;
    }
  }
  cout << m << '\n';
  return 0;
}