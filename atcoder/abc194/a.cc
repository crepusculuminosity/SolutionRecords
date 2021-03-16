#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("data.in", "r", stdin);
  int a, b;
  while (cin >> a >> b) {
    a += b;
    if (a >= 15 && b >= 8)
      cout << 1;
    else if (a >= 10 && b >= 3)
      cout << 2;
    else if (a >= 3)
      cout << 3;
    else
      cout << 4;
    cout << endl;
  }
  return 0;
}