#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1010;
const double eps = 1e-6;
struct node {
  double l, r;
  bool operator<(const node &x) const { return l < x.l; }
} q[maxn];
int n, d;

int main() {
   freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // freopen("data.out", "w", stdout);
  int kse = 1;
  while (cin >> n >> d && n) {
    bool f = 1;
    for (int i = 1; i <= n; i++) {
      int x, y;
      cin >> x >> y;
      if (y > d)
        f = 0;
      q[i].l = x - sqrt(d * d - y * y), q[i].r = x + sqrt(d * d - y * y);
    }
    cout << "Case " << kse++ << ": ";
    if (!f) {
      cout << "-1\n";
      continue;
    }
    sort(q + 1, q + 1 + n);
    double x = q[1].r;
    int now = 1, ans = 1;
    for (int i = 2; i <= n; i++) {
      if (q[i].l > x)
        ++ans, x = q[i].r;
      else if (q[i].l < x)
        x = q[i].r;
    }
    cout << ans << '\n';
  }
  return 0;
}