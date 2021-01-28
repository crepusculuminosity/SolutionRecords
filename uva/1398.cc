#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
struct Event {
  double pos;
  int type; //
  bool operator<(const Event &a) const {
    return pos < a.pos || (pos == a.pos && type > a.type);
  }
  /* data */
} q[MAXN << 1];

void update(int x, int dir, int edge, double &l, double &r) {
  if (dir == 0) {
    if (x <= 0 || x >= edge)
      r = l - 1;
  } else if (dir > 0) {
    l = max(l, -(double)x / dir);
    r = min(r, (double)(edge - x) / dir);
  } else if (dir < 0) {
    l = max(l, (double)(edge - x) / dir);
    r = min(r, -(double)x / dir);
  }
}

int main() {
  // freopen("data.in","r",stdin);

  int _;
  scanf("%d", &_);
  while (_--) {
    memset(q, 0, sizeof(q));
    int w, h, n, e = 0;
    scanf("%d%d%d", &w, &h, &n);
    for (int i = 1; i <= n; i++) {
      int x, y, a, b;
      scanf("%d%d%d%d", &x, &y, &a, &b);
      double l = 0, r = 1e9;
      update(x, a, w, l, r);
      update(y, b, h, l, r);
      if (r > l) {
        // e++;
        q[++e] = (Event){l, 0};
        // e++;
        q[++e] = (Event){r, 1};
      }
    }
    sort(q + 1, q + e + 1);
    int cnt = 0, ans = 0;
    for (int i = 1; i <= e; i++) {
      if (q[i].type == 0)
        ans = max(ans, ++cnt);
      else
        cnt--;
    }
    printf("%d\n", ans);
  }
  return 0;
}