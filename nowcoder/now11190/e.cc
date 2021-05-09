#include <bits/stdc++.h>
using namespace std;
int x, y, z, a, l, r;
int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int _;
  cin >> _;
  while (_--) {
    cin >> x >> y >> z >> a >> l >> r;
   // z = 1;
    int ans = 0;
    for (int i = l; i <= r; i++) {
      if ((abs((x * i - a) / z - (y * i - a) / z) ==
           abs((x * i - a - 1) / z - (y * i - a) / z)) &&
          ((abs((x * i - a) / z - (y * i - a) / z) ==
            abs((y * i - a - 1) / z - (x * i - a) / z))))
        ++ans, cout << i << ' ';
    }
    cout << ans << endl;
  }
  return 0;
}