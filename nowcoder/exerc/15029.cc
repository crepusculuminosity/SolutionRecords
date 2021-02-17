#include <bits/stdc++.h>
using namespace std;

struct t {
  int h, m, s;
  bool operator<(const t &x) const {
    if (h == x.h && m == x.m)
      return s < x.s;
    else if (h == x.h)
      return m < x.m;
    return h < x.h;
  }
} q[5010];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> q[i].h >> q[i].m >> q[i].s;
  sort(q + 1, q + 1 + n);
  for (int i = 1; i <= n; i++)
    cout << q[i].h << " " << q[i].m << " " << q[i].s << endl;
  return 0;
}