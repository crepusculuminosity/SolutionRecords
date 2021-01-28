#include <bits/stdc++.h>
using namespace std;

int main() {
  while (1) {
    int a, b;
    cin >> a >> b;
    while (a || b) {
      int x = a, y = b;
      a = x ^ y, b = abs(x - y);
      cout << a << " " << b << endl;
    }
  }
  return 0;
}