#include <bits/stdc++.h>
using namespace std;
int main() {
  int _;
  cin >> _;
  while (_--) {
    int x;
    cin >> x;
    int k = 1;
    while ((1 << k) < x)
      ++k;
    cout << "Input value: " << x << endl;
    cout << (1 << k) << endl << endl;
  }
  return 0;
}