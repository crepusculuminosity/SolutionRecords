#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  string a, b;

  while (cin >> a >> b) {
    int x = 0, y = 0;
    int f1 = 1, f2 = 1;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == '-') {
        f1 = -1;
        continue;
      }
      if (a[i] == ',')
        continue;
      x = x * 10 + a[i] - 48;
    }
    x *= f1;
    for (int i = 0; i < b.size(); i++) {
      if (b[i] == '-') {
        f2 = -1;
        continue;
      }
      if (b[i] == ',')
        continue;
      y = y * 10 + b[i] - 48;
    }
    y *= f2;
    cout << x + y << endl;
  }
  return 0;
}