#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    int ans = 0;
    while (n) {
      ++ans;
      n -= n & -n;
    }
    cout << ans << endl;
  }
  return 0;
}