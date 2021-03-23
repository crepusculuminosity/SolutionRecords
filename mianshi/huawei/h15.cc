#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int ans = 0;
  cin >> n;
  while (n) {
    ++ans;
    n -= n & -n;
  }
  cout << ans;
  return 0;
}