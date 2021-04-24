#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int _;
  cin >> _;
  while (_--) {
    int a, b;
    cin >> a >> b;
    cout << max(a, b) + a + b << endl;
  }
  return 0;
}