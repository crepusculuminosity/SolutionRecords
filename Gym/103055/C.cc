#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x, y, z;
} q[9];

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int _;
  cin >> _;
  while (_--) {
    for (int i = 1; i <= 8; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      q[i] = Point{a, b, c};
    }
    set<int> s;
    for (int i = 1; i <= 8; i++) {
      for (int j = i + 1; j <= 8; j++) {
        int d = (q[i].x - q[j].x) * (q[i].x - q[j].x) +
                (q[i].y - q[j].y) * (q[i].y - q[j].y) +
                (q[i].z - q[j].z) * (q[i].z - q[j].z);
        s.insert(d);
      }
    }
    bool f = 0;
    if (s.size() == 3) {
      int a[3], cnt = 0;
      for (auto it = s.begin(); it != s.end(); it++)
        a[cnt++] = *it;
      if (a[1] == 2 * a[0] && a[2] == 3 * a[0])
        f = 1;
    }
    if (f)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}