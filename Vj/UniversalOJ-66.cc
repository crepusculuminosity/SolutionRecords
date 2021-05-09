#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    int x = n;
    while (x) {
      --n;
      x -= x & -x;
    }
    cout << n << '\n';
  }
  return 0;
}