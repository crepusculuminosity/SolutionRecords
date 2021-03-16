#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
  int x = 0, y = n;
  while (n) {
    x = x * 10 + (n % 10);
    n /= 10;
  }
  return x == y;
}
int main() {
  int _;
  cin >> _;
  while (_--) {
    int c;
    cin >> c;
    int t = (c + 4) / 5;
    while (!check(c + t))
      t++;
    cout << "Input cost: " << c << endl << t << ' ' << c + t << endl;
    cout << endl;
  }
  return 0;
}