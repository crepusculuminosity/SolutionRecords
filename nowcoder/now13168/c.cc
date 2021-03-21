#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e4 + 10;

struct node {
  char f;
  int a, b, wa, wb;
} q[maxn];

int main() {
  // freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    q[x].a += y, q[x].b += z;
  }
  for (int i = 1; i <= m; i++) {
    if (q[i].a > q[i].b) {
      q[i].f = 'A';
      q[i].wb = q[i].b;
      q[i].wa = q[i].a - (q[i].a + q[i].b >> 1) - 1;
    } else {
      q[i].f = 'B';
      q[i].wa = q[i].a;
      q[i].wb = q[i].b - (q[i].a + q[i].b >> 1) - 1;
    }
  }
  int wa = 0, wb = 0, tot = 0;
  for (int i = 1; i <= m; i++) {
    cout << q[i].f << ' ' << q[i].wa << ' ' << q[i].wb << endl;
    wa += q[i].wa, wb += q[i].wb, tot += q[i].a + q[i].b;
  }
  cout << fixed << setprecision(10) << abs(wa - wb) * 1.0 / tot;

  return 0;
}